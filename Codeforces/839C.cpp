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
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
ld co,sumis;
std::vector<int> v[L];
ld dp[L];
ld dfs(int vertex,int parent)
{
	trace(v[vertex],x)
		if(x!=parent)
			dp[vertex]+=dfs(x,vertex);
	dp[vertex]/=sz(v[vertex]);
	dp[vertex]+=1;
	return dp[vertex];
}
int main()
{
		// ios_base::sync_with_stdio(false);
	 	// cin.tie(NULL);
	 	int n,a,b;
	 	cin>>n;
	 	if(n==1)
	 	{
	 		cout<<"0";
	 		return 0;
	 	}
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	// dfs(1,-1,0);
	 	// cout<<sumis<<" "<<co<<ln;
	 	printf("%.10Lf\n",dfs(1,-1));
		return 0;
}