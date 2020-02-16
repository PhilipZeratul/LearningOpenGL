#include "sphere.h"

size_t Sphere::vertexDataSize()
{
	return vertices.size() * sizeof(vertices[0]);
}

size_t Sphere::vertexCount()
{
	return vertices.size();
}

size_t Sphere::indexDataSize()
{
	return indices.size() * sizeof(indices[0]);
}

size_t Sphere::indexCount()
{
	return indices.size();
}

float* Sphere::getVertices()
{
	return &vertices[0];
}

unsigned int* Sphere::getIndices()
{
	return &indices[0];
}