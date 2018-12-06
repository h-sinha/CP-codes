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
int a[L],curtime=1,level[L],parent[L][22],counter[L],start[L],ending[L],base[L];
std::vector<int> adj[L];
string out[L];
struct node
{
	int l,r,c,q,LCA;
};
void eulerTour(int vertex,int _parent,int _depth)
{
	level[vertex]=1+_depth;
	parent[vertex][0]=_parent;
	start[vertex]=curtime++;
	base[curtime-1]=a[vertex];
	trace(adj[vertex],x)
		if(x!=_parent)
			eulerTour(x,vertex,_depth+1);
	ending[vertex]=curtime++;
	base[curtime-1]=a[vertex];
}
int lca(int a,int b)
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
bool comp(node x,node y)
{
	if(x.l/900==y.l/900)return x.r<y.r;
	return x.l<y.l;
}
void add(int idx) 
{
	counter[base[idx]]++;
}
void remove(int idx) 
{
	counter[base[idx]]--;
}
int main()
{
		int n,m,u,v,LCA,l,r,c;
		node temp;
		std::vector<node> vct;
		while(scanf("%d%d",&n,&m)!=EOF)
		{
			FOR(i,1,n+1)scanf("%d",&a[i]);
			FOR(i,0,n-1)
			{
				scanf("%d%d",&u,&v);
				adj[u].pb(v);
				adj[v].pb(u);
			}
			curtime=1;
			eulerTour(1,-1,0);
			FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
			FOR(i,0,m)
			{
				scanf("%d%d%d",&u,&v,&c);
				if(start[u]>start[v])swap(u,v);
				LCA=lca(u,v);
				temp.l=ending[u],temp.r=start[v],temp.c=c,temp.q=i;
				if(LCA==u)temp.LCA=-1;
				else temp.LCA=a[LCA];
				vct.pb(temp);
			}
			sort(all(vct),comp);
			l=1,r=0;
			trace(vct,x)
			{	
				while(r<x.r)
				{
					++r;
					add(r);
				}
				while(r>x.r)
				{
					remove(r);
					--r;
				}
				while(l<x.l)
				{
					remove(l);
					l++;
				}
				while(l>x.l)
				{
					--l;
					add(l);
				}
				if(x.LCA==x.c || counter[x.c]>0)out[x.q]="Find";
				else out[x.q]="NotFind";
			}
			vct.clear();
			FOR(i,0,m)cout<<out[i]<<ln;
			printf("\n");

		}
		return 0;
}