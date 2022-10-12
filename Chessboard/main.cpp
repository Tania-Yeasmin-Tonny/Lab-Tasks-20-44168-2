#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

//glPointSize(5.0);

/*glBegin(GL_LINE_LOOP);
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
glVertex2i(200, 200);*/

bool color = false ;

for(int i=0; i<=800 ; i+=100)
{
        for(int j=0; j<=800; j+=100)
        {
            if(color)
            {
                glColor3ub (0,0,0);
                color=false;

            }
            else
            {
                glColor3ub (255,255,255);
                color=true;
            }

            glBegin(GL_QUADS);
            glVertex2i(i,j);
            glVertex2i(i+100, j);
            glVertex2i(i+100, j+100);
            glVertex2i(i, j+100);

        }
}


glEnd();

glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800, 800);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Chess Board");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
