#include "window.h"

// i mean.. name speaks for itself
void input(wind *windows) {
  // escape key aint getting picked up yet
  // fucking hell in my case it was actual escape even though
  // i have keyd instance running for it being renamed. shit is fucked 
  // up and junky
  if (glfwGetKey(windows->window, GLFW_KEY_E) == GLFW_PRESS) { 
    std::cout << "EXIT REQUESTED\n";
    glfwSetWindowShouldClose(windows->window, true);
  }
  if (glfwGetKey(windows->window, GLFW_KEY_SPACE) == GLFW_PRESS) { 
    std::cout << "SPACE KEY PRESSED\n";
  }

  if (glfwGetKey(windows->window, GLFW_KEY_PRINT_SCREEN) == GLFW_PRESS) {
    std::cout << "screenshot of the state called\n";
    SavesToImg::save();
  }

  if (glfwGetMouseButton(windows->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
    std::cout << "pressed left mouse button\n";
    //changeColor();
    //do shit
  }

  /*if (glfwGetKey(windows->window, GLFW_KEY_F) == GLFW_PRESS) {
    windows->fPressed = true;
  }
  if (glfwGetKey(windows->window, GLFW_KEY_G) == GLFW_PRESS) {
    windows->fPressed = false;
  }*/
}

// initializing glfw
// and putting everything in main
int initGLFW(wind *windows) {
  // window shit
  windows->window = glfwCreateWindow(
      windows->width,
      windows->height,
      // c_str() returns a pointer to a null-terminated 
      // character array with data equivalent to 
      // those stored in the string. 
      // https://en.cppreference.com/w/cpp/string/basic_string/c_str
      windows->title.c_str(),
      NULL,
      NULL
      );
  if (windows->window == NULL) {
    std::cout << "\tFAILED::TO::CREATE::A::GLFW::WINDOW\n";
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(windows->window);
  return 0;
}

// well just initializing glad
// for fuck's sake
int initGLAD() {
  // here we get passed the function GLADloadproc
  // to load the address of the OGL function which
  // is os specific, and then glfwGetProcAddress 
  // handles the os specification aka where does it 
  // compile
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "\tFAILED::TO::INITIALIZE::GLAD\n";
    return -1;
  }
  return 0;
}

// checking if everything is okay
// and then if it is, returning 0
int creates(wind *windows) {
  // initializing glfw
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // opengl version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); // 4.6
  // some debug context
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
  // using core profile
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  // shit for os x
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPACT, GL_TRUE);
#endif


  if (initGLFW(windows) == -1) {
    std::cout << "error while initializing glfw\n";
    return -1;
  }
  std::cout << "glfw passed\n";
  if (initGLAD() == -1) {
    std::cout << "error while initializing glad\n";
    return -1;
  }
  std::cout << "glad passed\n";

  // getting current window size
  glfwGetWindowSize(
      windows->window, 
      &windows->width, 
      &windows->height
      );
  // well just tells glfw which handles the window
  // to call the second argument each time the 
  // window is resized
  framebuffer_size_callback(
      (uint)windows->width, 
      (uint)windows->height
      );
  glfwSetFramebufferSizeCallback(
      windows->window,
      (GLFWframebuffersizefun)framebuffer_size_callback
      );
  return 0;
}

// this small function should be called each time
// a user resizes the window. well, should adjust.
void framebuffer_size_callback(uint width, uint height) {
  // sets up the viewport for opengl.
  // in simple words just tells ogl the size 
  // of the rendering window
  glViewport(
      0, 
      0, 
      width, 
      height
      );
// glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
// in general here dimensions start from the bottom, 
// so y = 0, and x = 0, would mean that it is the bottom left 
 
}

std::string cursorPOSX(GLFWwindow *window) {
  double xpos = 0.0f;
  double ypos = 0.0f; 
  glfwGetCursorPos(window, &xpos, &ypos);

  /*std::string del = "\n";

  std::vector<std::string> pos;
  pos.insert(pos.end(), 
      {"x pos is: ", 
      std::to_string((int)xpos)});
 
  std::string positions;
  for (const auto &s : pos) {
    if (!positions.empty()) {
      positions += del;
    }
    positions += s;
  }*/
  std::string positions = std::to_string((int)xpos);

  return positions;
}
std::string cursorPOSY(GLFWwindow *window) {
  double xpos = 0.0f;
  double ypos = 0.0f; 
  glfwGetCursorPos(window, &xpos, &ypos);

  /*std::string del = "\n";

  std::vector<std::string> pos;
  pos.insert(pos.end(), 
      {"y pos is: ", 
      std::to_string((int)ypos)});
 
  std::string positions;
  for (const auto &s : pos) {
    if (!positions.empty()) {
      positions += del;
    }
    positions += s;
  }*/
  std::string positions = std::to_string((int)ypos);

  return positions;
}

// frame / second = 1 / (s/f)
std::string Cfps() {
  return "";
}
