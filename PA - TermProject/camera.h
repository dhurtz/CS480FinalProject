#ifndef CAMERA_H
#define CAMERA_H

#include "graphics_headers.h"

class Camera
{
  public:
    Camera();
    ~Camera();
    bool Initialize(int w, int h);
    glm::mat4 GetProjection();
    glm::mat4 GetView();

    void updateView(glm::vec3 cameraFront);
    void cameraPosVert(float speed);
    void cameraPosHorz(float speed);
    void zoom(float fov);
    glm::vec3 getCameraPos() { return cameraPos; }
    glm::vec3 getCameraFront() { return cameraFront; }
    glm::vec3 getCameraUp() { return cameraUp; }
    void setOldPos() 
    { 
        cameraPos = oldCameraPos; 
        view = glm::lookAt(cameraPos, cameraFront + cameraPos, cameraUp); 
    }
    void setNewPos(glm::vec3 planetPosition, float size) 
    {
        cameraPos = planetPosition + glm::vec3{2* size, 2* size, 2* size };
        view = glm::lookAt(cameraPos, planetPosition, glm::vec3(0.0f, 1.0f, 0.0f));
    }
    void setterPosFront(glm::vec3 pos) { oldCameraPos = cameraPos; }
    glm::vec3 oldCameraPos;
    bool isInteracting = false; 

  private:
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 20.0f);
    glm::vec3 cameraFront = glm::vec3(0.0, 1.0, 1.0);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    
    double x = 0.0;
    double y = 10.0;
    double z = -16.0;
    glm::mat4 projection;
    glm::mat4 view;
};

#endif /* CAMERA_H */
