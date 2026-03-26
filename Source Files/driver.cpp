#include <iostream>
#include <cassert>
#include "Time.h"
#include "Timer.h"
#include "Alarm.h"
#include "Stopwatch.h"
#include "Pomodoro.h"

void testTime() {
    std::cout << "Testing Time class..." << std::endl;
    
    Time t1;
    assert(t1.getSeconds() == 0);
    assert(t1.getMinutes() == 0);
    assert(t1.getHours() == 0);
    
    Time t2(30, 45, 8);
    assert(t2.getSeconds() == 30);
    assert(t2.getMinutes() == 45);
    assert(t2.getHours() == 8);
    
    t2.incrementSeconds(35);
    assert(t2.getSeconds() == 5);
    assert(t2.getMinutes() == 46);
    
    Time t3(10, 20, 5);
    Time t4(5, 10, 3);
    Time diff = t3.timeDifference(t4);
    assert(diff.getTotalSeconds() > 0);
    
    std::cout << "Time class tests passed!" << std::endl;
}

void testAlarm() {
    std::cout << "Testing Alarm class..." << std::endl;
    
    Alarm alarm1;
    assert(!alarm1.getIsSet());
    
    Alarm alarm2(7, 30, 0);
    alarm2.setIsSet(true);
    assert(alarm2.getIsSet());
    assert(alarm2.getAlarmTime().getHours() == 7);
    assert(alarm2.getAlarmTime().getMinutes() == 30);
    
    alarm2.setReoccurring(true);
    assert(alarm2.getReoccurring());
    
    alarm2.snooze(5);
    assert(alarm2.getAlarmTime().getMinutes() == 35);
    assert(alarm2.getAlarmTime().getHours() == 7);
    
    std::cout << "Alarm class tests passed!" << std::endl;
}

void testTimer() {
    std::cout << "Testing Timer class..." << std::endl;
    
    Timer timer1;
    assert(!timer1.isRunning());
    
    Timer timer2(30, 5, 0);
    assert(timer2.getCountdownTime().getSeconds() == 30);
    assert(timer2.getCountdownTime().getMinutes() == 5);
    
    Time currentTime(0, 0, 8);
    timer2.start(currentTime);
    assert(timer2.isRunning());
    
    timer2.stop();
    assert(!timer2.isRunning());
    
    timer2.reset();
    assert(timer2.getCountdownTime().getTotalSeconds() == 0);
    
    std::cout << "Timer class tests passed!" << std::endl;
}

void testStopwatch() {
    std::cout << "Testing Stopwatch class..." << std::endl;
    
    Stopwatch sw1;
    assert(!sw1.isRunning());
    assert(sw1.getLapCount() == 0);
    
    Stopwatch sw2(15, 2, 0);
    assert(sw2.getCurrentTime().getSeconds() == 15);
    assert(sw2.getCurrentTime().getMinutes() == 2);
    
    sw2.start();
    assert(sw2.isRunning());
    
    sw2.incrementTime(10, 1, 0);
    assert(sw2.getCurrentTime().getSeconds() == 25);
    assert(sw2.getCurrentTime().getMinutes() == 3);
    
    sw2.lap();
    assert(sw2.getLapCount() == 1);
    
    sw2.stop();
    assert(!sw2.isRunning());
    
    sw2.reset();
    assert(sw2.getCurrentTime().getTotalSeconds() == 0);
    assert(sw2.getLapCount() == 0);
    
    std::cout << "Stopwatch class tests passed!" << std::endl;
}

void testPomodoro() {
    std::cout << "Testing Pomodoro class..." << std::endl;
    
    Pomodoro pom1;
    assert(pom1.getCycles() == 0);
    
    Pomodoro pom2(30, 25, 0, 30, 5, 0);
    Time currentTime(0, 0, 9);
    pom2.startWork(currentTime);
    
    pom2.incrementCycles();
    assert(pom2.getCycles() == 1);
    
    pom2.startBreak(currentTime);
    pom2.incrementCycles();
    assert(pom2.getCycles() == 2);
    
    pom2.reset();
    assert(pom2.getCycles() == 0);
    
    std::cout << "Pomodoro class tests passed!" << std::endl;
}

void testBedtimeAlarmScenario() {
    std::cout << "\nTesting Bedside Alarm Scenario..." << std::endl;
    
    // Setup: Create an alarm for 7:00 AM
    Alarm wakeUpAlarm(7, 0, 0);
    wakeUpAlarm.setIsSet(true);
    wakeUpAlarm.setReoccurring(true);
    
    // Verify alarm is set
    assert(wakeUpAlarm.getIsSet());
    assert(wakeUpAlarm.getAlarmTime().getHours() == 7);
    
    // Simulate snoozing for 9 minutes
    wakeUpAlarm.snooze(9);
    assert(wakeUpAlarm.getAlarmTime().getMinutes() == 9);
    assert(wakeUpAlarm.getAlarmTime().getHours() == 7);
    
    // Setup: Create a timer for morning routine (30 minutes)
    Timer morningRoutine(0, 30, 0);
    Time currentTime(0, 9, 7);
    morningRoutine.start(currentTime);
    assert(morningRoutine.isRunning());
    
    // Setup: Create a stopwatch to track shower time
    Stopwatch showerTimer;
    showerTimer.start();
    showerTimer.incrementTime(0, 10, 0); // 10 minute shower
    showerTimer.lap();
    assert(showerTimer.getLapCount() == 1);
    
    std::cout << "Bedside Alarm Scenario tests passed!" << std::endl;
}

int main() {
    std::cout << "=== Starting Test Suite ===" << std::endl;
    
    try {
        testTime();
        testAlarm();
        testTimer();
        testStopwatch();
        testPomodoro();
        testBedtimeAlarmScenario();
        
        std::cout << "\n=== All tests passed! ===" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}