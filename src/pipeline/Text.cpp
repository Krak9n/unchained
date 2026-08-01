#include "Text.h"

Text::Text() {
  if (buffers() == -1) {
    std::cerr << "Couldn't initialize arrays and/or buffers! Aborting!\n";
    exit(1);
  }
}

int Text::buffers() {
  glGenVertexArrays(1, &bfs.VAOtext);
  glGenBuffers(1, &bfs.VBO_text);

  glBindVertexArray(bfs.VAOtext);
  glBindBuffer(GL_ARRAY_BUFFER, bfs.VBO_text);

  glBufferData(
      GL_ARRAY_BUFFER, 
      sizeof(float) * 6 * 4,
      NULL, 
      GL_DYNAMIC_DRAW
      );
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(
      0, 
      4,
      GL_FLOAT, 
      GL_FALSE, 
      4 * sizeof(float), 
      0);
  // unbinding vao and vbo
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  return 0;
}

void Text::bindsVAO() {
  glBindVertexArray(bfs.VAOtext);
  return;
}

void Text::bindsBUFFER() {
  glBindBuffer(GL_ARRAY_BUFFER, bfs.VBO_text);
}

void Text::cleans() {
  glDeleteBuffers(1, &bfs.VBO_text);
}
