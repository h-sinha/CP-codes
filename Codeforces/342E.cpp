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
const int L=1e5+7;
int parent[L][22],depth[L],subtree[L],centroidParent[L];
set <int> v[L];
std::vector<int> distanceis(L,INT_MAX/4);
void dfs(int vertex,int prev,int level)
{
	depth[vertex]=level+1;
	parent[vertex][0]=prev;
	for(auto &x:v[vertex])
		if(x!=prev)
			dfs(x,vertex,level+1);
}
int findCentroid(int vertex,int parent,int n)
{
	for(auto &x:v[vertex])
	{
		if(x!=parent && subtree[x]>n/2)
			return findCentroid(x,vertex,n);
	}
	return vertex;
}
int size(int vertex,int prev)
{
	subtree[vertex]=1;
	for(auto &x:v[vertex])
	{
		if(x==prev)continue;
		subtree[vertex]+=size(x,vertex);
	}
	return subtree[vertex];
}
void decompose(int vertex,int prev)
{
	size(vertex,-1);
	int c=findCentroid(vertex,-1,subtree[vertex]);
	centroidParent[c]=prev;
	for(auto &x:v[c])
	{
		v[x].erase(c);
		decompose(x,c);
	}
	v[c].clear();
}
int lca(int a,int b)
{
	if(depth[a]>depth[b])swap(a,b);
	int dist=depth[b]-depth[a];
	int index=0;
	// cout<<"s"<<dist<<endl;
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
int finddistance(int u,int v)
{
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}
int query(int vertex)
{
	int cur=vertex;
	int ans=INT_MAX;
	while(cur!=-1)
	{
		ans=min(ans,finddistance(vertex,cur)+distanceis[cur]);
		cur=centroidParent[cur];
	}
	return ans;
}
void update(int vertex)
{
	int cur=vertex;
	while(cur!=-1)
	{
		distanceis[cur]=min(distanceis[cur],finddistance(vertex,cur));
		// cout<<vertex<<" "<<cur<<" "<<finddistance(vertex,cur)<<endl;
		cur=centroidParent[cur];
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int type,n,a,b,q;
	 	cin>>n>>q;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].insert(b);
	 		v[b].insert(a);
	 	}
	 	FOR(i,0,n+1)
	 	{
	 		centroidParent[i]=-1;
	 		FOR(j,0,19)parent[i][j]=-1;
	 	}
	 	dfs(1,-1,-1);
	 	FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
		decompose(1,-1);
		update(1);
		while(q--)
		{
			cin>>type>>a;
			if(type==2)
				cout<<query(a)<<ln;
			else 
				update(a);
		}
		return 0;
}