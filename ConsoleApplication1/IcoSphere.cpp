#include "IcoSphere.h"

IcoSphere::IcoSphere(float radius)
{
	const float H_ANGLE = M_PI / 180 * 72;
	const float V_ANGLE = atanf(1.0f / 2);

	vertices.resize(12 * 3);
	int i1, i2;
	float z, xy;
	float hAngle1 = -M_PI_2 - H_ANGLE / 2;
	float hAngle2 = -M_PI_2;

	vertices[0] = 0;
	vertices[1] = 0;
	vertices[2] = radius;

	for (size_t i = 0; i <= 5; i++)
	{
		i1 = i * 3;
		i2 = (i + 5) * 3;
		z = radius * sinf(V_ANGLE);
		xy = radius * cosf(V_ANGLE);

		vertices[i1] = xy * cosf(hAngle1);
		vertices[i2] = xy * cosf(hAngle2);
		vertices[i1 + 1] = xy * sinf(hAngle1);
		vertices[i2 + 1] = xy * cosf(hAngle2);
		vertices[i1 + 2] = z;
		vertices[i2 + 2] = -z;

		hAngle1 += H_ANGLE;
		hAngle2 += H_ANGLE;
	}

	i1 = 11 * 3;
	vertices[i1] = 0;
	vertices[i1 + 1] = 0;
	vertices[i1 + 2] = -radius;
}