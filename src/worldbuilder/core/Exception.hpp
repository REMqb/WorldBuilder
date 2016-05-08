#pragma once

#include <exception>
#include <string>

namespace wb::core{
    class Exception : public std::exception
    {
        public:
            Exception(const std::string& function, const std::string& file, size_t line);

            virtual ~Exception() = 0;

        private:
            const std::string function;
            const std::string file;
            const size_t line;
    };
}
