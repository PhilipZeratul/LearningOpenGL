#pragma once
#include <vector>

class BezierCurve
{
public:
    BezierCurve() {}
    BezierCurve(float _p1x, float _p1y, float _p2x, float _p2y, float _p3x, float _p3y, float _p4x, float _p4y, int subdivisions);
    float* getVertices();
    size_t vertexDataSize();
    size_t vertexCount();
private:
    float evaluate(float p1, float p2, float p3, float p4, float t);

    std::vector<float> vertices;    
};

