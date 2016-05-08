#pragma once

#include <glbinding/gl33core/gl.h>

#include "../../core/Resource.hpp"

namespace wb::client::opengl{

    class Texture : public core::Resource
    {
        public:
            Texture();
            Texture(Texture&& move);

            ~Texture();

        private:
            gl33core::GLuint texture;
    };

}
