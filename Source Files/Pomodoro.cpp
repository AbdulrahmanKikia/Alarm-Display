#include "Pomodoro.h"
#include <iostream>

Pomodoro::Pomodoro() {
    workTimer = Timer(0, 25, 0); // Default 25 minutes
    breakTimer = Timer(0, 5, 0); // Default 5 minutes
    cycles = 0;
}
Pomodoro::Pomodoro(int workSec, int workMin, int workH, int breakSec, int breakMin, int breakH) {
    workTimer = Timer(workSec, workMin, workH);
    breakTimer = Timer(breakSec, breakMin, breakH);
    cycles = 0;
}
Pomodoro::Pomodoro(const Pomodoro& p) {
    workTimer = p.getWorkTimer();
    breakTimer = p.getBreakTimer();
    cycles = p.getCycles();
}
Pomodoro::~Pomodoro() {}

Timer Pomodoro::getWorkTimer() const {
    return workTimer;
}
Timer Pomodoro::getBreakTimer() const {
    return breakTimer;
}
int Pomodoro::getCycles() const {
    return cycles;
}

void Pomodoro::startWork(const Time& currentTime) {
    workTimer.start(currentTime);
}
void Pomodoro::startBreak(const Time& currentTime) {
    breakTimer.start(currentTime);
}
void Pomodoro::incrementCycles() {
    cycles++;
}
void Pomodoro::reset() {
    workTimer.reset();
    breakTimer.reset();
    cycles = 0;
}

void Pomodoro::printPomodoro(const Time& currentTime) const {
    std::cout << "Pomodoro Status:" << std::endl;
    std::cout << "Work Timer: ";
    workTimer.printTimer(currentTime);
    std::cout << "Break Timer: ";
    breakTimer.printTimer(currentTime);
    std::cout << "Completed Cycles: " << getCycles() << std::endl;
}