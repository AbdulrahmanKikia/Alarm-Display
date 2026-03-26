#include "Time.h"
#include <iostream>
#include <cstdlib> // for abs

Time::Time() {
	seconds = 0;
    minutes = 0;
	hours = 0;
	format24 = true;
}

Time::Time(int sec, int min, int h) {
	if (sec < 0 || sec > 59 || min < 0 || min > 59 || h < 0 || h > 24) {
		std::cerr << "Invalid time provided. Setting to default (00:00:00)." << std::endl;
		seconds = 0;
		minutes = 0;
		hours = 0;
	}

	else {
		seconds = sec;
		minutes = min;
		hours = h;
		format24 = true;
	}
}

Time::Time(const Time& t) {
	seconds = t.getSeconds();
	minutes = t.getMinutes();
	hours = t.getHours();
    format24 = t.isTimeFormat24();
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
	if (sec < 0 || sec > 59) {
		std::cerr << "Invalid seconds value. Must be between 0 and 59." << std::endl;
		return;
	}
	seconds = sec;
}
void Time::setMinutes(int min) {
	if (min < 0 || min > 59) {
		std::cerr << "Invalid minutes value. Must be between 0 and 59." << std::endl;
		return;
	}
	minutes = min;
}
void Time::setHours(int h) {
	if (h < 0 || h > 24) {
		std::cerr << "Invalid hours value. Must be between 0 and 24." << std::endl;
		return;
	}
	hours = h;
}
void Time::setTime(int sec, int min, int h) {
	setSeconds(sec);
	setMinutes(min);
	setHours(h);
}

bool Time::isTime(const Time& t) const{
	if (seconds == t.seconds && minutes == t.minutes && hours == t.hours) {
		return true;
	}
	else {
		return false;
	}
}

bool Time::isTimeFormat24() const{
	return format24;
}

void Time::setTimeFormat24(bool is24) {
	format24 = is24;
}

void Time::incrementSeconds(int sec) {
	seconds += sec;
	if (seconds >= 60) {
		minutes += seconds / 60;
		seconds = seconds % 60;
	}
	if (minutes >= 60) {
		hours += minutes / 60;
		minutes = minutes % 60;
	}
}

void Time::incrementMinutes(int min) {
	minutes += min;
	if (minutes >= 60) {
		hours += minutes / 60;
		minutes = minutes % 60;
	}
}

void Time::incrementHours(int h) {
	hours += h;
}

void Time::incrementTime(int sec, int min, int h) {
	incrementSeconds(sec);
	incrementMinutes(min);
	incrementHours(h);
}

// Helper method to convert to total seconds
int Time::getTotalSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

// Better timeDifference using seconds
Time Time::timeDifference(const Time& t) const {
    int diff = std::abs(getTotalSeconds() - t.getTotalSeconds());
    Time result;
    result.hours = diff / 3600;
    result.minutes = (diff % 3600) / 60;
    result.seconds = diff % 60;
    return result;
}

void Time::printTime() const {
    if (format24) {
        printf("%02d:%02d:%02d\n", hours, minutes, seconds); // Zero-padded
    } else {
        int displayHours = hours == 0 ? 12 : (hours > 12 ? hours - 12 : hours);
        const char* period = hours < 12 ? "AM" : "PM";
        printf("%02d:%02d:%02d %s\n", displayHours, minutes, seconds, period);
    }
}

void Time::printTimeInSeconds() const {
	std::cout << "Time in seconds: " << (hours * 3600) + (minutes * 60) + seconds << std::endl;
}

void Time::printTimeInMinutes() const {
	std::cout << "Time in minutes: " << (hours * 60) + minutes + (seconds / 60) << std::endl;
}

void Time::printTimeInHours() const {
	std::cout << "Time in hours: " << hours + (minutes / 60) + (seconds / 3600) << std::endl;
}

void Time::printTimeInDays() const {
	std::cout << "Time in days: " << (hours / 24) + (minutes / 1440) + (seconds / 86400) << std::endl;
}

void Time::printTimeDifference(const Time& t) const {
	Time diff = timeDifference(t);
	std::cout << "Time difference: " << diff.hours << " hours, " << diff.minutes << " minutes, " << diff.seconds << " seconds" << std::endl;
}

Time Time::operator-(const Time& other) const {
    int diff = getTotalSeconds() - other.getTotalSeconds();
    if (diff < 0) {
        return Time(0, 0, 0);
    }
    Time result;
    result.seconds = diff % 60;
    result.minutes = (diff / 60) % 60;
    result.hours = diff / 3600;
    return result;
}