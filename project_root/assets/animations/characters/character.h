#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>  // For std::cout

class Character {
public:
    virtual void move() const = 0;  // Move does not modify state of object
};

class Robot : public Character {
public:
    void move() const override {
        std::cout << "Robot is running..." << std::endl;
    }
};

class Human : public Character {
public:
    void move() const override {
        std::cout << "Human is running..." << std::endl;
    }
};

#endif
