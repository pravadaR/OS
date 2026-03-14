#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of processes:";
    cin>>n;

    int AT[n], BT[n], RT[n], CT[n], WT[n], TAT[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter AT and BT for P"<<i+1<<"; ";
        cin>>AT[i]>>BT[i];
        RT[i]=BT[i];
    }
    int time=0, completed=0;

    while(completed<n)
    {
        int idx=-1;
        int minRT=9999;

        for(int i=0;i<n;i++)
        {
            if(AT[i]<=time && RT[i]>0 && RT[i]<minRT)
        {
            minRT=RT[i];
            idx=i;
        }
        }
        if(idx != -1)
        {
            RT[idx]--;
            time++;

            if(RT[idx]==0)
            {
                completed++;
                CT[idx]=time;
            }
        }
        else
            time++;
    }
    for(int i=0;i<n;i++)
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