#ifndef STOPWATCH_H
#define STOPWATCH_H
#include "Time.h"

class Stopwatch {
    private:
        Time currentTime;
        bool running;
        int lapCount; // initially  0
    public:
        Stopwatch();
        Stopwatch(int, int, int);
        Stopwatch(Time);
        Stopwatch(const Stopwatch&);
        ~Stopwatch();

        Time getCurrentTime() const;
        bool isRunning() const;
        int getLapCount() const;

        void start();
        void stop();
        void reset();
        void incrementTime(int sec, int min, int h);
        void lap();
        void printStopwatch() const;
};

#endif // STOPWATCH_H