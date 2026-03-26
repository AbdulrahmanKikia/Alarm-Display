#include "Stopwatch.h"
#include <iostream>

Stopwatch::Stopwatch() {
    currentTime = Time();
    running = false;
    lapCount = 0;
}
Stopwatch::Stopwatch(Time t) {
    currentTime = t;
    running = false;
    lapCount = 0;
}
Stopwatch::Stopwatch(int sec, int min, int h) {
    currentTime = Time(sec, min, h);
    running = false;
    lapCount = 0;
}
Stopwatch::Stopwatch(const Stopwatch& s) {
    currentTime = s.getCurrentTime();
    running = s.isRunning();
    lapCount = s.getLapCount();
}
Stopwatch::~Stopwatch() {}

Time Stopwatch::getCurrentTime() const {
    return currentTime;
}
bool Stopwatch::isRunning() const {
    return running;
}
int Stopwatch::getLapCount() const {
    return lapCount;
}

void Stopwatch::start() {
    running = true;
}
void Stopwatch::stop() {
    running = false;
}
void Stopwatch::reset() {
    currentTime.setTime(0, 0, 0);
    lapCount = 0;
    if (running) {
        stop();
    }
}
void Stopwatch::incrementTime(int sec, int min, int h) {
    currentTime.incrementTime(sec, min, h);
}
void Stopwatch::lap() {
    if (running) {
        lapCount++;
    }
}
void Stopwatch::printStopwatch() const {
    std::cout << "Current Time: ";
    currentTime.printTime();
    std::cout << "Running: " << (isRunning() ? "Yes" : "No") << std::endl;
    std::cout << "Lap Count: " << getLapCount() << std::endl;
}