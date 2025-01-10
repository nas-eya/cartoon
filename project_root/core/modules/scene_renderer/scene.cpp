#include "scene.h"

Scene::Scene(const std::string& name, const std::string& description)
    : name(name), description(description) {}

std::string Scene::getName() const {
    return name;
}