#ifndef VIDEO_GENERATOR_H
#define VIDEO_GENERATOR_H

#include <string>

class VideoGenerator {
public:
    VideoGenerator(const std::string& outputVideo, int frameRate = 1);
    void saveFrame(const std::string& filename);
    void generateVideo();

private:
    std::string outputVideo;
    int frameRate;
    int frameCount;
};

#endif // VIDEO_GENERATOR_H