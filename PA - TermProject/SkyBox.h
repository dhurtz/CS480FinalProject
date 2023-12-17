#pragma once
#ifndef SKYBOX_H
#define SKYBOX_H

#include <vector>
#include "graphics_headers.h"
#include "Texture.h"

class SkyBox
{
public:
    //on start / on delete functions:  - Seth
    SkyBox(const char* fname, GLint posAttribLoc, GLint colAttribLoc, int posSel);
    ~SkyBox();
    //fucntions that we can call:  - Seth
    void Initialize(GLint posAttribLoc, GLint colAttribLoc);
    void Update(unsigned int dt);
    void Render(GLint posAttribLoc, GLint colAttribLoc);
    void Render(GLint posAttribLoc, GLint colAttribLoc, GLint tcAttribLoc, GLint hasTextureLoc);
    void createVertices();
    glm::mat4 GetModel();
    GLuint getTextureID() { return m_texture->getTextureID(); }
    int positionSelection = 0;
    int size = 0;
    glm::vec3 positions[6];
private:
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    Texture* m_texture;
    bool hasTex;
    GLuint vao;

    GLuint VB;
    GLuint IB;
};

#endif /* SKYBOX_H */
