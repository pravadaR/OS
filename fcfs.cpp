#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout<<"Enter number of processes: ";
	cin>>n;
	
	int AT[20], BT[20], CT[20], TAT[20], WT[20], RT[20];
	
	for(int i =0; i<n;i++)
	{
		cout<<"\nProcess "<<i+1<<"\n";
		
		cout<<"Arrival Time: ";
		cin>>AT[i];
		
		cout<<"Burst Time: ";
		cin>>BT[i];
		}
		
	CT[0] = AT[0] + BT[0];
	
	for(int i=1; i<n;i++)
	{
		if(CT[i-1]<AT[i])
		{
			CT[i]=AT[i]+BT[i];
		}
		else
		{
			CT[i]=CT[i-1]+BT[i];
		}
	}
	for(int i=0; i<n;i++)
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-BT[i];
		RT[i]=WT[i];
	}
	
	cout<<"\n\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n";
	
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"
            <<CT[i]<<"\t"
            <<TAT[i]<<"\t"
            <<WT[i]<<"\t"
            <<RT[i]<<"\n";
    }
    return 0;
   }