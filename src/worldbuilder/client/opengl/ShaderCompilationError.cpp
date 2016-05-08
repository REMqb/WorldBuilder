#include "ShaderCompilationError.hpp"

#undef ShaderCompilationError

using wb::client::opengl::ShaderCompilationError;

ShaderCompilationError::ShaderCompilationError(const std::string& message, const std::string& function, const std::string& file, size_t line) : Exception(function, file, line)
{

}
