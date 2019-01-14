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

#ifndef FIRESTORM_SCENE_HPP
#define FIRESTORM_SCENE_HPP

#include "SceneNode.hpp"
#include "CameraSceneNode.hpp"

#include <memory>

namespace fs::scene
{
class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;

    void create();
    virtual void destroy();

    void update(float deltaTime);
    void physicsUpdate();
    void render(VkCommandBuffer commandBuffer, VkPipelineLayout pipelineLayout, VkDescriptorSet sceneDescriptorSet);
    void applyPhysicsStep();

    const std::vector<SceneNode*>& getNodes() const;
    std::vector<SceneNode*>& getNodes();

    void addSceneNode(SceneNode& sceneNode);
    void removeSceneNode(SceneNode& sceneNode);

    CameraSceneNode* getActiveCamera();
    void setActiveCamera(CameraSceneNode* activeCamera);

    bool isTransformUpdated() const;

protected:
    std::string name;
    std::vector<SceneNode*> nodes;
    CameraSceneNode* activeCamera = nullptr;
    bool nodesModified = true;

};

typedef std::unique_ptr<Scene> ScenePtr;
}

#endif //FIRESTORM_SCENE_HPP
