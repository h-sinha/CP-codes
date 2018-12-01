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
std::vector<int> v[L],vect;
int f,cur;
std::vector<bool> visit(L),grey(L);
void dfs(int vertex,int parent)
{
	// cout<<vertex<<" & ";
	if(visit[vertex])
	{
		f=1;
		return;
	}
	grey[vertex] = 1;
	visit[vertex] = 1;
	trace(v[vertex],x)
		if(x!=parent)
		dfs(x,vertex);
	grey[vertex] = 0;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,k,ans=0,a,b;
	 	cin >> n >> k;
	 	FOR(i,0,k)
	 	{
	 		cin >> a >> b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	FOR(i,1,n+1)
		{
			if(!visit[i])
			{
				f=0,cur = i;
				dfs(i,-1);
				if(!f)
				{
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
}