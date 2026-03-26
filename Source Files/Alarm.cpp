#include "Alarm.h"
#include <iostream>

Alarm::Alarm() {
    alarmTime = Time();
    isSet = false;
    reoccurring = false;
}
Alarm::Alarm(int h, int m, int s) {
    alarmTime = Time(s, m, h);
    isSet = true;
    reoccurring = false;
}
Alarm::Alarm(Time t) {
    alarmTime = t;
    isSet = true;
    reoccurring = false;
}
Alarm::Alarm(const Alarm& a) {
    alarmTime = a.getAlarmTime();
    isSet = a.getIsSet();
    reoccurring = a.getReoccurring();
}
Alarm::~Alarm() {}

Time Alarm::getAlarmTime() const {
    return alarmTime;
}
bool Alarm::getIsSet() const {
    return isSet;
}
bool Alarm::getReoccurring() const {
    return reoccurring;
}

void Alarm::setAlarmTime(int h, int m, int s) {
    alarmTime.setTime(s, m, h);
}
void Alarm::setIsSet(bool set) {
    isSet = set;
}
void Alarm::setReoccurring(bool rec) {
    reoccurring = rec;
}

void Alarm::printAlarm() const {
    std::cout << "Alarm Time: ";
    alarmTime.printTime();
    std::cout << "Is Set: " << (getIsSet() ? "Yes" : "No") << std::endl;
    std::cout << "Reoccurring: " << (getReoccurring() ? "Daily" : "One-time") << std::endl;
}
void Alarm::snooze(int minutes) {
    alarmTime.incrementMinutes(minutes);
}