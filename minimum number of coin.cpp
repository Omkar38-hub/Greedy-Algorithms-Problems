#include<bits/stdc++.h>
using namespace std;

int minCoin(int coins[],int amount,int n)
{
	sort(coins,coins+n,greater<int>());
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(coins[i]<=amount)
		{
			int w=amount/coins[i];
			cout<<w<<" coins of denomination "<<coins[i]<<" required"<<"\n\n";
			amount=amount-w *coins[i];
			res+=w;
		}
		if(amount==0)
		  break;
	}
	return res;
}
int main()
{
	int amount=57;
	int coins[]={5,10,2,1};
	int n=sizeof(coins)/sizeof(coins[0]);
	cout<<"The minimum number of coin required to get "<<amount<<" is "<<minCoin(coins,amount,n);
	return 0;
}
