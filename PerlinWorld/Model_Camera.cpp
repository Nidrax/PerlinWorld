#include "stdafx.h"

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