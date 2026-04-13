#pragma once
#include <string>
#include <vector>

struct SceneData {
    int id;
    std::string name;
    std::string description;
};

struct StoryJob {
    std::string title;
    std::vector<SceneData> scenes;
};

class AzzaConnector {
public:
    StoryJob loadJob(const std::string& filePath);
};