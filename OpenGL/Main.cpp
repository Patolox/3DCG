#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <gl/glut.h>

float RotateAngle = 0;

float C0X = -0.8f;
float C0Y = -0.4f;
float C0Z = 0.0f;

float C1X = 0.0f;
float C1Y = -1.0f;
float C1Z = 0.0f;

float C2X = 0.8f;
float C2Y = -0.4f;
float C2Z = 0.0f;


// Coordenadas da piramide
float PX = -0.8f;
float PY = 0.0f;
float PZ = 0.0f;

// 0 = rotacionar x, 1 = rotacionar y, 2 = rotacionar z
int rotateCubeAxis = 0;

// Raio da esfera
float sphereRadius = 0.2f;


void timer(int frame)
{
	RotateAngle += 0.01;
	glutPostRedisplay();
}

void reshape(int w, int h) {

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	gluLookAt(
		0.0, 0.3, 0.3,
		0, 0, 0,
		0, 1, 0);

	glTranslatef(0.0f, -0.5f, -1.0f);

}

void mousePressed(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	}
	glutTimerFunc(40, timer, 0);
}

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
		case '0':
			rotateCubeAxis = 0;
			break;
		case '1':
			rotateCubeAxis = 1;
			break;
		case '2':
			rotateCubeAxis = 2;
			break;
		case 'w':
			PY += 0.1f;
			break;
		case 's':
			PY -= 0.1f;
			break;
		case 'a':
			PX -= 0.1f;
			break;
		case 'd':
			PX += 0.1f;
			break;
		case 'i':
			PZ += 0.1f;
			break;
		case 'k':
			PZ -= 0.1f;
			break;
		case 'z':
			sphereRadius -= 0.1f;
			break;
		case 'x':
			sphereRadius += 0.1f;
			break;
	}
	glutPostRedisplay();
}

void drawPyramid() {
	glPushMatrix();
		glTranslatef(PX, PY, PZ);
		glRotatef(RotateAngle, 0, 1, 0);
		glBegin(GL_QUAD_STRIP);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-0.3, -0.5, 0.3);
			glVertex3f(0.3, -0.5, 0.3);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.3, -0.5, -0.3);
			glVertex3f(0.3, -0.5, -0.3);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(PX, PY, PZ);
		glRotatef(RotateAngle, 0, 1, 0);
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0, 0, 0);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.3, -0.5, 0.3);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.3, -0.5, 0.3);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.3, -0.5, -0.3);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-0.3, -0.5, -0.3);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.3, -0.5, 0.3);
		glEnd();
	glPopMatrix();
}

void drawCube() {
	glPushMatrix();
		glTranslatef(0.6f, -0.3f, 0.0f);
		glScalef(-0.5f, -0.5f, -0.5f);
		if (rotateCubeAxis == 0){
			glRotatef(RotateAngle, 1, 0, 0);
		}
		else if (rotateCubeAxis == 1) {
			glRotatef(RotateAngle, 0, 1, 0);
		}
		else {
			glRotatef(RotateAngle, 0, 0, 1);
		}
		glBegin(GL_QUADS);
			glColor3f(0.0f, 1.0f, 0.0f);     // Verde
			glVertex3f(0.3f, 0.5f, -0.3f);
			glVertex3f(-0.3f, 0.5f, -0.3f);
			glVertex3f(-0.3f, 0.5f, 0.3f);
			glVertex3f(0.3f, 0.5f, 0.3f);

			glColor3f(1.0f, 0.5f, 0.0f);     // Laranja
			glVertex3f(0.3f, -0.5f, 0.3f);
			glVertex3f(-0.3f, -0.5f, 0.3f);
			glVertex3f(-0.3f, -0.5f, -0.3f);
			glVertex3f(0.3f, -0.5f, -0.3f);

			glColor3f(1.0f, 0.5f, 0.3f);     // Vermelho
			glVertex3f(0.3f, 0.5f, 0.3f);
			glVertex3f(-0.3f, 0.5f, 0.3f);
			glVertex3f(-0.3f, -0.5f, 0.3f);
			glVertex3f(0.3f, -0.5f, 0.3f);

			glColor3f(1.0f, 0.5f, 0.3f);     // Amarelo
			glVertex3f(0.3f, -0.5f, -0.3f);
			glVertex3f(-0.3f, -0.5f, -0.3f);
			glVertex3f(-0.3f, 0.5f, -0.3f);
			glVertex3f(0.3f, 0.5f, -0.3f);

			glColor3f(0.0f, 0.0f, 0.3f);     // Azul
			glVertex3f(-0.3f, 0.5f, 0.3f);
			glVertex3f(-0.3f, 0.5f, -0.3f);
			glVertex3f(-0.3f, -0.5f, -0.3f);
			glVertex3f(-0.3f, -0.5f, 0.3f);

			glColor3f(1.0f, 0.0f, 0.3f);     // Magenta
			glVertex3f(0.3f, 0.5f, -0.3f);
			glVertex3f(0.3f, 0.5f, 0.3f);
			glVertex3f(0.3f, -0.5f, 0.3f);
			glVertex3f(0.3f, -0.5f, -0.3f);
			
		glEnd();
	glPopMatrix();

}

void drawSphere() {
	const float PI = 3.141592f;
	GLfloat x, y, z, alpha, beta;
	int gradation = 20;

	for (alpha = 0.0; alpha < PI; alpha += PI / gradation)
	{
		glPushMatrix();
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(RotateAngle, 1, 1, 1);
			glBegin(GL_TRIANGLE_STRIP);
			for (beta = 0.0; beta < 2.01 * PI; beta += PI / gradation)
			{
				x = sphereRadius * cos(beta) * sin(alpha);
				y = sphereRadius * sin(beta) * sin(alpha);
				z = sphereRadius * cos(alpha);
				glColor3f(alpha + 0.5, -alpha, alpha);
				glVertex3f(x, y, z);
				x = sphereRadius * cos(beta) * sin(alpha + PI / gradation);
				y = sphereRadius * sin(beta) * sin(alpha + PI / gradation);
				z = sphereRadius * cos(alpha + PI / gradation);
				glColor3f(-alpha+0.5, alpha, alpha);
				glVertex3f(x, y, z);
			}
			glEnd();
		glPopMatrix();
	}
}

void drawCurve() {
	float x;
	float y;
	float z;
	glPushMatrix();
		glTranslatef(0.0f, -0.4f, 0.4f);
		glRotatef(RotateAngle, 0, 1, 0);
		glBegin(GL_LINES);
			for (float t = 0; t < 1; t += 0.001f) {
				x = std::pow(1 - t, 2) * C0X + 2 * t * (1 - t) * C1X + t * t * C2X;
				y = std::pow(1 - t, 2) * C0Y + 2 * t * (1 - t) * C1Y + t * t * C2Y;
				z = std::pow(1 - t, 2) * C0Z + 2 * t * (1 - t) * C1Z + t * t * C2Z;
				glVertex3f(x, y, z);

			}
		glEnd();
	glPopMatrix();
		
}

void draw() {
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	timer(0);
	drawCurve();
	drawPyramid();
	drawCube();
	drawSphere();
	glFlush();
	glutSwapBuffers();

	if (RotateAngle >= 360) {
		RotateAngle = 0;
	}
}

int main(int argc, char** argv) {
	int const win_width = 800;
	int const win_height = 600;
	float const win_aspect = (float)win_width / (float)win_height;
	glutInit(&argc, argv);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(win_width, win_height);
	glutCreateWindow("whitesquare");
	glutTimerFunc(40, timer, 0);
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutMouseFunc(mousePressed);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glLoadIdentity();

	glutMainLoop();
}