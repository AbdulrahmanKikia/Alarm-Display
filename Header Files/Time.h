#ifndef TIME_H
#define TIME_H	

class Time {
private:
	int seconds;
	int minutes;
	int hours;
	bool format24; // true for 24-hour format, false for 12-hour format
public:
	Time();
	Time(int, int, int);
	Time(const Time&);
	~Time();

	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;
	int getTotalSeconds() const;

	void setSeconds(int);
	void setMinutes(int);
	void setHours(int);
	void setTime(int, int, int);
	void setTimeFormat24(bool);

	bool isTime(const Time &t) const; // To be replaced with operator override
	void incrementSeconds(int);
	void incrementMinutes(int);
	void incrementHours(int);
	void incrementTime(int, int, int);
	Time timeDifference(const Time&) const;
	Time operator-(const Time&) const;
	bool isTimeFormat24() const;

	void printTime() const;
	void printTimeInSeconds() const;
	void printTimeInMinutes() const;
	void printTimeInHours() const;
	void printTimeInDays() const;
	void printTimeDifference(const Time&) const;
};

#endif // TIME_H