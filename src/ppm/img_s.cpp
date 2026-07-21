#include "img_s.h"

namespace SavesToImg {
  std::string name;

  std::string filename() {
    std::string pathTest = std::filesystem::current_path();

    if (pathTest.find("build") > 0) {
      std::string path = pathTest.substr(pathTest.find("build") + 1);
      int i = 0;

//      name.insert(name.size(), "%s %d", path, (std::string)++i); 
    }
    return "";
  }

  int8_t saves() {
    return 1;
  }

  void save() {
    std::cout << filename();
    if (saves() == 1) {
      std::cout << "saving to the img failed\n";
      return;
    }
  }
}
