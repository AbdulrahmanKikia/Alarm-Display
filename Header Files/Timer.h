#ifndef TIMER_H
#define TIMER_H

#include "Time.h"

class Timer {
    private:
        Time startTime; // The time when the timer was started
        Time countdownTime;
        bool running;
    public:
        Timer();
        Timer(int, int, int);
        Timer(Time);
        Timer(const Timer&);
        ~Timer();

        Time getCountdownTime() const;
        Time getStartTime() const;
        bool isRunning() const;
        Time getTimeRemaining(const Time&) const;

        void start(const Time&);
        void stop();
        void reset();
        void decrementTime(int sec, int min, int h);

        void printTimer(const Time&) const;
};
#endif // TIMER_H