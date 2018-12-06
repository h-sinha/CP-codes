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
const int L=2e5+7;
ll baseArray[L], seg[4*L],size_of_base,start[L],endi[L],posint[L];
int ti=1;
std::vector<int> v[L];
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	seg[index] = max( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
void update(int updateindex, int start = 1, int end = size_of_base, int index = 1)
{
	if(updateindex < start || updateindex > end)return;
	if( start == end && updateindex == start )
	{
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;
	update(updateindex, start, mid, 2*index );
	update(updateindex, mid+1, end, 2*index + 1);
	seg[index] = max( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
ll query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return 0;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	int mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return max(query_left, query_right);
}
int ss[L];
int dfs(int vertex,int parent)
{
	start[vertex] = ti++;
	baseArray[ti-1] = vertex;
	posint[vertex] = ti-1;
	ss[vertex] = 1;
	trace(v[vertex],x)
		if(x!=parent)
			ss[vertex]+= dfs(x,vertex);
	endi[vertex]=ti-1;
	return ss[vertex];
}
bool comp(int x,int y)
{
	return ss[x]<ss[y];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,tt,n,m,a,b,tmp;
	 ll auxi;
	cin >> t;
	std::vector<int> qq;
	FOR(kk,0,t)
	{
		cin >> n >> m >> a >> b;
		ll ans=0;
		FOR(i,0,n)v[i].clear();
		FOR(i,1,n)
		{
			cin >>tt;
			v[tt].pb(i);
			v[i].pb(tt);
		}
		qq.clear();
		ti=1;
		dfs(0,-1);
		size_of_base=ti-1;
		build();
		FOR(i,0,m)
		{
			tmp = (a*i+b)%n;
			qq.pb(tmp);
		}
		sort(all(qq),comp);
		FOR(i,0,m)
		{
			auxi =query(start[qq[i]],endi[qq[i]]);
			ans+=max(auxi,0LL);
			if(auxi!=0)
			{
				// cout<<i<<" "<<auxi<<endl;
				baseArray[posint[auxi]]=0;
				update(posint[auxi]);
			}
		}
		cout<<"Case #"<<kk+1<<": "<<ans<<ln;
	}
	return 0;
}
