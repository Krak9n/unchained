#pragma once
#ifndef TEXT_H
#define TEXT_H

#include <ft2build.h>
#include FT_FREETYPE_H  
#include "glad.h"
#include <iostream>
#include <string>
#include <stdint.h>
#include <map>
#include <glm/glm.hpp>
#include "../pipeline/shader.h"
#include "../pipeline/TextState.h"

typedef struct {
  FT_Library ft;
  FT_Face face;
} fontValues;

typedef struct {
  uint TextureID;
  glm::ivec2 Size;
  glm::ivec2 Bearing;
  uint Advance;
} Character;

class ft {
  public:
    ft();
    void render(
        shader SHADER, TextState render, 
        glm::vec3 color, std::string text,
        float x, float y, float scale
        );
  private:
    fontValues font{};
    const uint w = 0;
    const uint h = 48;
    std::map<char, Character> Characters;

    int initialize(std::string path);
    int loop();
};

#endif
