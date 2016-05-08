#include "ProgramLinkError.hpp"

#undef ProgramLinkError

using wb::client::opengl::ProgramLinkError;

ProgramLinkError::ProgramLinkError(const std::string& message, const std::string& function, const std::string& file, size_t line) : Exception(function, file, line)
{

}
