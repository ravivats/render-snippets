#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int width = 500, height = 500;
GLdouble point_p = 0.001;
GLdouble triangle_t1[3][2] = {{-0.5, 0}, {0.5, 0}, {0, 0.866}};

void init() {
    glClearColor(0, 0, 0, 1.0);
    glColor3f(0.5, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    point_p = width * height / 1e9;
    gluOrtho2D(-width / 200.0, width / 200.0, -0.1, height / 100.0 - 0.1);
    glMatrixMode(GL_MODELVIEW);
}

void reshape_func(int w, int h) {
    width = w;
    height = h;
    init();
    glutPostRedisplay();
}

void draw_quadilateral(GLdouble p[2]) {
    glRectd(p[0] - point_p, p[1] - point_p, p[0] + point_p, p[1] + point_p);
    /* glBegin(GL_QUADS);
         glVertex2d(p[0] + point_p, p[1] + point_p);glVertex2d(p[0] - point_p, p[1] + point_p);
         glVertex2d(p[0] - point_p, p[1] - point_p);glVertex2d(p[0] + point_p, p[1] - point_p);
    glEnd(); */
}

void display_func() {
    glClear(GL_COLOR_BUFFER_BIT);
    GLdouble p[2] = {0.5 * width / 200.0, 0.5 * height / 200.0};
    int v;
    for (int i = -1; ++i < 10000;) {
        draw_quadilateral(p);
        v = rand() % 3;
        p[0] = (p[0] + triangle_t1[v][0] * width / 200.0) / 2;
        p[1] = (p[1] + triangle_t1[v][1] * height / 200.0) / 2;
    }
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    srand(time(NULL));
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(display_func);
    glutReshapeFunc(reshape_func);
    init();
    glutMainLoop();
    return 0;
}
