#pragma once

#include "types.hpp"

namespace wb::core{

    class World
    {
        public:
            World();

            void getBlockAt(i64 x, i64 y, i64 z);

            virtual ~World();

        private:

            virtual void doGetBlockAt(i64 x, i64 y, i64 z);
    };

}
