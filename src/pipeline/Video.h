#pragma once
#ifndef VIDEO_H
#define VIDEO_H

#include "glad/glad.h"
#include <iostream>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "types.h"

class Video {
  public:
    Video();
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
