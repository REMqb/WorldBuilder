#include "ShaderProgram.hpp"

#include <memory>

#include "ShaderCompilationError.hpp"
#include "ProgramLinkError.hpp"

using wb::client::opengl::ShaderProgram;
using namespace gl33core;

ShaderProgram::ShaderProgram(){
    program = glCreateProgram();

    Shader vertexShader(GL_VERTEX_SHADER, "");
    Shader fragmentShader(GL_FRAGMENT_SHADER, "");

    glAttachShader(program, vertexShader.shader);
    glAttachShader(program, fragmentShader.shader);

    glLinkProgram(program);

    GLint result;

    glGetProgramiv(program, GL_COMPILE_STATUS, &result);
    if(!result)
    {
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &result);

        std::unique_ptr<GLchar[]> infoLog = std::make_unique<GLchar[]>(static_cast<size_t>(result));

        glGetProgramInfoLog(program, result, NULL, infoLog.get());

        throw ProgramLinkError(infoLog.get());
    }
}

ShaderProgram::ShaderProgram(ShaderProgram&& move){
    std::swap(program, move.program);
}

ShaderProgram::~ShaderProgram(){
    glDeleteProgram(program);
    program = 0;
}

ShaderProgram::Shader::Shader(gl33core::GLenum type, const std::string& source){
    shader = glCreateShader(type);

    const GLchar* shaderCode = source.c_str();

    glShaderSource(shader, 1, &shaderCode, nullptr);
    glCompileShader(shader);

    GLint result;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if(!result)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &result);

        std::unique_ptr<GLchar[]> infoLog = std::make_unique<GLchar[]>(static_cast<size_t>(result));

        glGetShaderInfoLog(shader, result, NULL, infoLog.get());

        throw ShaderCompilationError(infoLog.get());
    }
}

ShaderProgram::Shader::Shader(ShaderProgram::Shader&& move){
    std::swap(shader, move.shader);
}

ShaderProgram::Shader::~Shader(){
    glDeleteShader(shader);
    shader = 0;
}
