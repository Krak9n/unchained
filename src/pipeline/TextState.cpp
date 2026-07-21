#include "TextState.h"

TextState::TextState() {
  if (buffers() == -1) {
    std::cerr << "couldn't initialize arrays and/or buffers\naborting\n";
    exit(1);
  }
}

int TextState::buffers() {
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

void TextState::bindsVAO() {
  glBindVertexArray(bfs.VAOtext);
  return;
}

void TextState::bindsBUFFER() {
  glBindBuffer(GL_ARRAY_BUFFER, bfs.VBO_text);
}

void TextState::cleans() {
  glDeleteBuffers(1, &bfs.VBO_text);
}
