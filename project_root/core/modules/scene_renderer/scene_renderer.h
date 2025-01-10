#ifndef SCENE_RENDERER_H
#define SCENE_RENDERER_H

#include <string>
#include <iostream>

class SceneRenderer {
public:
    void renderScene(const std::string& sceneName) {
        std::cout << "Rendering scene: " << sceneName << std::endl;
    }
};

#endif // SCENE_RENDERER_H