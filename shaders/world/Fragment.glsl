#version 460 core // fragment

in vec3 fragColor;
out vec4 Result;

void main() {
  Result = vec4(fragColor, 0.0);
}
