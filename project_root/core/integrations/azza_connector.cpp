#include "azza_connector.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

StoryJob AzzaConnector::loadJob(const std::string& filePath) {
    StoryJob job;

    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open JSON job file\n";
        return job;
    }

    json data;
    file >> data;

    job.title = data["title"];

    for (auto& s : data["scenes"]) {
        SceneData scene;
        scene.id = s["id"];
        scene.name = s["name"];
        scene.description = s["description"];

        job.scenes.push_back(scene);
    }

    return job;
}