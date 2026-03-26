#ifndef ALARM_H
#define ALARM_H

#include "Time.h"

class Alarm {
	private:
		Time alarmTime;
		bool isSet;
		bool reoccurring; // true for daily, false for one-time
	public:
		Alarm();
		Alarm(int, int, int);
		Alarm(Time);
		Alarm(const Alarm&);
		~Alarm();

		Time getAlarmTime() const;
		bool getIsSet() const;
		bool getReoccurring() const;

		void setAlarmTime(int, int, int);
		void setIsSet(bool);
		void setReoccurring(bool);

		void printAlarm() const;
		void snooze(int minutes);
};

#endif // ALARM_H