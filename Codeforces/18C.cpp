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
ll a[100002],cumsum[100002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n;
	 	cin>>n;
	 	FOR(i,0,n)cin>>a[i];
	 	cumsum[0]=a[0];
		FOR(i,1,n)
		{
			cumsum[i]+=cumsum[i-1];
			cumsum[i]+=a[i];
		}
		ll ans=0;
		FOR(i,0,n-1)
			if(cumsum[i] == cumsum[n-1]-cumsum[i])ans++;
		cout<<ans;
		return 0;
}