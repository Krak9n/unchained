#pragma once
#ifndef SHADER_H
#define SHADER_H

#include "glad.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../types/types.h"

typedef struct {
  int success;
  std::string logs;
} infos;

// just empty
typedef struct {
  unsigned int vertexShader;
  unsigned int fragmentShader;
  unsigned int shader;
} SHADERS;

class shader {
  public: 
    shader(std::string vertex, std::string fragment);
    void use();
    void linking();
    void compiling(std::string vertex, std::string fragment);
    void cleans();
    auto uniformLocation(
        const char *UniformName
        ) -> int;
  private:
    SHADERS values{0};
    infos *info = new infos();

    std::string readGLSL(std::string f);
    void error_handle(unsigned int shader, std::string type);
};

#endif
