#include<bits/stdc++.h>
using namespace std;

struct process{
    int arrival,burst,priority, pid;
    int passed=0;
};
process processes[6];
bool vis[7] = {false};

process findMinSize(int n, int ttime)
{
    process ret;
    ret.burst=INT_MAX;
    ret.pid= -1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false && processes[i].burst<ret.burst && processes[i].arrival<=ttime)
            ret = processes[i];
    }
    vis[ret.pid-1]=true;
    return ret;
}
    int priority[] =    {8,3,4,4,5,5};
    int brust[] = {15,20,20,20,5,15};
    int arrival[] = {0,0,20,25,45,55};


bool foo(process x, process y)
{
    if(x.arrival==y.arrival)
    {
        if(x.priority==y.priority)
        {
            return x.burst<y.burst;
        }
        else
            return x.priority>y.priority;
    }
    else
        return x.arrival<y.arrival;
}


void waitingFunction(int burst[],int arrival[], int waitingTime[], int totalWaitingTime, int n)
{
    waitingTime[0]=0;
    int service[n]={0};
    for(int i=1;i<n;i++)
    {
        service[i] = service[i-1]+burst[i-1];
        waitingTime[i]=service[i]-arrival[i];
        if(waitingTime[i]<0) waitingTime[i] = 0;
    }
}

void turnAroundFunction(int burst[], int arrival[], int turnAroundTime[], int waitingTime[], int totalTurnAroundTime, int n)
{
    for(int i=0;i<n;i++)
    {
        turnAroundTime[i] = burst[i] + waitingTime[i];
    }
}

void solutionwithRoundRobin(int priority[], int burst[], int arrival[], int n)
{
    cout<< "\n\n.......Round Robin.....\n\n";




    int quantam = 10;
    int totalWaitingTime = 0, totalTurnAroundTime =0;
    int waitingTime[n] ={0}, turnAroundTime[n]={0}, temp[10];
    int total =0, cc2=0;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        temp[i]=burst[i];
    }
    queue<process> q;
    vector<int> res;
    int  wait=0;
    int wt=0,tt=0;
    process minArivProcess;
    minArivProcess.arrival=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(processes[i].arrival<minArivProcess.arrival)
        {
            minArivProcess = processes[i];
        }
    }
    q.push(minArivProcess);
    int counter2=0;

    while(!q.empty())
    {
        process tem = q.front();
        q.pop();
        res.push_back(tem.pid);
        //q.pop();
        if(tem.burst<=quantam&&tem.burst>0)
        {

            total +=  tem.burst;
            tem.burst=0;
            flag=true;
        }
        else if(tem.burst>0)
        {

            total += quantam;
            tem.burst -= quantam;
        }


        if(tem.burst==0 && flag==true)
        {
            cc2++;
            waitingTime[counter2++] = total-tem.arrival-temp[tem.pid-1];
            if(waitingTime[counter2-1]<0) waitingTime[counter2-1]=0;
            wt+=waitingTime[counter2-1];
            turnAroundTime[counter2-1] = total - tem.arrival;
            tt+=turnAroundTime[counter2-1];
            totalTurnAroundTime += turnAroundTime[counter2-1];
        }



        for(int i=0;i<n;i++)
        {
            if(processes[i].pid==tem.pid)
            {
                processes[i].burst=tem.burst;
            }
        }
        int ii=tem.pid;
        if(ii==n) ii=0;

        int counter = 0;

        while(counter++<n)
        {
            if(processes[ii].arrival<=total&&processes[ii].pid!=tem.pid && processes[ii].burst>0)
            {
                q.push(processes[ii]);
                ii++;
                break;
            }
            ii++;
            if(ii==n) ii=0;
        }



        if(cc2==n)
        {

            break;
        }

    }
    cout<< "Order: ";
    for(int i=0;i<res.size();i++)
    {
        cout<< res[i]<< " ";
    }
    cout<< endl;

    cout<< "Avg Waiting Time : "<< (float) wt/ (float)n<<endl;
    cout<< "Avg TurnAround Time : "<< (float) tt/ (float)n<<endl;
}


bool done[7] = {false};


bool foo2(process x, process y)
{
    if(x.arrival==y.arrival)
    {
        return x.burst<y.burst;
    }
    else
        return x.arrival<y.arrival;
}









