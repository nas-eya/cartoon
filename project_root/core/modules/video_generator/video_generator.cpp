#include "video_generator.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

VideoGenerator::VideoGenerator(const std::string& outputVideo, int frameRate)
    : outputVideo(outputVideo), frameRate(frameRate), frameCount(0) {}

void VideoGenerator::saveFrame(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "P3\n" << 100 << " " << 100 << "\n255\n";
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                file << 255 << " " << 0 << " " << 0 << "\n"; // Red color
            }
        }
        file.close();
        frameCount++;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

void VideoGenerator::generateVideo() {
    std::string command = "ffmpeg -framerate " + std::to_string(frameRate) + " -i frame%d.ppm " + outputVideo;
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error generating video" << std::endl;
    }
}