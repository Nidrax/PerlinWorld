#pragma once

template <typename T>
T Lerp(T w, T v0, T v1) { return (1 - w)*v0 + w*v1; }
/* This function makes a linear interpolation between two values based
on a weight factor. It should be a value in the range [0.0, 1.0] */

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