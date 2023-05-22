#include<bits/stdc++.h>
using namespace std;
struct Job
{
	char id;
	int dead;
	int profit;
};
bool mycmp(Job a,Job b)
{
	return (a.profit>b.profit);
}
void Schedule(Job a[],int n)
{
	bool slot[n]={false};
	sort(a,a+n,mycmp);
	//slot[a.first-1]=true;
	int result[n];
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,a[i].dead)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				slot[j]=true;
				result[j]=i;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(slot[i])
		  cout<<a[result[i]].id<<" "<<a[result[i]].profit<<"\n";
	}
}
int main()
{
	Job a[]={{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"The maximum profit by scheduling the given job \n";
	Schedule(a,n);
	return 0;
}
