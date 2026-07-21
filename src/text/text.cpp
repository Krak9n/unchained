#include "text.h"

ft::ft() {
  if (ft::initialize("../contents/fonts/tight_pixel.ttf")) {
    std::cerr << "FONT ERROR\n";
  }

  if (ft::loop() == -1) {
    std::cout << "ERROR WITH THE LOOP\n";
  }

  FT_Done_Face(font.face);
  FT_Done_FreeType(font.ft);
}

int ft::initialize(std::string path) {
  if (FT_Init_FreeType(&font.ft)) {
    std::cerr << "ERROR FREETYPE: library couldnt be initialized" 
      << std::endl;
    return -1;
  }

  //const char*t = pat.c_str();
  //const unsigned char *path(reinterpret_cast<const unsigned char*>(t));
  if (FT_New_Face(font.ft, path.c_str(), 0, &font.face)) {
    std::cerr << "ERROR FREETYPE: couldnt create new face / failed to load font" 
      << std::endl;
    return -1;
  }

  // setting the width to 0 lets the face dynamically calculate the 
  // width based on the height
  FT_Set_Pixel_Sizes(font.face, w, h);
  // ft_load_render tells freetype to create an 8-bit grayscale 
  // image, that could be accessed via face->glyph->bitmap
  if (FT_Load_Char(font.face, 'f', FT_LOAD_RENDER)) {
    std::cerr << "ERROR: couldnt load glyph" << std::endl;
    return -1;
  } 

  return 0;
}

int ft::loop() {
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  // loop gets all 128 ascii characters
  // and retrieves their corresponding glyphs.
  //
  for (unsigned char c = 0; c < 128; ++c) {
    if (FT_Load_Char(font.face, c, FT_LOAD_RENDER)) {
      std::cout << "ERROR: couldnt load glyph" << std::endl;
      return -1;
    }

    uint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RED,
        font.face->glyph->bitmap.width,
        font.face->glyph->bitmap.rows,
        0,
        GL_RED,
        GL_UNSIGNED_BYTE,
        font.face->glyph->bitmap.buffer
        );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    Character ch = {
      texture,
      glm::ivec2(font.face->glyph->bitmap.width, font.face->glyph->bitmap.rows),
      glm::ivec2(font.face->glyph->bitmap_left, font.face->glyph->bitmap_top),
      (uint)font.face->glyph->advance.x
    };

    Characters.insert(std::pair<char, Character>(c, ch));
  }
  glBindTexture(GL_TEXTURE_2D, 0);
  return 0;
}

void ft::render(
    shader SHADER, 
    TextState render, 
    glm::vec3 color,
    std::string text,
    float x, 
    float y,
    float scale
    ) {
  SHADER.use();
  glUniform3f(
      SHADER.uniformLocation("textColor"), 
      color.x, 
      color.y, 
      color.z
      );
  glActiveTexture(GL_TEXTURE0);
  render.bindsVAO();

  std::string::const_iterator c;
  for (c = text.begin(); c != text.end(); ++c) {
    Character ch = Characters[*c]; 

    float xpos = x + ch.Bearing.x * scale;
    float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

    float w = ch.Size.x * scale;
    float h = ch.Size.y * scale;
    // vbo update
    float vertices[6][4] = {
      { xpos,     ypos + h,   0.0f, 0.0f },            
      { xpos,     ypos,       0.0f, 1.0f },
      { xpos + w, ypos,       1.0f, 1.0f },

      { xpos,     ypos + h,   0.0f, 0.0f },
      { xpos + w, ypos,       1.0f, 1.0f },
      { xpos + w, ypos + h,   1.0f, 0.0f }           
    };
    glBindTexture(GL_TEXTURE_2D, ch.TextureID);
    render.bindsBUFFER();
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    x += (ch.Advance >> 6) * scale;

  }
  glBindVertexArray(0);
  glBindTexture(GL_TEXTURE_2D, 0);

  return;
}
