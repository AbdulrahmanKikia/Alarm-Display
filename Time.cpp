#include "Time.h"

Time::Time() {
	seconds = 0;
	minites = 0;
	hours = 0;
}

Time::Time(int sec, int min, int h) {
	seconds = sec;
	minutes = min;
	hours = h;
}

Time::Time(Time& t) {
	seconds = t.seconds;
	minutes = t.minutes;
	hours = t.hours;
}

Time::~Time(){}

int Time::getSeconds() const{
	return seconds;
}
int Time::getMinutes() const{
	return minutes;
}
int Time::getHours() const{
	return hours;
}

void Time::setSeconds(int sec) {
	seconds = sec;
}
void Time::setMinutes(int min) {
	minutes = min;
}
void Time::setHours(int h) {
	hours = h;
}
void Time::setTime(int sec, int min, int h) {
	setSeconds(sec);
	setMinutes(min);
	setHours(h);
}

bool Time::isTime(Time& t) const{
	if (seconds == t.seconds && minutes == t.minutes && hours == t.hours) {
		return true;
	}
	else {
		return false;
	}
}

bool Time::timeFormat24() {
	if (hours >= 0 && hours < 24) {
		return true;
	}
	else {
		return false;
	}
}

void Time::setTimeFormat24(bool is24) {
	timeFormat
}

void Time::incrementSeconds(int sec) {
	seconds += sec;
}

void Time::incrementMinutes(int min) {
	minutes += min;
}

void Time::incrementHours(int h) {
	hours += h;
}

void Time::incrementTime(int sec, int min, int h) {
	incrementSeconds(sec);
	incrementMinutes(min);
	incrementHours(h);
}

Time Time::timeDifference(Time& t) const {
	Time diff();
	diff.setSeconds(abs(seconds - t.seconds));
	diff.setMinutes(abs(minutes - t.minutes));
	diff.setHours(abs(hours - t.hours));
	return diff;
}

void Time::printTime() const {
	std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}