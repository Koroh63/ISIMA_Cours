#include "Jump.hpp"

Jump::Jump(const std::chrono::minutes& duration, const Step& startStep, const Step& endStep)
    : duration(duration), startStep(startStep), endStep(endStep) {}

bool Jump::Shift(long duration) {
    this->duration += std::chrono::minutes(duration);
    startStep.setDepartureTime(startStep.getDepartureTime() + std::chrono::minutes(duration));
    endStep.setArrivalTime(endStep.getArrivalTime() + std::chrono::minutes(duration));
    return true;
}
