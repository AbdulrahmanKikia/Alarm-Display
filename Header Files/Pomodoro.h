#ifndef POMODORO_H
#define POMODORO_H

#include "Timer.h"

class Pomodoro {
    private:
        Timer workTimer; // 25/5 minute work/break timers by default
        Timer breakTimer;
        int cycles; // Number of completed work/break cycles
    public:
        Pomodoro();
        Pomodoro(int workSec, int workMin, int workH, int breakSec, int breakMin, int breakH);
        Pomodoro(const Pomodoro&);
        ~Pomodoro();

        Timer getWorkTimer() const;
        Timer getBreakTimer() const;
        int getCycles() const;

        void startWork(const Time&);
        void startBreak(const Time&);
        void incrementCycles();
        void reset();

        void printPomodoro(const Time&) const;
};

#endif // POMODORO_H