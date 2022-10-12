#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;
int x1=0,y1=0,x2=0,y2=0;

void myDisplay(void)
{

glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);
glBegin(GL_LINE_LOOP);
glColor3ub (255,0,0);
glVertex2i(160, 120);
glColor3ub (0,255,0);
glVertex2i(480, 120);
glColor3ub (0,0,255);
glVertex2i(320, 480);
glEnd();
glColor3ub (255,255,0);
glBegin(GL_QUADS);
glVertex2i(200, 150);
glVertex2i(440, 150);
glVertex2i(440, 200);
glVertex2i(200, 200);
glEnd();

glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();



    cout<<"Enter an Initial point: ";
    cin>>x1>>y1;

    cout<<"Enter an Final point: ";
    cin>>x2>>y2;
}
