#include "scheduler.h"


Scheduler::Scheduler(const Time& time)
   :start_time(time)
{

}

void Scheduler::add_task(Task& task)
{
   min_heap.push(task);
}

void Scheduler::time_left_to_run(Task& p, long int next_execute_time) const
{
   cout<< "next task to run after :" << next_execute_time << " milliseconds" << endl;   
}

void Scheduler::wait_and_excecute(Task& p) const
{
   long int next_execute_time = p.getNextRunPeriod().get_mill() - start_time.get_mill();
   time_left_to_run(p, next_execute_time);
   usleep(microToMili * next_execute_time);
   p.run();
}

void Scheduler::execute(Task& p) const
{
   long int next_execute_time = p.getNextRunPeriod().get_mill() - start_time.get_mill();
   time_left_to_run(p, next_execute_time);
   p.run();
}

void Scheduler::start_scheduling(short number_task_to_run)
{
   Task p;
   bool check_continue_scheduling = !min_heap.empty() && (number_task_to_run-- != 0);

   while(check_continue_scheduling){
      p = min_heap.top(); 
      start_time.now();
      start_time < p.getNextRunPeriod() ? wait_and_excecute(p) :  execute(p);
      min_heap.pop(); 
      check_continue_scheduling = !min_heap.empty() && (number_task_to_run-- != 0);

   }
   
}
