#ifndef PERLINWORLD_MODEL_BASICMATH_H
#define PERLINWORLD_MODEL_BASICMATH_H
#define _USE_MATH_DEFINES

#include <math.h>

template <typename T>
inline T BasicLerp(T w, T v0, T v1) { return (1 - w)*v0 + w*v1; }

template <typename T>
inline T FmaLerp(T w, T v0, T v1) { return _Fma(w, v1, _Fma(-w, v0, v0)); }

template <typename T>
inline T Gradient(int hash, T x, T y, T z) {
	int h = hash & 15;	// Convert lower 4 bits of hash into 12 gradient directions
	T u = h < 8 ? x : y,
		v = h < 4 ? y : h == 12 || h == 14 ? x : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

inline unsigned int Hash(std::string s) {
	boost::crc_32_type r;
	r.process_bytes(s.data(), s.length());
	return r.checksum();
}

inline void ReSeed(unsigned int *seed) {
	*seed = floor(1 + ((*seed / 2) + 2 * sqrt(*seed)) / 2 + *seed / 2 + 4 * sqrt(*seed));
}

struct vec3 {

	float x, y, z;

	vec3() {
		x = y = z = 0.0f;
	}

	vec3(float nx, float ny, float nz) {
		x = nx;
		y = ny;
		z = nz;
	}

	vec3(float nxyz) {
		x = y = z = nxyz;
	}

	void Set(float nxyz) {
		x = y = z = nxyz;
	}

	void Set(float nx, float ny, float nz) {
		x = nx;
		y = ny;
		z = nz;
	}

	void Set(vec3 v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	vec3 operator=(const vec3 v) {
		Set(v.x, v.y, v.z);
		return *this;
	}

	vec3 operator-(const vec3 v) {
		return vec3(x - v.x, y - v.y, z - v.z);
	}

	vec3 operator+(const vec3 v) {
		return vec3(x + v.x, y + v.y, z + v.z);
	}

	vec3 operator*(const float f) {
		return vec3(x * f, y * f, z * f);
	}

	bool operator>(vec3 v) {
		return (x > v.x && y > v.y && z > v.z);
	}

	bool operator>=(vec3 v) {
		return (x >= v.x && y >= v.y && z >= v.z);
	}

	bool operator<(vec3 v) {
		return (x < v.x && y < v.y && z < v.z);
	}

	bool operator<=(vec3 v) {
		return (x <= v.x && y <= v.y && z <= v.z);
	}

	bool operator==(vec3 v) {
		return (x == v.x && y == v.y && z == v.z);
	}

	float Length() {
		return sqrt(x * x + y * y + z * z);
	}

	float Length2() {
		return x * x + y * y + z * z;
	}

	void Normalize() {
		float d = Length();
		x /= d;
		y /= d;
		z /= d;
	}

	void SetLength(float l) {
		Normalize();
		x *= l;
		y *= l;
		z *= l;
	}

	void Rotate(vec3 r) {
		r = r * (M_PI / 180.0f);

		float nx = x * cos(r.y) * cos(r.z) + y * (-cos(r.x) * sin(r.z) + sin(r.x) * sin(r.y) * cos(r.z)) + z * (sin(r.x) * sin(r.z) + cos(r.x) * sin(r.y) * cos(r.z));
		float ny = x * cos(r.y) * sin(r.z) + y * (cos(r.x) * cos(r.z) + sin(r.x) * sin(r.y) * sin(r.z)) + z * (-sin(r.x) * cos(r.z) + cos(r.x) * sin(r.y) * sin(r.z));
		float nz = -x * sin(r.y) + y * sin(r.x) * cos(r.y) + z * cos(r.x) * cos(r.y);

		x = nx;
		y = ny;
		z = nz;
	}

	void Scale(float s) {
		x *= s;
		y *= s;
		z *= s;
	}

	void Scale(float sx, float sy, float sz) {
		x *= sx;
		y *= sy;
		z *= sz;
	}

	void Scale(vec3 s) {
		x *= s.x;
		y *= s.y;
		z *= s.z;
	}

	float Dot(vec3 b) {
		return x * b.x + y * b.y + z * b.z;
	}

	static void Cross(vec3 a, vec3 b, vec3 &c) {
		c.x = a.y * b.z - a.z * b.y;
		c.y = a.z * b.x - a.x * b.z;
		c.z = a.x * b.y - a.y * b.x;
	}

};

#endif // !PERLINWORLD_MODEL_BASICMATH_H