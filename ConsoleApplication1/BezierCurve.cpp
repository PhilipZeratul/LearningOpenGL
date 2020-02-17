#include <iostream>
#include "BezierCurve.h"

BezierCurve::BezierCurve(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y, int subdivisions)
{
    float step = 1.0f / subdivisions;
    for (float t = 0; t < 1.0f; t += step)
    {
        float x = evaluate(p1x, p2x, p3x, p4x, t);
        float y = evaluate(p1y, p2y, p3y, p4y, t);
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f);

        std::cout << x << ", " << y << ", 0" << std::endl;
    }
    vertices.push_back(p4x);
    vertices.push_back(p4y);
    vertices.push_back(0.0f);

    std::cout << p4x << ", " << p4y << ", 0" << std::endl;
}

float* BezierCurve::getVertices()
{
    return &vertices[0];
}

size_t BezierCurve::vertexDataSize()
{
    return vertices.size() * sizeof(vertices[0]);
}

size_t BezierCurve::vertexCount()
{
    return vertices.size();
}

// Bezier Cubic
float BezierCurve::evaluate(float p1, float p2, float p3, float p4, float t)
{
    if (t < 0.0f || t > 1.0f)
    {
        std::cout << "ERROR: Bezier curve evaluation parameter t = "<< t << "out of (0, 1) bound!" << std::endl;
        return 0;
    }
    float s = 1 - t;
    float AB = p1 * s + p2 * t;
    float BC = p2 * s + p3 * t;
    float CD = p3 * s + p4 * t;
    float ABC = AB * s + BC * t;
    float BCD = BC * s + CD * t;
    return ABC * s + BCD * t;
}
