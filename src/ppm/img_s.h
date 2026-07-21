#pragma once
#ifndef IMG_S_H
#define IMG_S_H

#include <stdint.h>
#include <iostream>
#include <filesystem>

namespace SavesToImg {
  std::string filename();
  int8_t saves(); 
  void save();
}

#endif 
