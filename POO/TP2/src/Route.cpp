#include "Route.hpp"

Route::Route(const std::chrono::minutes& duration) : duration(duration) {}

std::chrono::minutes Route::getDuration() const {
    return duration;
}

void Route::setDuration(const std::chrono::minutes& duration) {
    this->duration = duration;
}
