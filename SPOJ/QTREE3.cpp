#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
const ll N=1e5+7;
vector <ll> adj[N];
ll baseArray[N], ptr;
ll chainNo, chainIndex[N], chainHead[N], posInBase[N];
ll depth[N], parent[N][32], subsize[N];
ll seg[N*6], queryarr[N*6];
void build(ll s,ll e,ll index)
{
	if(s>=e)
	{
		seg[index]=baseArray[s];
		return;
	}
	ll mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	seg[index]=min(seg[index<<1],seg[(index<<1)+1]);
	return;
}
ll queryseg(ll s,ll e,ll index,ll l,ll r)
{
	if(e<l || s>r )return LLONG_MAX;
	if(s>=l && e<=r)
		return seg[index];
	ll q1,q2,mid=(s+e)/2;
	q1=queryseg(s,mid,index<<1,l,r);
	q2=queryseg(mid+1,e,(index<<1)+1,l,r);
	return min(q1,q2);
}
void updateseg(ll s,ll e,ll index,ll updind)
{
	if(updind<s||updind>e)return;
	if(updind==s && updind==e)
	{
		seg[index]=baseArray[s];
		return;
	}
	ll mid=(s+e)/2;
	if(updind<=mid)
		updateseg(s,mid,index<<1,updind);
	else
		updateseg(mid+1,e,(index<<1)+1,updind);
	seg[index]=min(seg[index<<1],seg[(index<<1)+1]);
	return;
}
ll queryup(ll u, ll v) 
{
	if(u==v)
	{
		return baseArray[posInBase[u]];
	}
	ll uchain,vchain = chainIndex[v], ans =LLONG_MAX;
	while(1) 
	{
		uchain = chainIndex[u];
		if(uchain == vchain) 
		{
			if(u==v) break;
			ans=min(ans,queryseg(1,ptr,1,posInBase[v],posInBase[u]));
			// ans=min(ans,queryarr[1]);
			break;
		}
		ans=min(ans,queryseg(1,ptr,1,posInBase[chainHead[uchain]],posInBase[u]));
		// ans=min(ans,queryarr[1]);
		u = chainHead[uchain]; 
		u = parent[u][0]; 
	}
	return ans;
}
ll findancestor(ll vertex,ll dist)
{
	ll index=0;
	while(dist>0)
	{
		if(dist&1)vertex=parent[vertex][index];
		index++;
		dist>>=1;
	}
	return vertex;
}
void query(ll u) 
{
	ll ans=queryup(u,0);
	if(ans==LLONG_MAX)
		cout<<"-1"<<ln;
	else 
	{
		ans=depth[u]-ans;
		ans=findancestor(u,ans);
		cout<<ans+1<<ln;
	}
}
void HLD(ll curNode,ll prev) 
{
	if(chainHead[chainNo] == -1) 
		chainHead[chainNo] = curNode; 
	chainIndex[curNode] = chainNo;
	posInBase[curNode] = ptr; 
	baseArray[ptr++] = LLONG_MAX;
	ll special = -1,ncost;
	FOR(i,0,sz(adj[curNode]))
	{
		if(adj[curNode][i] != prev) 
			if(special == -1 || subsize[special] < subsize[adj[curNode][i]]) 
				special = adj[curNode][i];
	}
 
	if(special != -1) 
		HLD(special, curNode);
 
	FOR(i,0,sz(adj[curNode]))
	{ 
		if(adj[curNode][i]!=prev && special!=adj[curNode][i]) 
		{
			chainNo++;
			HLD(adj[curNode][i],curNode);
		}
	}
	return;
}
void dfs(ll vertex,ll prev,ll _depth) 
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
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	ll t,u,v,c,a,b,q;
	ptr = 1;
	ll n;
	cin>>n>>q;
	FOR(i,0,n)
	{
		chainHead[i]=-1;
		FOR(j,0,30)parent[i][j] = -1;
	}
	FOR(i,1,n)
	{
		cin>>u>>v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	chainNo = 0;
	dfs(0,-1,0); 
	HLD(0,-1);
	ptr--;
	build(1,ptr,1);
	FOR(j,1,30)
		FOR(i,0,n+1)
	 		if(parent[i][j-1]!=-1)
	 			parent[i][j]=parent[parent[i][j-1]][j-1];
	while(q--) 
	{
		cin>>a>>b;
		if(a)
			query(b-1);
		else
		{
			if(baseArray[posInBase[b-1]]==LLONG_MAX)baseArray[posInBase[b-1]]=depth[b-1];
			else baseArray[posInBase[b-1]]=LLONG_MAX;
			updateseg(1,ptr,1,posInBase[b-1]);
		}
	}
}  
