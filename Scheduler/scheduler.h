#ifndef S_GUARD
#define S_GUARD

#include "Task.h"
#include <queue>

typedef priority_queue <Task, vector<Task>, Task::myComparator > pq;


class Scheduler
{
private:
	pq min_heap;
	Time start_time;
	void time_left_to_run(Task& p, long int next_execute_time)const;
	void wait_and_excecute(Task& p)const;
	void execute(Task& p)const;

public:
	Scheduler(const Time&);
	void add_task(Task& task);
	void start_scheduling(short number_task_to_run);
};

#endif
