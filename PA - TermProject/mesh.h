#ifndef MESH_H
#define MESH_H

#include <vector>
#include "graphics_headers.h"
#include "Texture.h"
#include "Camera.h"

class Mesh
{
public:
    Mesh();
    Mesh(glm::vec3 pivot, const char* fname);
    Mesh(glm::vec3 pivot, const char* fname, const char* tname);

    ~Mesh();
    void Update(glm::mat4 model);
    void UpdatePosition(glm::vec3 pos, glm::vec3 front);
    void Render(GLint posAttrib, GLint colAttrib);
    void Render(GLint positionAttribLoc, GLint colorAttribLoc, GLint tcAttribLoc, GLint hasTex);

    glm::mat4 GetModel();

    bool InitBuffers();
    bool loadModelFromFile(const char* path);

    bool hasTex;
    GLuint getTextureID() { return m_texture->getTextureID(); }


    glm::vec3 getPosition() { return position; }

private:
    glm::vec3 pivotLocation;
    glm::mat4 model;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    GLuint VB;
    GLuint IB;
    Texture* m_texture;
    glm::vec3 position;
    GLuint vao;

    float angle;
};

#endif