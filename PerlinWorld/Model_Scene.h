#ifndef PERLINWORLD_MODEL_SCENE_H
#define PERLINWORLD_MODEL_SCENE_H

struct Scene {
	void Render();
};

struct Camera {
	vec3 pos;
	vec3 dir;
	float velRX, velRY;

	Camera(vec3, vec3);
	void Update();
};

void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);

#endif // !PERLINWORLD_MODEL_SCENE_H