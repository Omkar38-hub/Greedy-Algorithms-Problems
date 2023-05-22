#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b)
{
	double r1=(double)a.first/a.second;
	double r2=(double)b.first/b.second;
	return r1>r2;
}
int Fractional(int n,pair<int,int>a[],int w)
{
	sort(a,a+n,mycomp);
	double res=0.0;
	for(int i=0;i<n;i++)
	{
		if(a[i].second<=w)
		{
			res+=a[i].first;
			w=w-a[i].second;
		}
		else
		{
			res+=a[i].first *(double)w/a[i].second;
			break;
		}
	}
	return res;
}
int main()
{
	int n,x,y;
	cout<<"Enter the number of goodies ";
	cin>>n; //3
	int W=50;
	pair<int,int>a[n];
	for(int i=0;i<n;i++)//(120,30) (100,20) (60,10)
	{
		cout<<"Enter pair of value and weight ";
		cin>>x>>y;
		a[i]=make_pair(x,y);
	}
	cout<<"The maximum value picked in knapsack of "<<W<<" weight is "<<Fractional(n,a,W);
	return 0;
}
