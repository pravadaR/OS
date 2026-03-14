#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n, tq;
    cout<<"Enter number of processes:";
    cin>>n;

    int AT[n], BT[n], RT[n], CT[n], WT[n], TAT[n];

    for(int i=0;i<n;i++)
    {
        cout<<"ENter AT and BT for P"<<i+1<<": ";
        cin>>AT[i]>>BT[i];
        RT[i]=BT[i];
    }
    cout<<"Enter Time Quantum: ";
    cin>>tq;

    int time=0, completed=0;

    while(completed<n)
    {
        bool executed = false;

        for(int i=0;i<n;i++)
        {
            if(AT[i]<=time && RT[i]>0)
            {
                executed=true;

                if(RT[i]>tq)
                {
                    time += tq;
                    RT[i] -= tq;
                }
                else{
                    time += RT[i];
                    RT[i]=0;
                    CT[i]=time;
                    completed++;
                }
            }
        }
        if(!executed)
        time++;
    }
    for(int i=0; i<n;i++)
    {
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }
    cout<<"\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl;
    }
    return 0;
}
