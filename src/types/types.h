#pragma once
#ifndef HELP_H
#define HELP_H

#include <vector>
#include <stdint.h>
#include <glm/vec3.hpp>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef float f32;

// this doesnt make any sense.
// such a shitty code
typedef struct {
  u32 VAOtext;
  u32 VAO_vertices;
  u32 VAO_colors;
  u32 VBO_text; // first for shits
  u32 VBO_vertices; // second for text
  u32 VBO_colors;
  u32 EBO;
  u32 IBO;
} BFS;

typedef struct Vertex {
  Vertex() = default;
  Vertex(glm::vec3 position) {
    pos = position;
  }
  glm::vec3 pos = glm::vec3(0);
} Vertex;

#endif
