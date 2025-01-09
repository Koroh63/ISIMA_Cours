#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <chrono>

class Route {
private:
    std::chrono::minutes duration;

public:
    Route(const std::chrono::minutes& duration);
    std::chrono::minutes getDuration() const;
    void setDuration(const std::chrono::minutes& duration);
};

#endif // ROUTE_HPP
