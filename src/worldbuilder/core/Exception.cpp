#include "Exception.hpp"

using wb::core::Exception;

Exception::Exception(const std::string& function, const std::string& file, size_t line) : function(function), file(file), line(line)
{

}

Exception::~Exception()
{

}
