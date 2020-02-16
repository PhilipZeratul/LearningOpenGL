//http://www.songho.ca/opengl/gl_sphere.html

#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

class Sphere
{
public:
	size_t vertexDataSize();
	size_t vertexCount();
	size_t indexDataSize();
	size_t indexCount();
	float* getVertices();
	unsigned int* getIndices();

protected:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
};

