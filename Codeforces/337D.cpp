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
std::vector<int> v[L];
int n,m,d,done[L],subsize[L],depth[L],parent[L],ma[L];
std::vector<int> mark;
std::vector<pii> vct;
int dfs(int vertex,int _parent,int _depth)
{
	// cout<<vertex<<endl;
	depth[vertex]=_depth+1;
	subsize[vertex]=1;
	parent[vertex]=_parent;
	trace(v[vertex],x)
		if(x!=_parent)
			subsize[vertex]+=dfs(x,vertex,_depth+1);
	return subsize[vertex];
}
int ans=0,cur;
void solve(int vertex,int _parent, int sofar)
{
	// cout<<vertex<<" & ";
	if(sofar>d && !ma[vertex])
	{
		done[vertex]=1;
		ans+=subsize[vertex];
		cout<<vertex<<" - "<<sofar<<" "<<cur<<endl;
		return;
	}
	if(done[vertex])return;
	trace(v[vertex],x)
		if(x!=_parent)
			solve(x,vertex,sofar+1);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>m>>d;
	 	int a,b;
	 	FOR(i,0,m)
	 	{
	 		cin>>a;
	 		mark.pb(a);
	 		ma[a]=1;
	 	}
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	dfs(1,-1,0);
	 	trace(mark,x)vct.pb(mp(depth[x],x));
	 	sort(all(vct));
	 	trace(vct,x)
	 	{
	 		cur=x.S;
	 		solve(x.S,parent[x.S],0);
	 	}
	 	cout<<ans;
		return 0;
}