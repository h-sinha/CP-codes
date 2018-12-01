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
std::vector<ll> ans;
ll n;
bool calc(ll num)
{
	ll tmp=num;
	while(tmp>0)
	{
		num+=(tmp%10);
		tmp/=10;
	}
	return num==n;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n;
	 	FOR(i,0,100)
	 	{
	 		if(n-i<0)break;
	 		if(calc(n-i))ans.pb(n-i);
	 	}
	 	sort(all(ans));
	 	cout<<sz(ans)<<ln;
	 	trace(ans,x)cout<<x<<ln;
		return 0;
}