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
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int parent[100002][22],level[100002];
std::vector<int> v[100002];
void dfs(int vertex,int parent,int _level=-1)
{
	level[vertex]=_level+1;
	for(auto &x:v[vertex])
		if(x!=parent)dfs(x,vertex,_level+1);
}
int LCA(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int dist=level[b]-level[a];
	int index=0;
	while(dist>0)
	{
		if(dist&1){b=parent[b][index];}
		dist>>=1;index++;
	}
	
	RFOR(i,18,0)
	{
		if(parent[a][i]!=-1 && parent[a][i]!=parent[b][i])
		{
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b)return a;
	return parent[a][0];
}
int solve(int s,int t,int f,int lst,int ltf,int lsf)
{
	if(lsf==ltf)return level[f]+level[lst]-2*level[lsf]+1;
	return 1+level[f]-max(level[lsf],level[ltf]);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int u,a,b,c,lab,lbc,lca,ans,n,q;
	 	cin>>n>>q;
	 	FOR(i,0,n+1)FOR(j,0,19)parent[i][j]=-1;
	 	FOR(i,2,n+1)
	 	{
	 		cin>>u;
	 		parent[i][0]=u;
	 		v[i].pb(u);
	 		v[u].pb(i);
	 	}
	 	dfs(1,-1);
	 	FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
	 	while(q--)
	 	{
	 		cin>>a>>b>>c;
	 		ans=0;
	 		lab=LCA(a,b);
			lbc=LCA(b,c);
			lca=LCA(c,a);
	 		ans=max(ans,solve(a,b,c,lab,lbc,lca));
	 		// cout<<ans<<endl;
	 		ans=max(ans,solve(a,c,b,lca,lbc,lab));
	 		// cout<<ans<<endl;
	 		ans=max(ans,solve(b,a,c,lab,lca,lbc));
	 		// cout<<ans<<endl;
	 		ans=max(ans,solve(b,c,a,lbc,lca,lab));
	 		// cout<<ans<<endl;
	 		ans=max(ans,solve(c,a,b,lca,lab,lbc));
	 		// cout<<ans<<endl;
	 		// cout<<solve(c,b,a,lbc,lab,lca);
	 		ans=max(ans,solve(c,b,a,lbc,lab,lca));
	 		cout<<ans<<ln;
	 	}
		return 0;
}