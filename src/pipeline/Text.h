#pragma once
#ifndef STATE_H
#define STATE_H

#include "glad/glad.h"
#include <vector>
#include <iostream>
#include <glm/vec3.hpp>
#include "types.h"

class Text {
  public:
    Text();
    int buffers();
    void bindsVAO(); 
    void bindsTextVAO();
    void bindsBUFFER();
    void cleans();
  private:
    BFS bfs{};
};

#endif
