#include<bits/stdc++.h>
#include "Fcfs.cpp"
#include "Sjf_preemtive.cpp"
#include "Sjf_nonpreemtive.cpp"
#include "Priority_Scheduling.cpp"
#include "BankersAlgorithm.cpp"
#include "FIFO.cpp"
#include "Optimal.cpp"
#include "LeastRecentlyUsed.cpp"
#include "Round_Robin.cpp"

using namespace std;



  void option()
  {
    cout<<"           1.FCFS Algorithm"<<endl;
	cout<<"           2.SJF_preemptive Algorithm"<<endl;
	cout<<"           3.SJF_non-preemptive Algorithm"<<endl;
	cout<<"           4.Priority_Scheduling Algorithm"<<endl;
	cout<<"           5.Bankers_Algorithm Algorithm"<<endl;

	cout<<"           6.Round Robin Algorithm"<<endl;
	cout<<"           7.exit" << endl;

	cout<< endl << "Enter your Choice" << endl;

  }

int main()
{
    int priority[] = {8,3,4,4,5,5};
    int brust[] = {15,20,20,20,5,15};
    int arrival[] = {0,0,20,25,45,55};
    int n = sizeof(priority)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        processes[i].arrival=arrival[i];
        processes[i].burst = brust[i];
        processes[i].priority=priority[i];
        processes[i].pid=i+1;
    }


    sort(processes,processes+n,foo);
    option();


	int temp;

	for(int i=0;i<100;i++){
		cin>>temp;

		if(temp==1)
			Fcfs();


		else if(temp==2)
			Sjf_preemtive();


		else if(temp==3)
			Sjf_nonpreemtive();


		else if(temp==4)
			Priority_Scheduling();


		else if(temp==5)
			Bankers_Algorithm();


		else if(temp==6)
			FIFO();


		else if(temp==7)
			Optimal();


		else if(temp==8)
			LeastRecentlyUsed();

        else if(temp==9)
            solutionwithRoundRobin(priority,brust,arrival,n);

		 else {
			cout<<"exit";
			break;
		}
     cout<< endl << endl << "-------------------------------------------------" <<endl;
     cout<< "Enter your Choice" << endl;
	}

}
