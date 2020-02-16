#include "PolarSphere.h"

PolarSphere::PolarSphere(float radius, int sectorCount, int stackCount)
{
	float sectorStep = 2 * M_PI / sectorCount;
	float stackStep = M_PI / stackCount;
	float sectorAngle, stackAngle;
	float x, y, z, xy;

	// Vertices
	for (size_t i = 0; i <= stackCount; ++i)
	{
		stackAngle = M_PI_2 - (double)stackStep * i;
		xy = radius * cosf(stackAngle);
		z = radius * sinf(stackAngle);

		for (size_t j = 0; j <= sectorCount; ++j)
		{
			sectorAngle = sectorStep * j;
			x = xy * cosf(sectorAngle);
			y = xy * sinf(sectorAngle);
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);
		}
	}

	// Indices
	int k1, k2;
	for (int i = 0; i < stackCount; i++)
	{
		k1 = i * (sectorCount + 1);
		k2 = k1 + sectorCount + 1;

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}
}