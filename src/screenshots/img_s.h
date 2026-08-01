#pragma once
#ifndef IMG_S_H
#define IMG_S_H

#include <stdint.h>
#include <iostream>
#include <filesystem>

// later add the posibility to do screenshots inside of the game

namespace SavesToImg {
  std::string filename();
  int8_t saves(); 
  void save();
}

#endif 
