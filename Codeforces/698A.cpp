#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int func(int prev,int i);
int v[102],n,mem[6][102];
int main()
{
	cin>>n;
	for (int i = 0; i < n; i++)	
		cin>>v[i];
	cout<<func(0,0);
	return 0;
}
int func(int prev,int i)
{
	if(i>=n)
		return 0;
	else if(mem[prev][i]!=0)
		return mem[prev][i];
	else if(v[i]==0)
		mem[prev][i]=1+func(0,i+1);		
	else if(v[i]==1)
	{
		if(prev==2)
			mem[prev][i]=1+func(0,i+1);
		else 
			mem[prev][i]=func(2,i+1);
	}
	else if(v[i]==2)
	{
		if(prev==1)
			mem[prev][i]=1+func(0,i+1);
		else 
			mem[prev][i]=func(1,i+1);	
	}
	else if(v[i]==3)
	{
		if(prev==2)
			mem[prev][i]=func(1,i+1);
		else if(prev==1)
			mem[prev][i]=func(2,i+1);
		else
			mem[prev][i]=min(func(2,i+1),func(1,i+1));

	}
	return mem[prev][i];
}