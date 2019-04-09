#include<stdio.h>
//Structure of Process
struct job
{
	int pid;//process id
	int at;//process Arrival time
	int bt;//process total burst time
	int cmp;//process completion time
	int rb;//process remaining burst time
}f[100], s[100], m[100];//here f is Faculty Array,s is Student Array, And m is Merged Array... 

int n;//n is total no of Queries. 
int fc=0, sc=0, mc=0;//here fc is faculty count.sc is Student count And mc is merged array count.Count means no of Elements.
int quanta;//Round robin Quanta.
//to Apply Round Robin Algo.
void roundRobin()
{
	int time= m[0].at, mark=0, cc=0, i, rc;//here time is for starting time of first process, Since from that moment processor will start working 
                                               //here mark is for total no of processes arrived,cc is for completed process which is 0 initially
                                               //and rc is for remaining processes.
	while(time!=120 && cc!=mc)//while time is in range and total processes are not completed iterate
        {
		for(i=0; i<=mark; i++)//iterate for total arrived processes and process each for quanta time period
                {
			if(m[i].rb > quanta)//if process reamining burst is greater than quanta process for quanta
                        {
				time += quanta;//increase total time taken
				m[i].rb -= quanta;//decrease reamining burst by quanta time
			}
			else if(m[i].rb <=quanta && m[i].rb !=0)//if remaining burst is less or equal to quanta 
                        {
				time += m[i].rb;//increase time by remaining burst
				m[i].rb =0;//remaining burst will zero since it was less than Quanta
				m[i].cmp = time;//Assign that time to completion time for process since process is completed.
				cc++;//increase count of completed processes
			}
			else;
		}
		int start = mark+1;//here start is start is to check how many more processes are arrived
		for(rc= start; rc<mc; rc++)//iterate to check how many more processes are arrived in computing interval
                {
			if(m[rc].at <= time)//if any process is arrived increse mark
                        {
				mark++;
			}
		}
	}	
}
//To merge Student and Faculty Array
void merger()
        {
	int isc=0, ifc= 0;//here isc is initial student count and ifc is initial faculty count,Since merging will start from
                                     // the beginning of both the array
	if( fc!=0  && sc!=0)//here we will see that weather Student and Faculty Array contains something or not.If they are Equal to zero else 
             {              // will operate
		while(isc<sc && ifc<fc)//Loop while There is any Element in Both of the Array.
                {
			if(f[ifc].at == s[isc].at)//this is to check weather Faculty and Student have same arrival time if yes,Faculty will be first
                        {                         //to Process and Faculty will go into merged array first
				m[mc] = f[ifc];//this if to put faculty into merged array
				mc++;//increase counter of merged array
				ifc++;//increase initial Faculty added
				m[mc]= s[isc];//this is to put Student
				mc++;//increase counter of merged array
				isc++;//increse initial count of student
			}//if arrival time of faculty is less than student add faculty to the list
			else if(f[ifc].at < s[isc].at)
                        {
				m[mc]= f[ifc];
				mc++;
				ifc++;
			}//if arrival time of faculty is greater then add Student
			else if(f[ifc].at > s[isc].at)
                        {
				m[mc]= s[isc];
				mc++;
				isc++;
			}
			else;//else do nothing
		}
		if(mc != (fc+sc))//if mc is not equal to sum of fc and sc that means that we have added to mc but have not increment hence we have to  
                {
			if(fc!=ifc)//if ifc was not incremented increment
                        {
				while(ifc!=fc)//while ifc not equal to faculty count
                                {
					m[mc]= f[ifc];
					mc++;
					ifc++;
				}
			}
			else if(sc!=isc)//if ifc was not incremented increment
                        {
				while(isc!=sc)//while ifc not equal to faculty count
                                {
					m[mc]= s[isc];
					mc++;
					isc++;
				}
			}
		}
	}
	else if(fc==0)//if Faculty list is Empty we have to add from Student only
        {
		while(isc!=sc)
                {
			m[mc]= s[isc];
			mc++;
			isc++;
		}
	}
	else if(sc==0)//if Student list is Empty we have to add from Faculty only
        {
		while(ifc!=fc)
		{
			m[mc]= f[ifc];
			mc++;
			ifc++;
		}
	}
	else //if Both Faculty and Student are Empty.
    {
		printf("\n No valid Jobs available\n");
	}
}
//To Print the Status of Each process
void printer()
{
	int i=0, total=0, sum=0;//here i is used to iterate into merged array.total is to compute total time spent for all processes including waiting 
                                //and sum is to compute total computational time.	
    double average;         //To compute Average computational time
	printf("\nSummary for the Execution\n");
	printf("\nQuery ID\tArrival Time\tRessolving Time\tCompletion Time\tTurn Around Time\tWaiting Time");
	for(i; i<mc; i++)//to iterate
        {
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",
		m[i].pid, (m[i].at+1000), m[i].bt, (m[i].cmp+1000), (m[i].cmp-m[i].at), ((m[i].cmp-m[i].at)- m[i].bt));//here +1000 is because time is
                                                                                                                       //starting from 10:00
		total= m[i].cmp;//Assign completion time of each process to total
		sum+= (m[i].cmp-m[i].at);//add computational time which is difference of completion time and arrival time
	}
	average = sum/mc;//find average
	printf("\n\nTotal time Spent for all queries: %d", total);
	printf("\nAverage query time: %lf", average);
	printf("\nProcess Execution Complete");
}
//Here we will Take Input For Each function
void input()
{
	int map,  i, t;//here map is to distinguish between Faculty and Student if 1 then Faculty if 2 then Student,i is to iterate ,t reaching time.
	printf("Enter total no of queries: "); 
        scanf("%d", &n);//n was global no of Queries
	if(n==0)//if no Query Exit
        { 
         printf("\n No queries\n"); 
        }
	else//if n is not 0 take input
        {
         printf("\nEnter Quanta for each Process: "); 
         scanf("%d", &quanta);//Enter Quanta for Round robin algo
	 printf("\nEnter 1 for faculty and 2 for student\n");
	 for(i=0; i<n; i++)//take input of n Queries
         {
          printf("\nJob Type (1/2): "); 
          scanf("%d", &map);
	  if(map==1)//if map 1 take input into faculty Array
          {
	    printf("Query Id: "); 
            scanf("%d", &f[fc].pid);
	    printf("Arrival Time: "); scanf("%d", &t);
	    if(t<1000 || t>1200)//if time is Greater than range ask for input again
            {
	      printf("\nEnter Correct time");
	      input();
	    }
	    else
           {
             f[fc].at= t-1000;//here we are saving arrival time in minutes completed from 10:00
           }

	     printf("Resolving Time: ");
             scanf("%d", &f[fc].bt);	
             f[fc].rb= f[fc].bt; //inititally required burst will equal to total burst time
	     fc++;//increase counter for Faculty Array
	   } 
           else
           {
	     printf("Query Id: "); 
             scanf("%d", &s[sc].pid);
	     printf("Arrival Time: "); 
             scanf("%d", &t); 
	     if(t<1000 || t>1200)
             {
	      printf("\nEnter Correct time\n");
	      input();
	     }
	    else 
            {
              s[sc].at= t-1000;
            }
	    printf("Resolving Time: "); 
            scanf("%d", &s[sc].bt);	 
            s[sc].rb= s[sc].bt;
	    sc++;
	    }
	 }
	}
}
//This Function is To display Instructions.
void inst()
{
	printf("\nWelcome, please follow these instruction for proper functioning of the program"
			"\n**>Enter time in 2400 hours format. example for 10:30 am enter 1030"
			"\n**>Enter Query arrival times in ascending order, i.e., in real time arrival manner\n"
			"\nAll Time units are in minutes. \n\n"
			);
}

 int  main()
{
 	inst();//this function is to take display Instructions.
	input();//this function is used to take input from user.
	merger();//this is used to merge Faculty and Student Array.
	roundRobin();//to apply round robin Scheduling
	printer();//to Print the Status of Processes
        return 0;
}
