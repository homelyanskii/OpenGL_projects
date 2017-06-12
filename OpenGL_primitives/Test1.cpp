#include <iostream>
#include <GL/glu.h>
#include <GL/glut.h>

void display();
void timer (int);

using namespace std;

void timer (int = 0){
display();
glutTimerFunc(100, timer, 0);
}

void display(){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glRotatef(1, 1.0, 1.0, 0.0);
glBegin(GL_TRIANGLE_STRIP);

glColor3f(1.0,0.0,0.0);
glVertex3f(-0.5, 0, -0.5);
glVertex3f(0.5, 0, -0.5);
glVertex3f(0, 0.5, 0);

glVertex3f(0.5, 0, 0.5);

glVertex3f(-0.5, 0, -0.5);

glEnd();
glFlush();
glutSwapBuffers();

}

int main(int argc, char **argv)
{
glutInit(&argc, argv);

glutInitWindowSize(400, 400);
glutInitWindowPosition(740, 100);
glutCreateWindow("TEST");

glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glClearColor(0.0, 0.0, 0.0, 0.0);
glEnable(GL_DEPTH_TEST);

/* glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);*/

glutDisplayFunc(display);

glClear(GL_DEPTH_BUFFER_BIT);

timer();
glutMainLoop();

return 0;
}
