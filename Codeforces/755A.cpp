#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2!=0 && n!=1)
	{
		cout<<"1";
		return 0;
	}
	int temp;
	for(int i=1;i<=1000;i++)
	{
		temp=(n*i)+1;
		if(temp%3==0 ||temp%5==0 ||temp%7==0||temp%11==0||temp%13==0||temp%17==0)
		{
			if(temp!=3 && temp!=5 && temp!=7 && temp!=11 && temp!=13 && temp!=17)
			{
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}