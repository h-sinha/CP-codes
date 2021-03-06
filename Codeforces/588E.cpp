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
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
const int N=1e5+7;
vector <int> adj[N],id[N];
int  ptr;
int chainNo, chainIndex[N], chainHead[N], posInBase[N];
int depth[N], parent[N][20], otherEnd[N], subsize[N];
int tot;
set<int>SET,seg[4*N],baseArray[N];

void build(int s, int e,int index) 
{
	if(s == e-1) 
	{
		trace(baseArray[s],x)seg[index].insert(x);
		// cout<<s<<" "<<e<<" - "<<sz(seg[index])<<" "<<sz(baseArray[s])<< ln;
		return;
	}
	int mid=(s+e)>>1;
	build(s,mid,index<<1);
	build(mid,e,(index<<1)+1);
	trace(seg[index<<1],x)seg[index].insert(x);
	trace(seg[(index<<1)+1],x)seg[index].insert(x);
	return;
	// seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
}
void queryseg(int s,int e,int index,int l,int r) 
{
	// cout<<l<<" _ "<<r<<ln;
	if(s>=r || e<=l) 
	{
		// queryarr[index]=-1;
		return;
	}
	if(s>=l && e<=r) 
	{
		int cur=INT_MAX;
		// cout<<s<<" "<<e<<" - "<<l<<" "<<r<<" "<<sz(seg[index])<<ln;
		if(sz(SET))cur=*(--SET.end());
		trace(seg[index],x)
		{
			if(x>cur && sz(SET)>=tot)break;
			SET.insert(x);
			cur=*(--SET.end());
			// cout<<x<<" ";
		}
		while(sz(SET)>tot)SET.erase(--SET.end());
		// queryarr[index]=seg[index];
		return;
	}
	int mid=(s+e)>>1;
	queryseg(s,mid,index<<1,l,r);
	queryseg(mid,e,(index<<1)+1,l,r);
	// queryarr[index]=max(queryarr[index<<1],queryarr[(index<<1)+1]);
}
void queryup(int u, int v) 
{
	if(u==v)
	{
	 	return ;
	}
	// if(posInBase[u]>posInBase[v])swap(u,v);
	int uchain,vchain = chainIndex[v], ans = -1;
	while(1) 
	{
		uchain = chainIndex[u];
		if(uchain == vchain) 
		{
			if(u==v) break;
			queryseg(0,ptr,1,posInBase[v],posInBase[u]+1);
			break;
		}
		queryseg(0,ptr,1,posInBase[chainHead[uchain]],posInBase[u]+1);
		u = chainHead[uchain]; 
		u = parent[u][0]; 
	}
	return ;
}
 
int LCA(int u, int v) 
{
	if(depth[u]>depth[v])swap(u,v);
	int dist=depth[v]-depth[u];
	int index=0;
	while(dist>0)
	{
		if(dist&1)v=parent[v][index];
		dist>>=1;index++;
	}
	
	RFOR(i,16,0)
	{
		if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i])
		{
			u=parent[u][i];
			v=parent[v][i];
		}
	}
	if(u==v)return u;
	return parent[u][0];
}
void query(int u, int v) 
{
	int lca = LCA(u, v);
	// cout<<u<<" - "<<v<<"";
	queryup(u,lca);
	queryup(v,lca); 
	queryseg(0,ptr,1,posInBase[lca],posInBase[lca]+1);
	return;
}
void HLD(int curNode,int prev) 
{
	if(chainHead[chainNo] == -1) 
	{
		chainHead[chainNo] = curNode; 
	}
	chainIndex[curNode] = chainNo;
	posInBase[curNode] = ptr;
	trace(id[curNode],x)
	{
		// cout<<curNode<<" _ "<<x<<" "<<ptr<<ln;
		baseArray[ptr].insert(x);
	}
 	ptr++;
	int special = -1;
	FOR(i,0,sz(adj[curNode]))
	{
		if(adj[curNode][i] != prev) 
		{
			if(special == -1 || subsize[special] < subsize[adj[curNode][i]]) 
			{
				special = adj[curNode][i];
			}
		}
	}
 
	if(special != -1) 
		HLD(special, curNode);
 
	FOR(i,0,sz(adj[curNode]))
	{ 
		if(adj[curNode][i]!=prev && special!=adj[curNode][i]) 
		{
			chainNo++;
			HLD(adj[curNode][i], curNode);
		}
	}
	return;
}
void dfs(int vertex,int prev,int _depth) 
{
	parent[vertex][0] = prev;
	depth[vertex] = _depth;
	subsize[vertex] = 1;
	FOR(i,0,sz(adj[vertex]))
	{
		if(adj[vertex][i] != prev) 
		{
			dfs(adj[vertex][i],vertex, _depth+1);
			subsize[vertex] += subsize[adj[vertex][i]];
		}
	}
	return;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,q,u,v,c,cc;
	cin>>n>>m>>q;
	FOR(i,0,n)
	{
		chainHead[i] = -1;
		FOR(j,0,18)parent[i][j] = -1;
	}
	FOR(i,1,n)
	{
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	FOR(i,1,m+1)
	{
		cin>>cc;
		cc--;
		id[cc].pb(i);
	}
	chainNo = 0;
	dfs(0, -1,0); 
	HLD(0,  -1); 
	build(0,ptr,1); 
	// FOR(i,0,n)cout<<i<<" & "<<posInBase[i]<<ln;
	FOR(j,1,19)
	FOR(i,0,n)
		if(parent[i][j-1]!=-1)
	 		parent[i][j]=parent[parent[i][j-1]][j-1];
	while(q--)
	{
		// cout<<"ho ";
		cin>>u>>v>>tot;
		u--,v--;
		query(u,v);
		cout<<sz(SET)<<" ";
		trace(SET,x)cout<<x<<" ";
		cout<<ln;
		SET.clear();
	}
	// FOR(i,0,n)
	// {
	// 	SET.clear();
	// 	query(i,i);
	// 	cout<<i<<" -> "
	// 	trace(SET,x)cout<<x<<" ";
	// 	cout<<ln;
	// }
	// FOR(i,0,n){cout<<i<<" -> ";trace(id[i],x)cout<<x<<" ";cout<<ln;}
	return 0;
}