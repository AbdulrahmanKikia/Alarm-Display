#ifndef TIMER_H
#define TIMER_H

#include "Time.h"

class Timer {
    private:
        Time countdownTime;
        bool running;
    public:
        Timer();
        Timer(int, int, int);
        Timer(Time);
        Timer(const Timer&);
        ~Timer();

        Time getCountdownTime() const;
        bool isRunning() const;
        Time getTimeRemaining() const;

        void start();
        void stop();
        void reset();
        void decrementTime(int sec, int min, int h);

        void printTimer() const;
};
#endif // TIMER_H