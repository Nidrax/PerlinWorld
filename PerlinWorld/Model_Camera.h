#pragma once

class Camera {
public:
	vec3 pos;
	vec3 dir;
	float velRX, velRY;

	Camera(vec3, vec3);
	void Update();
};