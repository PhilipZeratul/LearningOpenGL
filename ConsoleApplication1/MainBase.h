#pragma once

class MainBase
{
public:
    virtual ~MainBase() {}
    virtual void Draw() = 0;

protected:
    unsigned int VAO;
    unsigned int shaderProgram;
};