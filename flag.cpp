#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.14159
#define no_points 500

void drawFlag(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.54,0.0);
    glVertex2d(-0.7,0.6);
    glVertex2d(0.7,0.6);
    glVertex2d(0.7,0.2);
    glVertex2d(-0.7,0.2);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2d(-0.7,0.2);
    glVertex2d(0.7,0.2);
    glVertex2d(0.7,-0.2);
    glVertex2d(-0.7,-0.2);
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.8,0.0);
    glVertex2d(-0.7,-0.2);
    glVertex2d(0.7,-0.2);
    glVertex2d(0.7,-0.6);
    glVertex2d(-0.7,-0.6);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glLineWidth(3.0);
    glColor3f(0.0,0.0,1.0);
    for(int i =0; i< no_points;i++) {
        double angle  = 2*pi*i/no_points;
        double x = 0.13*cos(angle);
        double y = 0.13*sin(angle);
        glVertex2d(x,y);
    }
    glEnd();
    glFlush();
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,1.0);

    double fraction = 0.0;
    for(int j=0;j<24;j++)
    {
        for(int i=0;i<no_points;i++) {
        double x = i*0.13*cos(fraction)/no_points;
        double y = i*0.13*sin(fraction)/no_points;
        glVertex2d(x,y);
        }
        fraction += pi/12.0;
    }
    glEnd();
    glFlush();
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2d(-0.7,0.6);
    glVertex2d(-0.7,-1);
    glVertex2d(-0.8,-1);
    glVertex2d(-0.8,0.6);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Indian Flag");
    glutDisplayFunc(drawFlag);
    glutMainLoop();
}