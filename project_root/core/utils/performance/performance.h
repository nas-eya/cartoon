#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <chrono>

class Performance {
public:
    static void measureExecutionTime(void (*func)());
};

#endif // PERFORMANCE_H
