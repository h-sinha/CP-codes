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
ll m=1e9+7;
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
	 	ll n,x,ar[100002],sumis=0;
	 	cin>>n>>x;
	 	std::vector<ll> v;
	 	FOR(i,0,n){cin>>ar[i];sumis+=ar[i];}
	 	FOR(i,0,n)
	 	{
	 		if(counter.find(sumis-ar[i])==counter.end())
	 		v.pb(sumis-ar[i]);
	 		counter[sumis-ar[i]]++;
	 	}
	 	sort(v.begin(),v.end());
	 	ll co=0,ans=0,tmp=0;
	 	int cur=0;
	 	while(1)
	 	{
			co+=(v[cur]-co);
				 		
	 	}

		return 0;
}