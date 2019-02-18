#include "scheduler.h"

int Task::id_number = 0;

void add_to_schedule(Task* arr, short num, Scheduler& s)
{
	for(int i = 0; i < num; i++) s.add_task(arr[i]);
}

void test_1()
{
	Task tasks[3] = {Task (10, "play the guitar"), 
					 Task (20, "go start coding man!!"),
					 Task (30, "go to the bathrooooooom !!!!  ")
					};
	Scheduler s(Time(0));
	add_to_schedule(tasks, 3, s);
	s.start_scheduling(3);

}


void test_2()
{
	Task tasks[3] = {Task (100, "go to workkk"), 
					 Task (1000, "study c++!!"),
					 Task (1500, "go to sleeeeeeeeep !!!!  ")
					};
	Scheduler s(Time(0));
	add_to_schedule(tasks, 3, s);
	s.start_scheduling(3);

}

void test_3()
{
	Task tasks[3] = {Task (100, "no sleeeep today"), 
					 Task (1000, "study c and oop!!"),
					 Task (1500, "go to University!!!!  ")
					};
	Scheduler s(Time(0));
	add_to_schedule(tasks, 3, s);
	s.start_scheduling(2);

	Task tasks2[1] = {Task (5, "go eat!!!! its 12:30 !!!   ")};
	add_to_schedule(tasks2, 1, s);
	s.start_scheduling(2);

}


void print_line()
{
	cout<< "****************************** END TEST *********************************" <<endl;
}


int main()
{
	test_1(); 
	print_line();
	test_2();
	print_line();
	test_3();
}



