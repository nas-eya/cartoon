#ifndef STORY_PROCESSOR_H
#define STORY_PROCESSOR_H

#include <string>
#include <vector>

class StoryProcessor {
public:
    StoryProcessor(const std::string& storyFile);
    std::vector<std::string> processStory();

private:
    std::string storyFile;
};

#endif // STORY_PROCESSOR_H