#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <time.h>

#include "gsl.h"			// For C++11 guidelines purpose only. You can just remove this line instead of getting GSL (found at https://github.com/Microsoft/GSL)
#include "GL/freeglut.h"	// Just grab the newest freeglut library (Google is your friend) and add it to your project includes directory
#include "boost/crc.hpp"	// Get it from Boost library: http://www.boost.org/

#include "Model_BasicMath.h"
#include "Model_PerlinNoise.h"
#include "Model_Vec3.h"
#include "Model_Scene.h"
#include "Model_Camera.h"
#include "Model_Chunk.h"
#include "View_BasicRendering.h"

#define ChunkWidthX 16
#define ChunkWidthY 16
#define ChunkHeight 16


extern int WIDTH;
extern int HEIGHT;

extern std::vector<std::vector <Chunk>> Map;

extern Scene SC;
extern Camera *MainCam;

#pragma endregion