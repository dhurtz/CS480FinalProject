#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <stack>
using namespace std;

#include "graphics_headers.h"
#include "camera.h"
#include "shader.h"
#include "object.h"
#include "sphere.h"
#include "SkyBox.h"
#include "mesh.h"

#define numVBOs 2;
#define numIBs 2;


class Graphics
{
  public:
    Graphics();
    ~Graphics();
    bool Initialize(int width, int height);
    void HierarchicalUpdate2(double dt);
    void Render();

    Camera* getCamera() { return m_camera; }
    Mesh* getStarShip() { return m_mesh; }

  private:
    std::string ErrorString(GLenum error);

    bool collectShPrLocs();
    void ComputeTransforms (double dt, std::vector<float> speed, std::vector<float> dist,
        std::vector<float> rotSpeed, glm::vec3 rotVector, std::vector<float> scale, 
        glm::mat4& tmat, glm::mat4& rmat, glm::mat4& smat);

    stack<glm::mat4> modelStack;

    Camera *m_camera;
    Shader *m_shader;

    GLint m_projectionMatrix;
    GLint m_viewMatrix;
    GLint m_modelMatrix;
    GLint m_positionAttrib;
    GLint m_colorAttrib;
    GLint m_tcAttrib;
    GLint m_hasTexture;

    // Skybox
    SkyBox* m_skyBoxes[6] = {};
    SkyBox* m_skyBox;

    // Planets and moons
    Sphere* m_sun;

    Sphere* m_mercury;

    Sphere* m_venus;

    Sphere* m_earth;
    Sphere* m_earths_moon;

    Sphere* m_mars;
    Sphere* m_mars_moon1;
    Sphere* m_mars_moon2;

    Sphere* m_jupiter;
    Sphere* m_jupiter_moon1;
    Sphere* m_jupiter_moon2;
    Sphere* m_jupiter_moon3;

    Sphere* m_saturn;
    Sphere* m_saturn_moon1;
    Sphere* m_saturn_moon2;
    Sphere* m_saturn_moon3;
    Sphere* m_saturn_moon4;
    Sphere* m_saturn_moon5;

    Sphere* m_uranus;
    Sphere* m_uranus_moon1;
    Sphere* m_uranus_moon2;
    Sphere* m_uranus_moon3;
    Sphere* m_uranus_moon4;
    Sphere* m_uranus_moon5;

    Sphere* m_neptune;
    Sphere* m_neptune_moon1;
    Sphere* m_neptune_moon2;
    Sphere* m_neptune_moon3;
    Sphere* m_neptune_moon4;

    // comet
    Sphere* m_haley;

    // Mesh
    Mesh* m_mesh;



};

#endif /* GRAPHICS_H */
