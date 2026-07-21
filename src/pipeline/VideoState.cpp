#include "VideoState.h"

VideoState::VideoState() {
  if (VideoState::grid() != 0) {
    std::cerr << "fuck\n";
  }
}

std::vector<Vertex> vertices = {
  glm::vec3(0.0f, 1.0f, 0.0f),
  glm::vec3(1.0f, 0.0f, 0.0f),
  glm::vec3(-1.0f, -1.0f, 0.0f),
  glm::vec3(0.0f, 1.0f, 0.0f),
  glm::vec3(1.0f, -1.0f, 0.0f),
  glm::vec3(0.0f, 0.0f, 1.0f)
};

auto VideoState::grid() -> int {
  glGenVertexArrays(1, &bfs.VAO_vertices);
  glGenBuffers(1, &bfs.VBO_vertices);
  glBindVertexArray(bfs.VAO_vertices);
  // shit begins
  glBindBuffer(GL_ARRAY_BUFFER, bfs.VBO_vertices);
  glBufferData(
      GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), 
      &vertices[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0); // pos
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec3), (void*)0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(glm::vec3), (void*)(sizeof(glm::vec3)));

  return 0;
}

void VideoState::bindsVAO() {
  glBindVertexArray(bfs.VAO_vertices);
  return;
}

void VideoState::bindsEBO() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bfs.EBO);
  return;
}

void VideoState::bindsBUFFER() {
  glBindBuffer(GL_ARRAY_BUFFER, bfs.VBO_vertices);
}
/*
auto VideoState::indic(Cell& logic) -> int {
  return sizeof(logic.indices);
}
*/
void VideoState::cleans() {
  glDeleteBuffers(1, &bfs.VAO_vertices);
  glDeleteBuffers(1, &bfs.VBO_vertices);
  glDeleteBuffers(1, &bfs.EBO);
}

