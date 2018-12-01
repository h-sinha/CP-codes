#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n;
	 	cin>>n;
	 	ll ans=0;
	 	if(n/100)
	 	{
	 		ans+=n/100;
	 		n-=(n/100)*100;
	 	}
	 	if(n/20)
	 	{
	 		ans+=n/20;
	 		n-=(n/20)*20;
	 	}
	 	if(n/10)
	 	{
	 		ans+=n/10;
	 		n-=(n/10)*10;
	 	}
	 	if(n/5)
	 	{
	 		ans+=n/5;
	 		n-=(n/5)*5;
	 	}
	 	if(n/1)
	 	{
	 		ans+=n/1;
	 		n-=(n/1)*1;
	 	}
	 	cout<<ans;

		return 0;
}