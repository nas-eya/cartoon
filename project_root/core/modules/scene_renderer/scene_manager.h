#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <vector>
#include <string>
#include <iostream>

class SceneManager {
public:
    void addScene(const Scene& scene);
    const Scene& getCurrentScene() const;
    void switchToScene(const std::string& name);
    void renderCurrentScene() const;

    void createScene(const std::string& sceneName) {
        std::cout << "Creating scene: " << sceneName << std::endl;
        scenes.push_back(Scene(sceneName));
    }

private:
    std::vector<Scene> scenes;
    int currentSceneIndex = 0;
};

#endif // SCENE_MANAGER_H