#include "stdafx.h"

void Scene::Render(){
	float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);

	float gl_fogcolor[] = { 0.75f, 0.75f, 0.75f, 1.0f };
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, gl_fogcolor);
	glFogf(GL_FOG_START, 80.0f);
	glFogf(GL_FOG_END, 150.0f);

	float l0_amb[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	float l0_dif[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float l0_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float l0_pos[] = { -1.0f, .2f, 0.5f, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0_spe);
	glLightfv(GL_LIGHT0, GL_POSITION, l0_pos);
	float l1_amb[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float l1_dif[] = { 1.0f, 1.0f, 1.00f, 1.0f };
	float l1_spe[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float l1_pos[] = { 1.0f, .4f, -0.25f, 0.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, l1_amb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, l1_dif);
	glLightfv(GL_LIGHT1, GL_SPECULAR, l1_spe);
	glLightfv(GL_LIGHT1, GL_POSITION, l1_pos);
}