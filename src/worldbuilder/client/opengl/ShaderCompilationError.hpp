#pragma once

#include "../../core/Exception.hpp"

namespace wb::client::opengl{

    class ShaderCompilationError : public core::Exception
    {
        public:
            ShaderCompilationError(const std::string& message, const std::string& function, const std::string& file, size_t line);
    };

}

//Macro allowing to throw without having to specify manualy function, file and line parameters
#define ShaderCompilationError(message) ShaderCompilationError(message, __PRETTY_FUNCTION__, __FILE__, __LINE__)
