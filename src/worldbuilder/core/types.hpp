#pragma once

#include <ctype.h>

namespace wb {
    using i8 = signed char;
    using ui8 = unsigned char;

    using i16 = short;
    using ui16 = unsigned short;

    using i32 = int;
    using ui32 = unsigned int;

    using i64 = long long int;
    using ui64 = unsigned long long int;

    using f32 = float;
    using f64 = double;
}

static_assert(sizeof(wb::i8) == 1, "int8 size should be 1 bytes");
static_assert(sizeof(wb::i16) == 2, "int16 size should be 2 bytes");
static_assert(sizeof(wb::i32) == 4, "int32 size should be 4 bytes");
static_assert(sizeof(wb::i64) == 8, "int64 size should be 8 bytes");

static_assert(sizeof(wb::ui8) == 1, "uint8 size should be 1 bytes");
static_assert(sizeof(wb::ui16) == 2, "uint16 size should be 2 bytes");
static_assert(sizeof(wb::ui32) == 4, "uint32 size should be 4 bytes");
static_assert(sizeof(wb::ui64) == 8, "uint64 size should be 8 bytes");

static_assert(sizeof(wb::f32) == 4, "f32 size should be 4 bytes");
static_assert(sizeof(wb::f64) == 8, "f64 size should be 8 bytes");
