#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
std::vector<int>ans;
std::vector<pii> v[L];
int dp[L],co[L];
int assign(int vertex,int parent,int prv)
{
	int counter=0;
	if(prv==2)dp[vertex]++;
	trace(v[vertex],x)
	{
		if(x.F!=parent)
		{
			if(x.S==2)dp[vertex]++;
			dp[vertex]+=assign(x.F,vertex,x.S);
		}
	}
	return dp[vertex];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,x,y,t;
	 	cin>>n;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>x>>y>>t;
	 		v[x].pb(mp(y,t));
	 		v[y].pb(mp(x,t));
	 		if(t==2)co[x]++,co[y]++;
	 	}
	 	// cout<<ln;
	 	assign(1,-1,0);
	 	// FOR(i,1,n+1)debug2(co[i],dp[i]);
	 	FOR(i,1,n+1)
	 		if(co[i] && dp[i]==1)ans.pb(i);
	 	cout<<sz(ans)<<ln;
	 	trace(ans,x)cout<<x<<" ";
		return 0;
}