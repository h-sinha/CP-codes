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
ll w[50002],n;
std::vector<int> v[50002];
multiset<pii>SET[50002];
void bfs(int vertex)
{
	int depth[50002],head;
	FOR(i,1,n+1)depth[i]=-1;
	depth[vertex]=0;
	SET[vertex].insert({0,w[vertex]});
	queue <int> q;
	depth[vertex]=0;
	q.push(vertex);
	while(sz(q))
	{
		head=q.front();
		q.pop();
		trace(v[head],x)
		{
			if(depth[x]==-1)
			{
				depth[x]=depth[head]+1;
				// cout<<x<<"-";
				SET[vertex].insert({depth[x],w[x]});
				q.push(x);
			}
		}
	}
	// cout<<vertex<<ln;
	// trace(SET[vertex],x)cout<<x.F<<" "<<x.S<<ln;
	// cout<<ln;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a,b,k,ans,m;
	 	cin>>n;
	 	FOR(i,1,n+1)cin>>w[i];
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	FOR(i,1,n+1)
	 		bfs(i);
	 	cin>>m;
	 	while(m--)
	 	{
	 		cin>>a>>b>>k;
	 		multiset<ll>query;
	 		trace(SET[a],x)
	 		{
	 			if(x.F>b)break;
	 			query.insert(x.S);
	 		}
	 		trace(query,x)
	 		{
	 			k--;
	 			if(k==0)
	 			{
	 				ans=x;
	 				break;
	 			}
	 		}
	 		if(k)cout<<"-1\n";
	 		else cout<<ans<<ln;
	 	}
		return 0;
}