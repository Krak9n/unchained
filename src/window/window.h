#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include "glad.h"
#define GLFW_INCLUDE_NONE 
#include <GLFW/glfw3.h>
#include "../ppm/img_s.h"

typedef struct {
  int32_t width;
  int32_t height;
  std::string title;
  GLFWwindow *window;
  bool fPressed;
} wind;

void input(wind *windows);
int initGLFW(wind *windows);
int initGLAD();
int creates(wind *windows);
void framebuffer_size_callback(uint width, uint height);
std::string cursorPOSX(GLFWwindow *window);
std::string cursorPOSY(GLFWwindow *window);
std::string Cfps();

#endif
