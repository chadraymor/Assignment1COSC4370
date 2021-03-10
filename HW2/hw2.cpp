/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

double d2r(double a)
{
	return a * 3.14159265358979323846 / 180;
}

void problem1() {
    // TODO: Your code here!
	int a = 36;
	while (a <= 360)
	{
		glPushMatrix();
		glTranslated(cos(d2r(a)), sin(d2r(a)), 0);
		glRotatef(a, 0, 0, 1);
		glutSolidTeapot(.25);
		a = a + 36;
	}
}

void problem2() {
    // TODO: Your code here!
	int n = 1;
	double x = -3.75;
	while (n <= 15)
	{          
		double y = 0;
		double yinc = .03;
		int i = 0;
		while (i < n)
		{
			glPushMatrix();
			glTranslated(x, y, 0);
			glutSolidCube(.5);
			glPopMatrix();
			yinc = yinc * 1.13;
			y = y + yinc;
			i=i+1;
		}
		x = x + .5;
		n = n+1;
	}
}

void createRowTea(double n, double y)
{
	double r = 1;
	if(int(n)%2==1)
	{ 
		glPushMatrix();
		glTranslated(0, y, 0);
		glutSolidTeapot(.25);
		glPopMatrix();
		while (r!=ceil(n/2.0))
		{
			glPushMatrix();
			glTranslated(r, y, 0);
			glutSolidTeapot(.25);
			glPopMatrix();
			glPushMatrix();
			glTranslated(-r, y, 0);
			glutSolidTeapot(.25);
			glPopMatrix();
			r++;
		}
	}
	else
	{
		r = .5;
		while (r<=n/2)
		{
			glPushMatrix();
			glTranslated(r, y, 0);
			glutSolidTeapot(.25);
			glPopMatrix();
			glPushMatrix();
			glTranslated(-r, y, 0);
			glutSolidTeapot(.25);
			glPopMatrix(); 
			r++;
		}
	}
}

void problem3() {
    // TODO: Your code here!
	createRowTea(1, 1);
	createRowTea(2, .5);
	createRowTea(3, 0);
	createRowTea(4, -.5);
	createRowTea(5, -1);
	createRowTea(6, -1.5);
}


void createRowCube(double n, double y)
{
	double r = 0;
	glPushMatrix();
	glTranslated(0, y, 0);
	glutSolidCube(.25);
	glPopMatrix();
	while (r < n/1.5)
	{
		glPushMatrix();
		glTranslated(r, -y/2, 0);
		glutSolidCube(.25);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-r, y/2, 0);
		glutSolidCube(.25);
		glPopMatrix();
		r=r+.2;
	}
}

void makeTri()
{
	glOrtho(0, 0, 0, 0, 1, -1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0, 0);
	glVertex2f(2, 3);
	glVertex2f(3, 2);
	glVertex2f(3, 3);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0, 0);
	glVertex2f(-2, 3);
	glVertex2f(-3, 2);
	glVertex2f(-3, 3);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0, 0);
	glVertex2f(-2, -3);
	glVertex2f(-3, -2);
	glVertex2f(-3, -3);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0, 0);
	glVertex2f(2, -3);
	glVertex2f(3, -2);
	glVertex2f(3, -3);
	glEnd();
}

void problem4() {
    // TODO: Your code here!
	
	makeTri();
	createRowCube(3, 0);
	createRowCube(2.5, 1);
	createRowCube(2, 2);
	createRowCube(1.5, 3);
	createRowCube(1, 4);
	createRowCube(.5, 5);
	createRowCube(3, 0);
	createRowCube(2.5, -1);
	createRowCube(2, -2);
	createRowCube(1.5, -3);
	createRowCube(1, -4);
	createRowCube(.5, -5);

}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
