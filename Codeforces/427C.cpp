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
const int L=1e5+7;
std::map<ll,ll> counter;
std::vector<int> org[L],rev[L];
stack <int> STACK;
std::vector<bool> visit(L);
std::vector<bool> visit1(L);
ll cost[L],xx=1e9+7;
void dfs(int vertex)
{
	if(visit[vertex])return;
	visit[vertex]=1;
	trace(org[vertex],x)
		dfs(x);
	STACK.push(vertex);
	return;
}
ll dfs1(int vertex)
{
	if(visit1[vertex])return INT_MAX;
	counter[cost[vertex]]++;
	ll co=INT_MAX;
	visit1[vertex]=1;
	trace(rev[vertex],x)
		co=min(co,dfs1(x));
	return min(cost[vertex],co);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,a,co=0,b,m,ways=1,ans=0;
	 	cin>>n;
	 	FOR(i,1,n+1)cin>>cost[i];
	 	cin>>m;
	 	while(m--)
	 	{
	 		cin>>a>>b;
	 		org[a].pb(b);
	 		rev[b].pb(a);
	 	}
	 	FOR(i,1,n+1)
	 		if(!visit[i])
	 			dfs(i);
	 	while(!STACK.empty())
	 	{
	 		while(!STACK.empty() && visit1[STACK.top()])STACK.pop();
	 		if(STACK.empty())break;
	 		int cur=STACK.top();
	 		STACK.pop();
	 		co=dfs1(cur);
	 		ans+=co;
	 		ways=(ways%xx * counter[co]%xx)%xx;
	 		counter.clear();
	 	}
	 	cout<<ans<<" "<<ways;
		return 0;
}