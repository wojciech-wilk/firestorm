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

#include "RendererComponent.hpp"

namespace fs::scene
{

void RendererComponent::create(SceneNode& sceneNode, TransformationComponent& transformation)
{
    Component::create(sceneNode);
    RendererComponent::transformation = &transformation;
    active = true;
}

void RendererComponent::destroy()
{
    active = false;
    transformation = nullptr;
    Component::destroy();
}

void RendererComponent::pushTransform(VkCommandBuffer commandBuffer, VkPipelineLayout pipelineLayout)
{
    if (transformation->isTransformUpdated())
    {
        transformation->updateTransform();
    }

    vkCmdPushConstants(commandBuffer, pipelineLayout, VK_SHADER_STAGE_VERTEX_BIT, 0, sizeof(graphics::Transform),
                       &transformation->getTransform());
}

bool RendererComponent::isActive() const
{
    return active;
}

void RendererComponent::setActive(bool active)
{
    RendererComponent::active = active;
}

}
