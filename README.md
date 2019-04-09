# Question1

Fair-share scheduling is a scheduling algorithm for computer operating systems in which the CPU usage is equally 
distributed among system users or groups, as opposed to equal distribution among processes.
One common method of logically implementing the fair-share scheduling strategy is to recursively apply the 
round-robin scheduling strategy at each level of abstraction (processes, users, groups, etc.) 
The time quantum required by round-robin is arbitrary, as any equal division of time will produce the same results.

The given problem is based upon solving queries of persons of different classes i.e. Faculty and Students.
Thus, these queries can be compared to different processes in terms of operating system where each process 
has its demands and needs resources and time for its execution. 
And this demands of processes are handled by the CPU.

Now, Mr. Sharma, wants to provide priority for each query based upon its 
class, as well as, he wants to dedicate a fixed amount of time to every request. Thus in Operating System, if 
we divide the requests into two separate queues i.e. Faculty and Student such that the first queue contains 
faculty queries has higher priority and the second contains student queries which has lower priority, then 
we can resolve the problem, by allocating them required resources.
