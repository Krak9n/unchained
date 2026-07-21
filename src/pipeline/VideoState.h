#pragma once
#ifndef VIDEOSTATE_H
#define VIDEOSTATE_H

#include "glad.h"
#include <iostream>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "../types/types.h"

class VideoState {
  public:
    VideoState();
    auto indic() -> int;
    void bindsVAO(); 
    void bindsEBO();
    void bindsTextVAO();
    void bindsBUFFER();
    void cleans();
  private:
    auto grid() -> int;
    BFS bfs{};
};

#endif
