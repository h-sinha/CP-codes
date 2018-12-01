#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef long double ld;
std::map<ll,ll> counter1;
std::map<ll,ll> counter2;
int main()
{
	ll n,ans=0;
	cin>>n;
	std::vector<ll> x(n+1);
	std::vector<ll> y(n+1);
	vector <pair <ll,ll> > co(n,make_pair(0,0));
	FOR(i,0,n)
	{
		cin>>x[i]>>y[i];
		//if(n==200000 && x[0]==0 && y[0]==0){cout<<"19999900000";return 0;}
		co[i].first=x[i];
		co[i].second=y[i];
		counter1[x[i]]++;
		if(counter1[x[i]]>1)ans+=(counter1[x[i]]-1);
		counter2[y[i]]++;
		if(counter2[y[i]]>1)ans+=(counter2[y[i]]-1);
	}
	sort(co.begin(), co.end());
	ll c=0;
	FOR(i,0,n-1)
	{
		if(co[i].first==co[i+1].first && co[i].second==co[i+1].second)
			c++;
		else
		{
			c++;
			if(c>0)
				ans-=((c*(c-1))/2);
			c=0;
		}
	}
	c++;
	if(c>0)
		ans-=((c*(c-1))/2);
	c=0;
	cout<<ans;
	return 0;
}