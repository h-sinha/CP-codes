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
const int L=2e5+7;
map<ll,ll> counter;
ll arr[L],t=0,start[L],ending[L];
std::vector<int> v[L];
void dfs(int vertex,int parent)
{
	start[vertex]=t;
	arr[t]=vertex;
	t++;
	trace(v[vertex],x)
	{
		if(x!=parent)dfs(x,vertex);
	}
	ending[vertex]=t-1;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,q,u,a,idx,k;
	 	cin>>n>>q;
	 	FOR(i,2,n+1)
	 	{
	 		cin>>a;
	 		v[i].pb(a);
	 		v[a].pb(i);
	 	}
	 	FOR(i,1,n+1)sort(all(v[i]));
	 	dfs(1,-1);
	 	// FOR(i,0,t)cout<<arr[i]<<" ";
	 	// cout<<ln;
	 	// FOR(i,1,n+1)cout<<i<<"- "<<start[i]<<" "<<ending[i]<<ln;
		while(q--)
		{
			cin>>u>>k;
			idx=start[u]+k-1;
			if(idx>ending[u])cout<<"-1\n";
			else cout<<arr[idx]<<ln;
		}
		return 0;
}