#version 460 core

// blur has to run on top of the 
// left top blocks. so blurring them.
// and after that having text rendered 
// above it.

out vec4 blur;

uniform float sampleDistance = 200.0;

void main() {
  mat3 kernel = mat3(
      1, 2, 1,
      2, 4, 2,
      1, 2, 1);
  for (unsigned int i = 0; i < 9; ++i) {
    kernel[i] /= 16;
  }
  float s = 1.0 / sampleDistance;
  vec2 offsets[9];
  //               x y
  offsets[0] = vec2(-s, -s);
  offsets[1] = vec2(0, -s);
  offsets[2] = vec2(s, -s);
  offsets[3] = vec2(-s, 0);
  offsets[4] = vec2(0, 0);
  offsets[5] = vec2(s, 0);
  offsets[6] = vec2(-s, s);
  offsets[7] = vec2(0, s);
  offsets[8] = vec2(s, s);

  vec3 results = vec3(0.0);
  for (unsigned int i = 0; i < 9; ++i) {
    results += texture(textureUnit, texCoord + offsets[i]).rgb * kernel[i];
  }
  blur 
}
