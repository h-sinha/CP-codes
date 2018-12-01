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
const int L=2e6+7;
std::vector<int> v[L], adj[L];
int d[L], deg[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, k, mx = INT_MIN;
	 	cin >> n >> k;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> d[i];
	 		v[d[i]].pb(i);
	 		mx = max(d[i],mx);
	 	}
	 	if(sz(v[0]) != 1)
	 	{
	 		cout << "-1";
	 		return 0;
	 	}
	 	int cur = 0, edges = 0;
	 	FOR(i,1,mx+1)
	 	{
	 		cur = 0;
	 		trace(v[i], x)
	 		{
	 			if(cur >= sz(v[i-1]) || deg[x] == k)
	 			{
	 				cout << "-1";
	 				return 0;
	 			}
	 			edges++;
	 			adj[ v[i-1][cur] ].pb(x);
	 			deg[ v[i-1][cur] ]++;
	 			deg[x]++;
	 			if(deg[ v[i-1][cur] ] == k)cur++;
	 		}
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(deg[i]>k)
	 		{
	 			cout<<"-1";
	 			return 0;
	 		}
	 	}
	 	cout << edges <<ln;
	 	FOR(i,1,n+1)
	 		trace(adj[i], x)cout<<i<<" "<<x<<ln;
		return 0;
}