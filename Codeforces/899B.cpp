#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	std::vector<int> v(n+1);
	for (int i = 1; i <=n; i++)
		cin>>v[i];
	int pos28[20],pos29[20],m=0,l=0,count28=0,count29=0;
	for(int i=1;i<n;i++)
	{
		if(v[i]==28)
		{
			count28++;
			pos28[m]=i;
			m++;
		}
		else if(v[i]==29)
		{
			count29++;
			pos29[l]=i;
			l++;
		}
	}
	if(n>=12 && (count28+count29)<1)
	{	
		cout<<"No";
		return 0;
	}	
	if(n==24 && (count28+count29)!=2)
	{	
		cout<<"No";
		return 0;
	}
	if(count29>=2)
	{	
		cout<<"No";
		return 0;
	}
	if(l==0)
	{
		for (int i = 0; i < m-1; i++)
		{
			if(pos28[i+1]-pos28[i]<12)
			{
				cout<<"No";
				return 0;
			}
		}
	}
	else if(abs(pos28[0]-pos29[0])<12 && m!=0)
	{
		cout<<"No";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(v[i]==30 && v[i+1]==30)
		{
			cout<<"No";
			return 0;
		}
	}
	if(v[1]==28||v[1]==29)
	{
		if(n>1)
		{
			if(v[2]!=31)
			{
				cout<<"No";
				return 0;
			}
		}
	}
	for(int i=2;i<n;i++)
	{
		if(v[i]==29||v[i]==28)
		{
			if(v[i-1]!=31||v[i+1]!=31)
			{
				cout<<"No";
				return 0;
			}
		}
	}
	if(v[n-1]==28||v[n-1]==29)
	{
		if(v[n]!=31)
		{
			cout<<"No";
			return 0;
		}
	}
	int counter=0;
	for(int i=1;i<n;i++)
	{
		if(v[i]==31 && v[i+1]==31)
		{
			counter++;
		}
	}
	if((n==4||n==5||n==6||n==7) && counter>=2)
	{
		cout<<"No";
		return 0;
	}
	if((n==8||n==9||n==10||n==11||n==12) && (counter<1||counter>2))
	{
		cout<<"No";
		return 0;
	}
	if((n==13||n==14||n==15||n==16||n==17||n==18||n==19||n==20) && (counter<2||counter>3))
	{
		cout<<"No";
		return 0;
	}
	if((n==21||n==22||n==23) && (counter<3||counter>4))
		{
		cout<<"No";
		return 0;
	}
	if(n==24 && counter>5)
		{
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}