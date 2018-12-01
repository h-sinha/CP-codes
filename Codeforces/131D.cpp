#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
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
std::vector<int> v[3002];
std::vector<bool> visit(3002);
int mark[3002],dist[3002],par=INT_MAX;
bool dfs(int vertex,int parent)
{
	if(visit[vertex]){par=vertex;return mark[vertex]=1;}
	visit[vertex]=1;
	trace(v[vertex],x)
		if(x!=parent && vertex!=par)
		mark[vertex]+=dfs(x,vertex);
	if(vertex==par)return 0;
	return mark[vertex];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a,b,n;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	dfs(1,-1);
	 	FOR(i,1,n+1)dist[i]=INT_MAX;
	 	queue <int> q;
	 	FOR(i,1,n+1)
	 	{
	 		if(mark[i])
	 		{
	 			dist[i]=0;
	 			q.push(i);
	 		}
	 	}
	 	int tmp;
	 	while(sz(q))
	 	{
	 		tmp=q.front();
	 		q.pop();
	 		trace(v[tmp],x)
	 		{
	 			if(dist[x]>dist[tmp]+1)
	 			{
	 				dist[x]=dist[tmp]+1;
	 				q.push(x);
	 			}
	 		}
	 	}
	 	FOR(i,1,n+1)cout<<dist[i]<<" ";
		return 0;
}