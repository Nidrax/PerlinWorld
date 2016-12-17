#include "stdafx.h"

bool keystate[256];
bool noDensity = false;

void Scene::Render(){
	float gl_fogcolor[] = { 0.75f, 0.75f, 0.75f, 1.0f };
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, gl_fogcolor);
	glFogf(GL_FOG_START, 200.0f);
	glFogf(GL_FOG_END, 250.0f);

	for (unsigned m = 0; m != Map.size(); m++) {
	 for (unsigned n = 0; n != Map[0].size(); n++) {
	  for (unsigned i = 0; i < ChunkWidthX; i++) {
	   for (unsigned j = 0; j < ChunkWidthY; j++) {
	    for (unsigned k = 0; k < ChunkHeight; k++) {
						
		 if (k < Map[m][n].Get(i, j) && (Map[m][n].Get(i, j, k) || noDensity))
		 {
			glColor3f(0.6, 0.2 + (0.5 / ChunkHeight) * k , 0.1);
			glPushMatrix();
			glTranslatef(m * ChunkWidthX + i, k, n * ChunkWidthY + j);
			glutSolidCube(1.0f);
			glPopMatrix();
		 }

	    }
	   }
	  }
	 }
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

Camera::Camera(vec3 p, vec3 d) {
	/*pos.Set(-20.0f, 20.0f, -20.0f);
	dir.Set(0.1f, -0.05f, 0.0f);*/
	pos = p;
	dir = d;
	velRX = 0.0f;
	velRY = 0.0f;
}

void Camera::Update() {
	float T = acos(dir.y);
	float G = atan2(dir.z, dir.x);
	T -= velRX * .03f;
	G += velRY * .03f;
	dir.x = sin(T) * cos(G);
	dir.y = cos(T);
	dir.z = sin(T) * sin(G);
}

void OnKeyPress(unsigned char key, int x, int y) {
	if (!keystate[key]) {
		OnKeyDown(key, x, y);
	}
	keystate[key] = true;
}

void OnKeyDown(unsigned char key, int x, int y) {
	if (key == 27) {
		glutLeaveMainLoop();
	}
	if (key == 32) {
		noDensity = !noDensity;
	}
}

void OnKeyUp(unsigned char key, int x, int y) {
	keystate[key] = false;
}