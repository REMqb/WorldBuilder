#pragma once

#include <glbinding/gl33core/gl.h>

#include "../../core/Resource.hpp"

namespace wb::client::opengl{

    class ShaderProgram : public core::Resource
    {
        public:
            ShaderProgram();
            ShaderProgram(ShaderProgram&& move);

            ~ShaderProgram();

        private:
            gl33core::GLuint program;

            class Shader : public core::Resource
            {
                    friend class ShaderProgram;
                public:
                    Shader(gl33core::GLenum type, const std::string& source);
                    Shader(Shader&& move);

                    ~Shader();

                private:
                    gl33core::GLuint shader;

            };
    };

}
