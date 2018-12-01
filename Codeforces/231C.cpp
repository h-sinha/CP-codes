#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int arr[100002],n,mod,max,i,d=0,k;
	cin>>n>>k;
	for (i=0;i<n;i++)
		cin>>arr[i];
	mod=1;
	sort(arr,arr+n);
	max=arr[0];
	long long int l=0;
	for(i=1;i<n;i++)
	{
		d+=(arr[i]-arr[i-1])*(i-l);
		while(d>k)
		{
			d-=arr[i]-arr[l];
			l++;
		}
		if(i-l+1>mod)
		{
			mod=i-l+1;
			max=arr[i];
		}
	}
	cout<<mod<<" "<<max<<endl;
	return 0;
}