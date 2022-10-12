#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <cmath>
using namespace std;

float x0=0, y=0; ///Starting Points
float x1=0, yF=0; ///Ending Points

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);

float m;
m= (yF-y)/(x1-x0); ///dy/dx
if(m<1) /// dy<dx
{
    glBegin(GL_POINTS);
    glColor3ub (0,0,0);
    glVertex2i(x0,y);
    glEnd();

    //myDisplay();
    float xi=x0; //initial pixel
    float yi=y; //initial pixel

    for(int n=1;n<=(x1-x0);n++)
    {
        //for next pixel value
        xi=xi+1; //as m<1 so x will be the unit interval
        yi=yi+m;

        float caly=floor(yi+.5); //flooring up the values as we need an integer number
        //myDisplay();
        glBegin(GL_POINTS);
        glColor3ub (0,0,0);
        glVertex2i(xi,yi);
        glEnd();

    }
}
if(m>1) ///dy>dx
{
    glBegin(GL_POINTS);
    glColor3ub (0,0,0);
    glVertex2i(x0,y);
    glEnd();

    //myDisplay();
    float xi=x0; //initial pixel value
    float yi=y; //initial pixel value

    for(int n=1;n<=(x1-x0);n++)
    {
        //for next pixel value
        yi=yi+1; //as m>1 so y will be the unit interval
        xi=xi+(1/m);

        float caly=floor(yi+.5); //flooring up the values as we need an integer number
        //myDisplay();
        glBegin(GL_POINTS);
        glColor3ub (0,0,0);
        glVertex2i(xi,yi);
        glEnd();

    }
}

glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}



int main(int argc, char** argv)
{
    //Taking inputs
    cout<<"Insert initial point: ";
    cin>>x0;
    cin>>y;
    cout<<"Insert Final point: ";
    cin>>x1;
    cin>>yF;
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (150, 250);
glutCreateWindow ("Bresenhum Incremental Algorithm");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();


}
