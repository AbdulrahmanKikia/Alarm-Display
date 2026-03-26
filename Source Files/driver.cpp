// Test Time Class
#include "Time.h"
#include <iostream>

int main() {
    Time t1; // default
    Time t2(30, 15, 9); // 9:15:30

    std::cout << "t1 (default): ";
    t1.printTime();

    std::cout << "t2: ";
    t2.printTime();

    t1.setTime(45, 59, 23);
    std::cout << "t1 after setTime(45,59,23): ";
    t1.printTime();

    t1.setTimeFormat24(false);
    std::cout << "t1 in 12-hour format: ";
    t1.printTime();

    t1.incrementSeconds(30);
    std::cout << "t1 after incrementSeconds(30): ";
    t1.printTime();

    Time diff = t1.timeDifference(t2);
    std::cout << "Difference between t1 and t2: ";
    diff.printTime();

    t1.printTimeInSeconds();
    t1.printTimeInMinutes();
    t1.printTimeInHours();
    t1.printTimeInDays();

    return 0;
}

