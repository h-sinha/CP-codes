#include<bits/stdc++.h>
using namespace std;
int countz[102],counto[102],maxsofar[102];
int main()
{
	int n,arr[102],i,j,temp,flip,maximum;
	cin>>n;
	for (i = 1; i <= n; i++)
		cin>>arr[i];
	if(arr[1]==1)
	{
		countz[1]=0;
		counto[1]=1;
	}
	else
	{
		countz[1]=1;
		counto[1]=0;
	}
	for(i=2;i<=n;i++)
	{
		if(arr[i]==1)
			counto[i]++;
		else
			countz[i]++;
		counto[i]+=counto[i-1];
		countz[i]+=countz[i-1];
	}
	countz[0]=0,counto[0]=0;	
	for(i=1;i<=n;i++)
	{
		maxsofar[i]=countz[i];
		for(j=i;j<=n;j++)
		{
			temp=countz[j]-countz[i-1]+counto[n]-counto[j]+counto[i-1];
			if(temp>maxsofar[i])
				maxsofar[i]=temp;
		}
	}
	maximum=-INT_MAX;
	for(i=1;i<=n;i++)
	{
		if(maximum<maxsofar[i])
			maximum=maxsofar[i];
	}
	cout<<maximum<<endl;
	return 0;
}