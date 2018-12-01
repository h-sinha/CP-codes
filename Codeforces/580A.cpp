#include<bits/stdc++.h>
using namespace std;
int n,arr[100002];
int func();
int main()
{
	int i;
	cin>>n;
	for (i = 0; i < n; i++)
		cin>>arr[i];
	cout<<func()<<endl;
	return 0;
}
int func()
{
	int seq=arr[0],i,count=1,max=-1;
	for(i=1;i<n;i++)
	{
		if(arr[i]>=seq)
		{
			seq=arr[i];
			count++;
		}
		else
		{
			if(max<count)
				max=count;
			seq=arr[i];
			count=1;
		}
	}
	if(count>max)
		max=count;
		return max;
}