#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <bits/stdc++.h>
using namespace std;

int depth = 3;


void myInit(void) 
{ 
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0, 500, 0, 500); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
} 

void drawPoly1()
{
  glBegin(GL_QUADS);
  glColor3f(1.0,0.0,0.0);
  glVertex2f(120,100);
  glVertex2f(300,300);
  glVertex2f(500,500);
  glVertex2f(120,400);
  depth--;
  glEnd();
}

void drawPoly2()
{
  glBegin(GL_QUADS);
  glColor3f(0.0,1.0,0.0);
  glVertex2f(170,150);
  glVertex2f(200,150);
  glVertex2f(200,300);
  glVertex2f(170,200);
  depth--;
  glEnd();
}

void drawPoly3()
{
  glBegin(GL_QUADS);
  glColor3f(0.0,0.0,1.0);
  glVertex2f(175,175);
  glVertex2f(195,175);
  glVertex2f(195,250);
  glVertex2f(175,250);
  depth--;
  glEnd();
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

 while(1)
 {
	if(depth==3)
	{
		drawPoly1();
	}
	else if(depth==2)
	{
		drawPoly2();
	}
	else if(depth==1)
	{
		drawPoly3();
	}
	else
	{
		break;
	}
}
	
	glFlush();
}








int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(1000, 1000); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Painter's Algorithm"); 
    glutDisplayFunc(display); 
    myInit();
    glutMainLoop(); 
} 