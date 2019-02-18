#include "Task.h"

Task::Task()
	:m_mill(0)
{
	id_number += 1;
	m_number = id_number;
}

Task::Task(long int mill,const char* description)
	:m_mill(mill)
{
	strcpy(m_description, description);
	id_number += 1;
	m_number = id_number;
	
}
	
void Task::run(){
	cout<< "my number is :" << m_number <<endl;
	cout<<  m_description << endl;
	cout<< "======================================================="<<endl;
}

Time Task::getNextRunPeriod() const {
	return m_mill;
} 


int Task::myComparator::operator() (const Task& p1, const Task& p2) 
{ 
	return p1.getNextRunPeriod() > p2.getNextRunPeriod(); 
} 

Time Task::get_time()const
{
	return m_mill;
}


