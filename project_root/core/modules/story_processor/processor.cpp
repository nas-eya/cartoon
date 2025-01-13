#include "story_processor.h"
#include <fstream>
#include <iostream>

StoryProcessor::StoryProcessor(const std::string& storyFile) : storyFile(storyFile) {}

std::vector<std::string> StoryProcessor::processStory() {
    std::vector<std::string> scenes;
    std::ifstream file(storyFile);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            scenes.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open story file: " << storyFile << std::endl;
    }
    return scenes;
}