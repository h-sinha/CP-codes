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
std::vector<pii> v;
bool comp(pii x,pii y)
{
	if(x.F==y.F)return x.S>y.S;
	return x.F<y.F;
}
ll mark[100002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,a,b,ans=0;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a>>b;
	 		v.pb(mp(a,b));
	 	}
	 	sort(all(v),comp);
	 	ll mx=v[0].S;
	 	FOR(i,1,n)
	 	{
	 		if(v[i].S<=mx){mark[i]=1;continue;}
	 		mx=v[i].S;
	 	}
	 	FOR(i,0,n)if(mark[i])ans++;
	 	cout<<ans;
		return 0;
}