#include<bits/stdc++.h>
using namespace std;
int main()
{
	int diff1,arr1[102],temp,m,s,pos,i,f=1,l,diff,arr[102],sum,k;
	cin>>m>>s;
	if(m==1 && s==0)
	{
		cout<<"0 0"<<endl;
		return 0;
	}
	if(9*m<s || s==0)
	{
		cout<<"-1 -1"<<endl;
		return 0;
	}
	for(i=0;i<m;i++)
	{
		arr[i]=9;
		arr1[i]=9;
	}
	sum=m*9;
	diff=sum-s;
	diff1=sum-s;
	k=m-1;
	while(diff>0)
	{
		if(diff>=9)
		{
			arr[k]-=9;
			diff-=9;
		}
		else
		{
			arr[k]-=diff;
			diff=0;
		}
			k--;
	}
	k=0;
	while(diff1>0)
	{
		if(k==0 && diff1>=9)
		{
			arr1[k]-=8;
			diff1-=8;
		}
		else if(diff1>=9)
		{
			arr1[k]-=9;
			diff1-=9;
		}
		else
		{
			arr1[k]-=diff1;
			diff1=0;
		}
			k++;
	}
	for (i =  0; i < m; i++)
		cout<<arr1[i];
	cout<<" ";
	for (i =  0; i < m; i++)
		cout<<arr[i];
	cout<<endl;
	return 0;
}