#include "Texture.hpp"

using wb::client::opengl::Texture;
using namespace gl33core;

Texture::Texture(){
    glGenTextures(1, &texture);
}

Texture::Texture(Texture&& move){
    std::swap(texture, move.texture);
}

Texture::~Texture(){
    glDeleteTextures(1, &texture);
    texture = 0;
}
