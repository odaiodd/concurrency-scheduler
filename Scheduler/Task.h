#ifndef TASK_GUARD
#define TASK_GUARD

#include "Time.h"
#include <string.h>
#define microToMili 1000
#define TASK_DESCRIPTION_SIZE 256

using namespace std;

struct ITask
{
   virtual void run() = 0;
   virtual Time getNextRunPeriod()const = 0 ; // in milliseconds
};

struct Task : public ITask
{
public:
	Task();
	Task(long int mill, const char* description);
	void run();
	Time getNextRunPeriod() const;
	Time get_time()const;

	// nested class for comparing two tasks
	class myComparator 
	{ 
		public: 
    		int operator() (const Task& p1, const Task& p2);
	}; 

private:
	char m_description[TASK_DESCRIPTION_SIZE];
	int m_number;
	Time m_mill;
	static int id_number; // id counter
};




#endif

