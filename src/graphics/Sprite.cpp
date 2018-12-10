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

#include "Sprite.hpp"

namespace fs::graphics
{
void Sprite::create(core::Recti rect, const Texture& texture, const VkDescriptorSet& descriptorSet)
{
    Sprite::rect = rect;
    Sprite::texture = &texture;
    Sprite::descriptorSet = descriptorSet;

    createMesh();
}

void Sprite::createMesh()
{
    widthUnits = static_cast<core::fs_float32>(rect.width) / texture->getPixelsPerUnit();
    auto halfWidth = widthUnits / 2.f;
    heightUnits = static_cast<core::fs_float32>(rect.height) / texture->getPixelsPerUnit();
    auto halfHeight = heightUnits / 2.f;

    core::Rectf textureRect{};
    textureRect.x = static_cast<core::fs_float32>(rect.x) / texture->getWidthPixels();
    textureRect.y = static_cast<core::fs_float32>(rect.y) / texture->getHeightPixels();
    textureRect.width = static_cast<core::fs_float32>(rect.width) / texture->getWidthPixels();
    textureRect.height = static_cast<core::fs_float32>(rect.height) / texture->getHeightPixels();

    std::vector<Vertex> vertices;
    vertices.push_back({
                           {-halfWidth,    -halfHeight, 0.f},
                           {1.0f,          0.0f,        0.0f},
                           {textureRect.x, textureRect.y}
                       });
    vertices.push_back({
                           {halfWidth,                         -halfHeight, 0.f},
                           {0.0f,                              1.0f,        0.0f},
                           {textureRect.x + textureRect.width, textureRect.y}
                       });
    vertices.push_back({
                           {halfWidth,                         halfHeight, 0.f},
                           {0.0f,                              0.0f,       1.0f},
                           {textureRect.x + textureRect.width, textureRect.y + textureRect.height}
                       });
    vertices.push_back({
                           {-halfWidth,    halfHeight, 0.f},
                           {1.0f,          1.0f,       1.0f},
                           {textureRect.x, textureRect.y + textureRect.height}
                       });

    const std::vector<core::fs_uint32> indices{0, 1, 2, 2, 3, 0};

    mesh.create(vertices, indices);
}

void Sprite::destroy()
{
    destroyMesh();

    texture = nullptr;
    descriptorSet = VK_NULL_HANDLE;
}

void Sprite::destroyMesh()
{
    mesh.destroy();
}

const VkDescriptorSet Sprite::getDescriptorSet() const
{
    return descriptorSet;
}

const Texture* Sprite::getTexture() const
{
    return texture;
}

Mesh& Sprite::getMesh()
{
    return mesh;
}

const Mesh& Sprite::getMesh() const
{
    return mesh;
}

core::fs_float32 Sprite::getWidthUnits() const
{
    return widthUnits;
}

core::fs_float32 Sprite::getHeightUnits() const
{
    return heightUnits;
}
}
