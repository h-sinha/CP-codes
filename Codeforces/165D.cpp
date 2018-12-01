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
const int N=1e5+7;
vector <int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainIndex[N], chainHead[N], posInBase[N];
int depth[N], parent[N][20], otherEnd[N], subsize[N];
int seg[N*6], queryarr[N*6];
void build(int s, int e,int index) 
{
	if(s == e-1) 
	{
		seg[index] = baseArray[s];
		return;
	}
	int mid=(s+e)>>1;
	build(s,mid,index<<1);
	build(mid,e,(index<<1)+1);
	seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
}
void updateseg(int s,int e,int index,int pos, int val) 
{
	if(s>pos || e<=pos) return;
	if(s==pos && s==e-1) 
	{
		seg[index]=val;
		return;
	}
	int mid=(s+e)>>1;
	updateseg(s,mid,index<<1,pos,val);
	updateseg(mid,e,(index<<1)+1,pos,val);
	seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
	return;
}
void queryseg(int s,int e,int index,int l,int r) 
{
	if(s>=r || e<=l) 
	{
		queryarr[index]=-1;
		return;
	}
	if(s>=l && e<=r) 
	{
		queryarr[index]=seg[index];
		return;
	}
	int mid=(s+e)>>1;
	queryseg(s,mid,index<<1,l,r);
	queryseg(mid,e,(index<<1)+1,l,r);
	queryarr[index]=max(queryarr[index<<1],queryarr[(index<<1)+1]);
}
int queryup(int u, int v) 
{
	if(u==v) return 0;
	int uchain,vchain = chainIndex[v], ans = -1;
	while(1) 
	{
		uchain = chainIndex[u];
		if(uchain == vchain) 
		{
			if(u==v) break;
			queryseg(0,ptr,1,posInBase[v]+1,posInBase[u]+1);
			ans=max(ans,queryarr[1]);
			break;
		}
		queryseg(0,ptr,1,posInBase[chainHead[uchain]],posInBase[u]+1);
		ans=max(ans,queryarr[1]);
		u = chainHead[uchain]; 
		u = parent[u][0]; 
	}
	return ans;
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
	
	RFOR(i,15,0)
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
	int ans = queryup(u,lca);
	if(ans!=0)
	{
		cout<<"-1\n";
		return;
	}
	int temp = queryup(v,lca);
	if(max(temp,ans)!=0)cout<<"-1\n";
	else cout<<depth[u]+depth[v]-2*depth[lca]<<"\n";
}
void change(int i, int val) 
{
	int u = otherEnd[i];
	// cout<<"s"<<u<<ln;
	updateseg(0,ptr,1,posInBase[u], val);
}
void HLD(int curNode,  int prev) 
{
	if(chainHead[chainNo] == -1) 
	{
		chainHead[chainNo] = curNode; 
	}
	chainIndex[curNode] = chainNo;
	posInBase[curNode] = ptr; 
	baseArray[ptr++] = 0;
 
	int special = -1,ncost;
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
		HLD(special,  curNode);
 
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
			// otherEnd[indexx[vertex][i]]=vertex;
			otherEnd[indexx[vertex][i]] = adj[vertex][i];
			dfs(adj[vertex][i],vertex, _depth+1);
			subsize[vertex] += subsize[adj[vertex][i]];
		}
	}
}
int main() 
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int type,t,u,v,c;
		ptr = 0;
		int n;
		cin>>n;
		FOR(i,0,n)
		{
			chainHead[i] = -1;
			FOR(j,0,18)parent[i][j] = -1;
		}
		// cout<<"S"<<n<<endl;
		FOR(i,1,n)
		{
			cin>>u>>v;
			u--,v--;
			adj[u].push_back(v);
			indexx[u].push_back(i);
			adj[v].push_back(u);
			indexx[v].push_back(i);
		}
		// cout<<"sda"<<n;
		chainNo = 0;
		dfs(0, -1,0); 
		HLD(0,  -1); 
		FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
 		cin>>t;
 		while(t--)
 		{
 			cin>>type;
 			if(type==1)
 			{
 				cin>>u;
 				change(u,0);
 			}
 			else if(type==2)
 			{
 				cin>>u;
 				change(u,1);
 			}
 			else 
 			{
 				cin>>u>>v;
 				u--,v--;
 				query(u,v);
 			}
 		}
	 return 0;
}