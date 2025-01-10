#include "scene_manager.h"
#include <iostream>

void SceneManager::addScene(const Scene& scene) {
    scenes.push_back(scene);
}

const Scene& SceneManager::getCurrentScene() const {
    return scenes[currentSceneIndex];
}

void SceneManager::switchToScene(const std::string& name) {
    for (size_t i = 0; i < scenes.size(); ++i) {
        if (scenes[i].getName() == name) {
            currentSceneIndex = i;
            break;
        }
    }
}

void SceneManager::renderCurrentScene() const {
    std::cout << "Rendering scene: " << getCurrentScene().getName() << std::endl;
}