#include<iostream>
using namespace std;

int main()
{
    int burst_time[200],process[200],waiting_time[200],Turnaround_time[200],i,j,n,total=0,pos,temp;
    float waiting_time_avg,Turnaround_avg;
    cout<<"Enter number of process: ";
    cin>>n;

    cout<<"\nEnter Burst time: \n";
    for(i=0;i<n;i++)
    {
       cout<<"Process["<<i+1<<"]: ";
       cin>>burst_time[i];
        process[i]=i+1;           //Process Number
    }

//Sort


    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }

    waiting_time[0]=0;//First process has 0 waiting time
    //waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]=waiting_time[i]+burst_time[j];

        total=total+waiting_time[i];
    }
     //Average waiting time
    waiting_time_avg=(float)total/n;
    total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
       Turnaround_time[i]=burst_time[i]+waiting_time[i]; //Turnaround Time
       total=total+Turnaround_time[i];
        cout<<"\n"<<process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<Turnaround_time[i];
    }

 //Average Turnaround Time
    Turnaround_avg=(float)total/n;
    cout<<"\n\nAverage Waiting Time: "<<waiting_time_avg;
    cout<<"\nAverage Turnaround Time: "<<Turnaround_avg;
}
