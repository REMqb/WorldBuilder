#pragma once

namespace wb::core{
    /**
     * @brief Represent a resource, a pointer like data to OS alocated resource
     * Base for things like OpenGL texture, vertex buffer, ...
     * RAII (Alocate the resource on construction, free it on destruction)
     */
    class Resource
    {
        public:
            virtual ~Resource() = 0;
    };
}
