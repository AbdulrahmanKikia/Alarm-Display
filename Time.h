#pragma once

class Time {
private:
	int seconds;
	int minutes;
	int hours;
public:
	Time();
	Time(int, int, int);
	Time(Time&);
	~Time();

	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;

	void setSeconds(int);
	void setMinutes(int);
	void setHours(int);
	void setTime(int, int, int);
	void setTimeFormat24(bool);

	bool isTime(Time &t) const; // To be replaced with operator override
	void incrementSeconds(int);
	void incrementMinutes(int);
	void incrementHours(int);
	void incrementTime(int, int, int);
	Time timeDifference(Time&) const;
	bool timeFormat24();

	void printTime() const;
	void printTimeInSeconds() const;
	void printTimeInMinutes() const;
	void printTimeInHours() const;
	void printTimeInDays() const;
	void printTimeDifference(Time&) const;
};