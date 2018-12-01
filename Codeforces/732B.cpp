#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,k,arr[502],temp,diff,sum,minimum,pos,i,newarr[502][502];
	cin>>n>>k;
	for (i = 0; i < n; i++)
		cin>>arr[i];
	diff=k-(arr[1]+arr[0]);
	m=0;
	minimum=INT_MAX;
	pos=-1;
	while(m<=diff)
	{
		sum=0;
		newarr[0][m]=arr[0]+m;
		sum+=m;
		for (i = 1; i < n; i++)
		{
			newarr[i][m]=arr[i];
			temp=k-(newarr[i][m]+newarr[i-1][m]);
			if(temp>0)
			{
				newarr[i][m]+=temp;
				sum+=temp;
			}
		}
		if(sum<minimum)
		{
			minimum=sum;
			pos=m;
		}
		m++;
	}
	if(minimum==INT_MAX)
	{
		cout<<"0"<<endl;
		for (i = 0; i < n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return 0;
	}
	cout<<minimum<<endl;
	for ( i = 0; i < n; i++)
		cout<<newarr[i][pos]<<" ";
	cout<<endl;
	return 0;
}