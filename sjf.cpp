#include<iostream>
using namespace std;

int main()
{
    int n; 

    cout<<"Enter number of processes:";
    cin>>n;

    int AT[n], BT[n], CT[n], WT[n], TAT[n], completed[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter AT and BT for P"<<i+1<<": ";
        cin>>AT[i]>>BT[i];
        completed[i]=0;
    }

    int time=0, done=0;

    while(done<n)
    {
        int idx=-1;
        int minBT=9999;

        for(int i=0;i<n;i++)
        {
            if(AT[i]<=time && completed[i]==0 && BT[i]<minBT)
            {
                minBT=BT[i];
                idx=i;
            }
        }
        if(idx != -1)
        {
            time += BT[idx];
            CT[idx]=time;
            completed[idx]=1;
            done++;
        }
        else
        time++;
    }
    for(int i=0;i<n;i++)
    {
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]=BT[i];
    }
    cout<<"\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl;
    }
    return 0;
}
