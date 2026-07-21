#pragma once
#ifndef STATE_H
#define STATE_H

#include "glad.h"
#include <vector>
#include <iostream>
#include <glm/vec3.hpp>
#include "../types/types.h"

class TextState {
  public:
    TextState();
    int buffers();
    void bindsVAO(); 
    void bindsTextVAO();
    void bindsBUFFER();
    void cleans();
  private:
    BFS bfs{};
};

#endif
