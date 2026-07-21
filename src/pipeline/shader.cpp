#include "shader.h"

shader::shader(std::string vertex, std::string fragment) {
  compiling(vertex, fragment);
  linking(); 

  glDeleteShader(values.vertexShader);
  glDeleteShader(values.fragmentShader);
  delete info;
}

auto shader::uniformLocation(
    const char *UniformName) -> int {
  int value = glGetUniformLocation(values.shader, UniformName);
  return value;
}

void shader::use() {
  glUseProgram(values.shader);
}

void shader::linking() {
  values.shader = glCreateProgram(); 
  glAttachShader(values.shader, values.vertexShader);
  glAttachShader(values.shader, values.fragmentShader);
  glLinkProgram(values.shader);

  error_handle(values.shader, "PROGRAM");
}

void shader::compiling(std::string vertex, std::string fragment) {
  std::string vssource = shader::readGLSL(vertex);
  const char *VSsource = reinterpret_cast<const char *>(vssource.c_str());
  std::cout << "\tSHADERS\n" << "\t-------" << std::endl;
  std::cout << "VERTEX SHADER: " << vertex << "\n" << VSsource;

  std::string fssource = shader::readGLSL(fragment);
  const char *FSsource = reinterpret_cast<const char *>(fssource.c_str());
  std::cout << "FRAGMENT SHADER: " << fragment << "\n" << FSsource;
  std::cout << "\t-------" << std::endl;

  // -- VERTEX
  values.vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(
      values.vertexShader, 
      1,
      &VSsource,
      NULL
      );
  glCompileShader((GLuint)values.vertexShader); 
  error_handle(values.vertexShader, "VERTEX"); // breaks here // does not 
  // -- FRAGMENT
  values.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(
      values.fragmentShader,
      1, 
      &FSsource,
      NULL
      );
  glCompileShader((GLuint)values.fragmentShader);
  error_handle(values.fragmentShader, "FRAGMENT");
}

std::string shader::readGLSL(std::string f) {
  std::ifstream filename(f);
  std::vector<std::string> output;

  if (!filename.is_open()) {
    std::cerr << "there was an error while opening shader\n";
    return "\0";
  }

  std::string contents((std::istreambuf_iterator<char>(filename)), std::istreambuf_iterator<char>());

  return contents;
}

void shader::error_handle(u32 shader, std::string type) {
  if (type != "PROGRAM") {
    glGetShaderiv(
        shader, 
        GL_COMPILE_STATUS, 
        &info->success);
    if (info->success == GL_FALSE) {
        glGetShaderInfoLog(
            shader, 
            1024, 
            NULL, 
            info->logs.data()
            );
        std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " 
          << type << "\n" << info->logs.data();
    } 
  }
  else {
    glGetProgramiv(
        shader, 
        GL_LINK_STATUS,
        &info->success
        );
    if (info->success == GL_FALSE) {
      glGetProgramInfoLog(
          shader, 
          1024, 
          NULL,
          info->logs.data()
          );
      std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " 
        << type << "\n" << info->logs.data();
    }
  }
}

void shader::cleans() {
  glDeleteProgram(values.shader);
}
