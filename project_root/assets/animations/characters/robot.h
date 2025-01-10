#ifndef ROBOT_H
#define ROBOT_H

#include "character.h"

class RobotCharacter : public Character {
public:
    void run() override {
        std::cout << "Robot is running..." << std::endl;
    }
    void jump() override {
        std::cout << "Robot is jumping..." << std::endl;
    }
    void talk() override {
        std::cout << "Robot is talking..." << std::endl;
    }
};

#endif // ROBOT_H