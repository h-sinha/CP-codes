#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, a, b, tmp,xx, yy, cur;
	 	cin >> n >> a >> b;
	 	n*=6;
	 	if(a*b >= n)
	 	{
	 		cout<<a*b<<ln;
	 		cout<<a<<" "<<b;
	 		return 0;
	 	}
	 	ll mx=1e18;
	 	ll aa = min(a,b), bb=max(a,b);
	 	for (ll i = aa; i*i <= n; ++i)
	 	{
	 		cur = i;
	 		tmp =((n+i-1)/i);
	 		if(tmp<bb)continue;
	 		if(cur*tmp>=n && cur*tmp<=mx)
	 		{
	 			mx = cur*tmp;
	 			xx = cur;
	 			yy = tmp;
	 		}
	 	}
	 	if(xx < a || yy <b)swap(xx,yy);
	 	cout<<mx<<ln;
	 	cout<<xx<<" "<<yy;
		return 0;
}