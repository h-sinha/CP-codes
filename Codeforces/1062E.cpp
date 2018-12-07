#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
map<ll,ll> counter;
std::vector<int> v[L];
int level[L],parent[L][22], enter, starttime[L];
void dfs(int vertex,int pr,int lvl)
{
	parent[vertex][0]=pr;
	level[vertex]=lvl;
	starttime[vertex] = enter++;
	trace(v[vertex], x)
		if(x!=pr)dfs(x,vertex,lvl+1);
}
int lca(int a,int b)
{
	if(a==0)return b;
	else if(b==0)return a;
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
int size_of_base;
std::vector<int> minTime(4*L, 100001), maxTime(4*L), segLCA(4*L);
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		minTime[index] = start;
		maxTime[index] = start;
		segLCA[index] = start;
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	if(starttime[minTime[2*index]] < starttime[minTime[2*index + 1]])minTime[index] = minTime[2*index];
	else minTime[index] = minTime[2*index + 1];

	if(starttime[maxTime[2*index]] > starttime[maxTime[2*index + 1]])maxTime[index] = maxTime[2*index];
	else maxTime[index] = maxTime[2*index + 1];
	
	segLCA[index] = lca(segLCA[2*index], segLCA[2*index+1]);
	return;
}
int query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return 100001;
	if(start >= l && end <= r)
	{
		return minTime[index];
	}
	int mid = (start + end)/2;
	int query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	if(starttime[query_left] < starttime[query_right])return query_left;
	else return query_right;
}
int querymax(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return 0;
	if(start >= l && end <= r)
	{
		return maxTime[index];
	}
	int mid = (start + end)/2;
	int query_left, query_right;
	query_left = querymax(l, r, start, mid, 2*index );
	query_right = querymax(l, r, mid+1, end, 2*index + 1);
	if(starttime[query_left] > starttime[query_right])return query_left;
	else return query_right;
}
int findLCA(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return 0;
	if(start >= l && end <= r)
	{
		return segLCA[index];
	}
	int mid = (start + end)/2;
	int query_left, query_right;
	query_left = findLCA(l, r, start, mid, 2*index );
	query_right = findLCA(l, r, mid+1, end, 2*index + 1);
	return lca(query_right, query_left);
}

int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, q, a;
	 	cin>>n >> q;
	 	FOR(i,2,n+1)
	 	{
	 		cin >> a ;
	 		v[i].pb(a);
	 		v[a].pb(i);
	 		parent[i][0] = a;
	 	}
	 	starttime[100001] = INT_MAX;
	 	starttime[0] = -1;
	 	dfs(1,-1,0);
	 	FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
		size_of_base = n;
		build();
		int l, r, v2, v1, tmp2, tmp1, tmp3;
		while(q--)
		{
			cin >> l >> r;
			v1 = querymax(l, r);
			v2 = query(l, r);
			tmp1 = tmp2 =0;
			tmp1 = lca(findLCA(l, v1-1), findLCA(v1+1, r));
			tmp2 = lca(findLCA(l, v2-1), findLCA(v2+1, r));
			if(level[tmp1] > level[tmp2])cout<<v1<<" "<<level[tmp1]<<ln;
			else cout<<v2<<" "<<level[tmp2]<<ln;
		}
		return 0;
}
