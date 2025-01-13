#include "../assets/animations/characters/robot.h"
#include "../assets/animations/characters/human.h"
#include "../core/modules/scene_renderer/scene_manager.h"
#include "../core/modules/scene_renderer/scene_renderer.h"
#include "../core/nova.h"
#include "../modules/video_generator/video_generator.h"
#include "../modules/story_processor/processor.h"
#include "../utils/performance/performance.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Performance::measureExecutionTime([]() {
        // Initialize Nova (the AI)
        Nova nova("Nova");

        // Initialize the characters
        Robot robot;
        Human human;

        // Initialize scene manager and video generator
        SceneManager sceneManager;
        SceneRenderer sceneRenderer;
        VideoGenerator videoGen("output.mp4");

        // Process the story to generate scenes
        StoryProcessor storyProcessor("story/dialogues/dialogue1.txt");
        std::vector<std::string> scenes = storyProcessor.processStory();

        // Create and render scenes
        for (const auto& sceneName : scenes) {
            sceneManager.createScene(sceneName);
            std::string frameFilename = "frame" + std::to_string(&sceneName - &scenes[0]) + ".ppm";
            sceneRenderer.renderScene(sceneName, frameFilename);
            videoGen.saveFrame(frameFilename);
            nova.observeScene(sceneName);
        }

        // Generate video from frames
        videoGen.generateVideo();
    });

    return 0;
}