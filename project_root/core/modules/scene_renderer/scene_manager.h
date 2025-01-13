#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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

    void saveCurrentSceneAsImage(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "P3\n" << 100 << " " << 100 << "\n255\n";
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 100; ++j) {
                    file << 255 << " " << 0 << " " << 0 << "\n"; // Red color
                }
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

private:
    std::vector<Scene> scenes;
    int currentSceneIndex = 0;
};

#endif // SCENE_MANAGER_H