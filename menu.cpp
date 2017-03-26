#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int flag=0;
float size=0.2;
void mydisplay()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glFlush();
}

void init()
{
    glClearColor(0.0,0.0,0.0,1);
    glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

void demo_menu(int id)
{
switch(id)
{
  case 1: exit(0);
      break;

    
}
}

void edit_menu(int id)
{
    switch(id)
    {
        case 1:
      printf("Bar graph\n");
      break;
  case 2:
      printf("Line Graph\n");
      break;
  case 3:
      printf("Pie Chart\n");
      break;
    }
}


void size_menu(int id)
{
switch(id){
case 2: printf("normal");break;
case 3: printf("print");break;
case 4:printf("web");break;
}
}

void myReshape(int w, int h)
{

/* adjust clipping box */
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
    glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,  2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
else
glOrtho(-2.0*(GLfloat)w/(GLfloat)h, 2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
int sub_menu1, sub_menu2;
glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
      glutInitWindowSize(500,500);
      glutInitWindowPosition(20,20);
      glutCreateWindow("menu");

/*sub_menu1=glutCreateMenu(size_menu);
glutAddMenuEntry("normal",2);
glutAddMenuEntry("print",3);
glutAddMenuEntry("web",4);
*/
sub_menu2=glutCreateMenu(edit_menu);
glutAddMenuEntry("Bar Graph",1);
glutAddMenuEntry("Line Graph",2);
glutAddMenuEntry("Pie Chart",3);


glutCreateMenu(demo_menu);
glutAddSubMenu("Graphs",sub_menu2);
glutAddMenuEntry("Quit",1);

/*glutAddSubMenu("view",sub_menu1);
glutAddSubMenu("edit",sub_menu2);
*/
glutAttachMenu(GLUT_RIGHT_BUTTON);

glutDisplayFunc(mydisplay);
init();
glutReshapeFunc(myReshape);
glutMainLoop();
}
