#include "stdafx.h"

void Scene::Render(){

	float gl_fogcolor[] = { 0.75f, 0.75f, 0.75f, 1.0f };
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, gl_fogcolor);
	glFogf(GL_FOG_START, 150.0f);
	glFogf(GL_FOG_END, 200.0f);

	for (unsigned m = 0; m != Map.size(); m++) {
		for (unsigned n = 0; n != Map[0].size(); n++) {
			for (unsigned i = 0; i < ChunkWidthX; i++) {
				for (unsigned j = 0; j < ChunkWidthY; j++) {
					for (unsigned k = 0; k < ChunkHeight; k++) {
						
						if (k < Map[m][n].Get(i, j) /*&& Map[m][n].Get(i, j, k)*/) {
							glColor3f(0.25, 0.3 + 0.025 * k , 0.25);
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