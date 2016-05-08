#include "VertexBuffer.hpp"

using wb::client::opengl::VertexBuffer;
using namespace gl33core;

VertexBuffer::VertexBuffer(){
    glGenBuffers(1, &vertexBuffer);
}

VertexBuffer::VertexBuffer(VertexBuffer&& move){
    std::swap(vertexBuffer, move.vertexBuffer);
}

VertexBuffer::~VertexBuffer(){
    glGenBuffers(1, &vertexBuffer);
    vertexBuffer = 0;
}
