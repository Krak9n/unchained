#version 460 core
in vec2 TextCoords;
out vec4 colors;

uniform sampler2D text;
uniform vec3 textColor;


void main() {
  // test
  vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TextCoords));
  colors = vec4(textColor, 1.0) * sampled;
}
