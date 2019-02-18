#ifndef TIME_GUARD
#define TIME_GUARD

#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>

class Time
{
private:
	long int m_time;
	static long int get_system_curr_time();
public:
	Time(const Time& t);
	Time(long int);
	Time();
	void now();
	bool operator<=(const Time& other) const;
	bool operator>=(const Time& other) const;
	bool operator>(const Time& other) const;
	bool operator<(const Time& other) const;
	long int get_mill() const;
	Time operator+(const Time& other) const;
	Time operator-(const Time& other) const;
	friend std::ostream& operator <<(std::ostream& os, Time& other);
};

#endif
