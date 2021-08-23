#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{

     int arrival_time[100],burst_time[100],x[100],i,j,smallest,count=0,time,n;
     double Average_waiting_time=0,Average_turnaround_time=0,end;

     cout<<"enter the number of Processes:\n"<<endl;
     cin>>n;

     cout<<"enter arrival time:\n"<<endl;
     for(i=0;i<n;i++)
     cin>>arrival_time[i];

     cout<<"enter burst time:\n"<<endl;
     for(i=0;i<n;i++)
     cin>>burst_time[i];

     for(i=0;i<n;i++)
     x[i]=burst_time[i];

     burst_time[9]=9999;

     for(time=0;count!=n;time++)
     {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(arrival_time[i]<=time && burst_time[i]<burst_time[smallest] &&burst_time[i]>0 )
            smallest=i;
        }

        burst_time[smallest]--;
        if(burst_time[smallest]==0)
        {
            count++;
            end=time+1;
            Average_waiting_time=Average_waiting_time+end-arrival_time[smallest]-x[smallest];
            Average_turnaround_time= Average_turnaround_time+end-arrival_time[smallest];
        }
     }
     cout<<"\n\nAverage waiting time = "<<Average_waiting_time/n<<endl;
     cout<<"\n\nAverage Turnaround time = "<<Average_turnaround_time/n<<endl;

     return 0;
}
