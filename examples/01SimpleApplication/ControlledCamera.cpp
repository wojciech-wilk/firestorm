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

#include <iostream>
#include "ControlledCamera.hpp"

namespace fs
{

void ControlledCamera::create(io::InputManager& inputManager, const graphics::Window& window,
                              const graphics::MappedMemoryBuffer& uniformBuffer)
{
    CameraSceneNode::create(inputManager, window, uniformBuffer);
}

void ControlledCamera::destroy()
{
    CameraSceneNode::destroy();
}

void ControlledCamera::update(float deltaTime)
{
    float cameraOffset = cameraSpeed * deltaTime;

    core::Vector2f position = transformation->getPosition();
    if (inputManager->getKeyState(io::Key::Up) == io::KeyState::Pressed)
    {
        position.y += cameraOffset;
    }
    else if (inputManager->getKeyState(io::Key::Down) == io::KeyState::Pressed)
    {
        position.y -= cameraOffset;
    }
    if (inputManager->getKeyState(io::Key::Right) == io::KeyState::Pressed)
    {
        position.x += cameraOffset;
    }
    else if (inputManager->getKeyState(io::Key::Left) == io::KeyState::Pressed)
    {
        position.x -= cameraOffset;
    }
    if (transformation->getPosition() != position)
    {
        transformation->setPosition(position);
    }

    if (inputManager->getButtonState(io::Button::Left) == io::KeyState::Pressed)
    {
        setZoom(getZoom() + cameraOffset);
    }
    else if (inputManager->getButtonState(io::Button::Right) == io::KeyState::Pressed)
    {
        setZoom(getZoom() - cameraOffset);
    }

    CameraSceneNode::update(deltaTime);
}
}
