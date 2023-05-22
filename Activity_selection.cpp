#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b)
{
	return (a.second<b.second);
}
int maxActivity(int n,pair<int,int>a[])
{
	sort(a,a+n,mycomp);
	int prev=0;
	int count=1;
	for(int i=1;i<n;i++)
	{
		if(a[i].first>=a[prev].second)
		{
			count++;
			prev=i;
		}
	}
	return count;
}
int main()
{
	int n,x,y;
	cout<<"Enter the number of activities ";
	cin>>n; //3
	pair<int,int>a[n];
	for(int i=0;i<n;i++)//(12,25) (10,20) (20,30)
	{
		cout<<"Enter start and end time of activity ";
		cin>>x>>y;
		a[i]=make_pair(x,y);
	}
	cout<<"The maximum number of activity can be done is "<<maxActivity(n,a);
	return 0;
}
