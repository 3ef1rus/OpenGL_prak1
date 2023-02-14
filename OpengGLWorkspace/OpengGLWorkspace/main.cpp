//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <iostream>


void RenderString(float x, float y, void* font)
{
	char* c;

	glColor3f(1, 0, 0);
	glRasterPos2f(x, y);
	unsigned char ta[] = "Vial";
	unsigned char* t = ta;
	glutBitmapString(font, t);
}

void Display() {
	while (true) {
		glClear(GL_COLOR_BUFFER_BIT);
		glTranslated(0.4, 0.6, 0.15);
		RenderString(0.25f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		glRotated(0.005, 0.1, 1, 0);  // аним 2 вращение вокрук Y
	//	glScaled(1, 1, 1);
	//	glRotated(0.05, 0.1, 1, 0);
		glTranslated(-0.4, -0.6, -0.15);
		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 1);
		//yea
			//1
		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 1);
		glVertex3f(0.2, 0.4, 0.0);
		glVertex3f(0.6, 0.4, 0.0);
		glVertex3f(0.4, 0.6, 0.0);
		glVertex3f(0.2, 0.8, 0.0);
		glVertex3f(0.6, 0.8, 0.0);
		glVertex3f(0.4, 0.6, 0.0);
		glEnd();
		//низ
		glBegin(GL_QUADS);
		glColor3f(0, 0, 1);
		glVertex3f(0.2, 0.8, 0.0);
		glVertex3f(0.6, 0.8, 0.0);
		glVertex3f(0.6, 0.8, 0.3);
		glVertex3f(0.2, 0.8, 0.3);
		glEnd();

		//верх
		glBegin(GL_QUADS);
		glColor3f(0, 0.5, 0);
		glVertex3f(0.2, 0.4, 0.0);
		glVertex3f(0.6, 0.4, 0.0);
		glVertex3f(0.6, 0.4, 0.3);
		glVertex3f(0.2, 0.4, 0.3);
		glEnd();

		//levoniz

		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(0.2, 0.4, 0.0);
		glVertex3f(0.2, 0.4, 0.3);
		glVertex3f(0.4, 0.6, 0.3);
		glVertex3f(0.4, 0.6, 0.0);
		glEnd();
		//levoverh

		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(0.4, 0.6, 0.0);
		glVertex3f(0.4, 0.6, 0.3);
		glVertex3f(0.2, 0.8, 0.3);
		glVertex3f(0.2, 0.8, 0.0);
		glEnd();

		//pravoniz

		glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(0.6, 0.4, 0.0);
		glVertex3f(0.6, 0.4, 0.3);
		glVertex3f(0.4, 0.6, 0.3);
		glVertex3f(0.4, 0.6, 0.0);
		glEnd();
		//pravoverh

		glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0);
		glVertex3f(0.4, 0.6, 0.0);
		glVertex3f(0.4, 0.6, 0.3);
		glVertex3f(0.6, 0.8, 0.3);
		glVertex3f(0.6, 0.8, 0.0);
		glEnd();
		//2
		/*glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);
		glVertex3f(0.2, 0.4, 0.3);
		glVertex3f(0.6, 0.4, 0.3);
		glVertex3f(0.4, 0.6, 0.3);
		glVertex3f(0.2, 0.8, 0.3);
		glVertex3f(0.6, 0.8, 0.3);
		glVertex3f(0.4, 0.6, 0.3);
		glEnd();*/

		glFlush();
	}
}

void Initialize() {
	glClearColor(0.8, 1.0, 0.6, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1, 0, 1);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("lab1");

		glutDisplayFunc(Display);

	Initialize();
	glutMainLoop();
	return 0;
}

