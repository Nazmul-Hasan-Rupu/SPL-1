#include<bits/stdc++.h>

using namespace std;

void Fcfs()
{
    int n,Burst_Time[200],waiting_time[200],turnaround_time[200],Average_Waiting_time=0;
    int Average_Turnaround_Time=0,i,j,total_waiting_time=0,total_turnaround_time=0;

    ifstream ifile;
    ifile.open("FcfsFile.txt");


    ifile>>n;


    for(i=0;i<n;i++)
    {

        ifile>>Burst_Time[i];
    }

    waiting_time[0]=0;

    //waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]=waiting_time[i]+Burst_Time[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";


    for(i=0;i<n;i++)
    {
        turnaround_time[i]=Burst_Time[i]+waiting_time[i];
        total_waiting_time=total_waiting_time+waiting_time[i];
        total_turnaround_time=total_turnaround_time+turnaround_time[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<Burst_Time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnaround_time[i];
    }

    Average_Waiting_time=total_waiting_time/i;
    Average_Turnaround_Time=total_turnaround_time/i;
    cout<<"\n\nAverage Waiting Time:"<<Average_Waiting_time;
    cout<<"\nAverage Turnaround Time:"<<Average_Turnaround_Time;
	cout<<endl;
}
