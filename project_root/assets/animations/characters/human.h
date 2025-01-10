#ifndef HUMAN_CHARACTER_H
#define HUMAN_CHARACTER_H

#include "character.h"

/// @brief 
class Human : public Character {
public:
    void run() override {
        std::cout << "Human is running..." << std::endl;
    }
    void jump() override {
        std::cout << "Human is jumping..." << std::endl;
    }
    void talk() override {
        std::cout << "Human is talking..." << std::endl;
    }
};

#endif // HUMAN_H