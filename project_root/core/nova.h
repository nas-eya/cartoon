// nova.h
#ifndef NOVA_H
#define NOVA_H

#include <string>
#include <iostream>

class Nova {
public:
    Nova(const std::string& name) : name(name) {}

    void respondToScene(const std::string& sceneName) {
        std::cout << name << " is observing the scene: " << sceneName << std::endl;
    }

    void observeScene(const std::string& sceneName) {
        std::cout << name << " is observing the scene: " << sceneName << std::endl;
    }

private:
    std::string name;
};

#endif // NOVA_H
