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
map<pii,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll l,r,x,y;
	 	cin>>l>>r>>x>>y;
	 	ll prod=x*y;
	 	ll ans=0;
	 	if(l%x)l=(l/x +1)*x;
	 	for (ll i = l; i <=sqrt(prod) && i<=y; i+=x)
	 	{
	 		if(prod%i)continue;
	 		if(__gcd(i,prod/i)!=x || prod/i < i || prod/i>r)continue;
	 		if(prod/i !=i)ans+=2;
	 		else ++ans; 
	 	}
	 	cout<<ans<<ln;
		return 0;
}