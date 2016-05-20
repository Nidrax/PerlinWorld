#include "stdafx.h"

int WIDTH = 1280;
int HEIGHT = 720;

Scene SC;
Camera *MainCam = new Camera({ -35.0f, 30.0f, -35.0f }, { 0.57f, -0.4f, 0.72f });

void ViewInit(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutCreateWindow("GameInOneWeek");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); glCullFace(GL_BACK); glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH); glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); glEnable(GL_LIGHT1); glEnable(GL_FOG);

	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	//glutTimerFunc(17, OnTimer, 0);

	glutMainLoop();
}

void OnRender() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.59f, 0.75f, 0.85f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();

	gluLookAt(MainCam->pos.x, MainCam->pos.y, MainCam->pos.z, MainCam->pos.x + MainCam->dir.x, MainCam->pos.y + MainCam->dir.y, MainCam->pos.z + MainCam->dir.z, 0.0f, 1.0f, 0.0f);

	SC.Render();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void OnReshape(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 150.0f);
}