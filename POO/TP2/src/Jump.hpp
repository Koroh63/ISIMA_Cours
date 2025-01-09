#ifndef JUMP_HPP
#define JUMP_HPP

#include <chrono>
#include "Step.hpp"

class Jump {
private:
    std::chrono::minutes duration;
    Step startStep;
    Step endStep;

public:
    Jump(const std::chrono::minutes& duration, const Step& startStep, const Step& endStep);
    bool Shift(long duration);
};

#endif // JUMP_HPP
