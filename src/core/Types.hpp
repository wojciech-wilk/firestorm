// MIT License
//
// Copyright (c) 2018 Wojciech Wilk
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FIRESTORM_TYPES_HPP
#define FIRESTORM_TYPES_HPP

#include <cstdint>

namespace fs::core
{
using fs_uint8 = uint8_t;
using fs_int8 = int8_t;

using fs_uint16 = uint16_t;
using fs_int16 = int16_t;

using fs_uint32 = uint32_t;
using fs_int32 = int32_t;

using fs_uint64 = uint64_t;
using fs_int64 = int64_t;

struct Recti
{
    fs_uint64 x = 0;
    fs_uint64 y = 0;
    fs_uint64 width = 0;
    fs_uint64 height = 0;
};

struct Vector2i
{
    fs_uint64 x = 0ull;
    fs_uint64 y = 0ull;
};

struct Vector2f
{
    float x = 0.f;
    float y = 0.f;
};

struct Vector2d
{
    double x = 0.;
    double y = 0.;
};

}

#endif //FIRESTORM_TYPES_HPP