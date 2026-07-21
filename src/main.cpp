#include "glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
// mine
#include "window/window.h"
#include "pipeline/shader.h"
#include "pipeline/TextState.h"
#include "pipeline/VideoState.h"
#include "text/text.h"

int main() {
  wind _window = {
    .width = 1920,
    .height = 1080,
    .title = "jesus christ is dead",
    .window = nullptr,
    .fPressed = false
  };
  wind *windows = &_window; //?
  creates(windows); 

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  shader screenTEXT("../shaders/text/TextVertex.glsl", "../shaders/text/TextFragment.glsl");
  shader mains("../shaders/world/Vertex.glsl", "../shaders/world/Fragment.glsl");// fuck
  //shader enironment();

  glm::mat4 projection = glm::ortho(
      0.0f, static_cast<float>(windows->width), 
      0.0f, static_cast<float>(windows->height));
  screenTEXT.use();
  glUniformMatrix4fv(
      screenTEXT.uniformLocation("projection"), 
      1, GL_FALSE, glm::value_ptr(projection));

  VideoState videoObjects;
  TextState renderer;

  ft text;
  unsigned int sizeOf = sizeof(Vertex) / sizeof(glm::vec3);
  while(!glfwWindowShouldClose(windows->window)) { 
    // function from above checks on each new loop if 
    // the glfw has been instructed to be closed
    input(windows);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glfwGetWindowSize(
        windows->window, 
        &windows->width, 
        &windows->height);
    framebuffer_size_callback(
        (uint)windows->width, 
        (uint)windows->height);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // this will clear
                          // all previous frames
                          // generated
    // update to the projection
    projection = glm::ortho(
        0.0f, static_cast<float>(windows->width), 
        0.0f, static_cast<float>(windows->height));
    screenTEXT.use();
    glUniformMatrix4fv(
        screenTEXT.uniformLocation("projection"), 
        1, GL_FALSE, glm::value_ptr(projection));

    mains.use();
    videoObjects.bindsVAO();
    glDrawArrays(GL_TRIANGLES, 0, sizeOf);

    text.render(
        screenTEXT,
        renderer,
        glm::vec3(1.0f, 1.0f, 1.0f),
        cursorPOSX(windows->window),
        (float)(5),
        (float)(windows->height - 35),
        0.8f);
    text.render(
        screenTEXT,
        renderer,
        glm::vec3(1.0f, 1.0f, 1.0f),
        cursorPOSY(windows->window),
        (float)(5),
        (float)(windows->height - 60),
        0.8f);

    glfwSwapBuffers(windows->window);
    glfwPollEvents(); 
  }
  renderer.cleans();
  videoObjects.cleans();
  screenTEXT.cleans();

  // cleaning 
  glfwDestroyWindow(windows->window);
  glfwTerminate();
  return 0;
}

