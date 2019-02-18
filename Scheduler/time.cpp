#include "Time.h"


Time::Time(const Time& t)
	:m_time(t.m_time)
{

}

Time::Time(long int t)
{
	m_time = get_system_curr_time() + t;
}

Time::Time()
{
	m_time = get_system_curr_time();
}

void Time::now()
{
	m_time = get_system_curr_time();
}

long int Time::get_system_curr_time(){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return ms;
}

long int Time::get_mill() const
{
	return m_time;
}	

bool Time::operator<=(const Time& other)const
{
	return m_time <= other.m_time;
}

bool Time::operator>=(const Time& other)const
{
	return m_time >= other.m_time;
}

bool Time::operator>(const Time& other)const
{
	return m_time > other.m_time;
}

bool Time::operator<(const Time& other)const
{
	return m_time < other.m_time;
}

Time Time::operator+(const Time& other)const
{
	Time tmpm_time(other);
	tmpm_time.m_time += m_time;
	return tmpm_time;
}

Time Time::operator-(const Time& other)const
{
	Time tmpm_time(other);
	tmpm_time.m_time -= m_time;
	return tmpm_time;
}

std::ostream& operator << (std::ostream& os, Time& other)
{
	os << other.m_time;
	return os;
}

