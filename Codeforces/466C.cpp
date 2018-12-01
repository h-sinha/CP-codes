#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,counter=0,i,ans=0,sum;
	cin>>n;
	vector <ll> v(n+1);
	vector <ll> cum(n+1);
	for(i=1;i<=n;i++)
		cin>>v[i];
	cum[1]=v[1];
	for(i=1;i<=n;i++)
		cum[i]=cum[i-1]+v[i];
	if(cum[n]%3!=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	sum=cum[n]/3;
	for ( i = 1; i <n; i++)
	{
		if(cum[i]==sum*2)
			ans+=counter;
		if(cum[i]==sum)
			counter++;
	}
	cout<<ans<<endl;
	return 0;
}