#include "Timer.h"
#include <iostream>

Timer::Timer() {
    countdownTime = Time();
    startTime = Time();
    running = false;
}
Timer::Timer(int sec, int min, int h) {
    countdownTime = Time(sec, min, h);
    startTime = Time();
    running = false;
}
Timer::Timer(Time t) {
    countdownTime = t;
    startTime = Time();
    running = false;
}
Timer::Timer(const Timer& t) {
    countdownTime = t.getCountdownTime();
    startTime = t.getStartTime();
    running = t.isRunning();
}
Timer::~Timer() {}

Time Timer::getCountdownTime() const {
    return countdownTime;
}
Time Timer::getStartTime() const {
    return startTime;
}
bool Timer::isRunning() const {
    return running;
}
Time Timer::getTimeRemaining(const Time& currentTime) const {
    if (!running) {
        return countdownTime;
    }
    Time elapsed = currentTime - startTime;
    return countdownTime - elapsed;
}

void Timer::start(const Time& currentTime) {
    running = true;
    startTime = currentTime;
}
void Timer::stop() {
    running = false;
}
void Timer::reset() {
    countdownTime.setTime(0, 0, 0);
    if (running) {
        stop();
    }
}
void Timer::decrementTime(int sec, int min, int h) {
    countdownTime.incrementTime(-sec, -min, -h);
}

void Timer::printTimer(const Time& currentTime) const {
    std::cout << "Timer: ";
    countdownTime.printTime();
    std::cout << "Remaining Time: ";
    getTimeRemaining(currentTime).printTime();
    std::cout << "Running: " << (isRunning() ? "Yes" : "No") << std::endl;
}