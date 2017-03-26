/*
 *  double_buffer.c
 *  This program shows double buffering for animation with no_flicker. The left and middle mouse_func
 *  buttons start and stop the spinning motion of the square.
 */

#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>

#define DEGREES_TO_RADIANS 3.14159/180.0

static GLfloat spin = 0.0;
GLfloat x, y;
int singleBuffer, doubleBuffer;

void draw_square()
{
    glBegin(GL_QUADS);
	   glVertex2f(x,y);
	   glVertex2f(-y,x);
       glVertex2f(-x,-y);
	   glVertex2f(y,-x);
	glEnd();
}


void display_new()
{
    glClear (GL_COLOR_BUFFER_BIT);

    draw_square();

    glutSwapBuffers ();
}

void display_func()
{
    glClear (GL_COLOR_BUFFER_BIT);

    draw_square();

    glFlush();
}

void idle_spin (void)
{
    spin = spin + 2.0;
    if (spin > 360.0) spin = spin - 360.0;
	x= 25.0*cos(DEGREES_TO_RADIANS * spin);
    y= 25.0*sin(DEGREES_TO_RADIANS * spin);
	glutSetWindow(singleBuffer);
    glutPostRedisplay(); 
	glutSetWindow(doubleBuffer);
    glutPostRedisplay();
}

void myinit ()
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f (1.0, 1.0, 1.0);
    glShadeModel (GL_FLAT);
}

void mouse_func(int btn, int state, int x, int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  glutIdleFunc(idle_spin);
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)   glutIdleFunc(NULL);
}

void reshape_func(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) 
	glOrtho (-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w, 
	    50.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);
    else 
	glOrtho (-50.0*(GLfloat)w/(GLfloat)h, 
	    50.0*(GLfloat)w/(GLfloat)h, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();

}

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, and handle input events.
 */
int main(int argc, char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	singleBuffer=glutCreateWindow("single buffered");
    myinit ();
	glutDisplayFunc(display_func); 
    glutReshapeFunc (reshape_func);
    glutIdleFunc (idle_spin);
    glutMouseFunc (mouse_func);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowPosition(500,0);
	doubleBuffer=glutCreateWindow("double buffered");
    myinit ();
	glutDisplayFunc(display_new);
    glutReshapeFunc (reshape_func);
    glutIdleFunc (idle_spin);
    glutMouseFunc (mouse_func);

	glutMainLoop();

}

