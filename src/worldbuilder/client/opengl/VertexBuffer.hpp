#pragma once

#include <glbinding/gl33core/gl.h>

#include "../../core/Resource.hpp"

namespace wb::client::opengl{

    class VertexBuffer : public core::Resource
    {
        public:
            VertexBuffer();
            VertexBuffer(VertexBuffer&& move);

            ~VertexBuffer();

        private:
            gl33core::GLuint vertexBuffer;
    };

}
