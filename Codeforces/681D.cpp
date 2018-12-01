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
std::vector<int> v[L];
int a[L], indegree[L], gift[L], pos[L];
bool visit[L];
std::vector<int> ans;
void dfs()
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, cur=0, tmp, aa, bb;
	 	cin>>n>>m;
	 	queue <int> qq;
	 	while(m--)
	 	{
	 		cin >> aa >> bb;
	 		v[bb].pb(aa);
	 		indegree[aa]++;
	 	}
	 	FOR(i,1,n+1)if(indegree[i] == 0)qq.push(i);
	 	while(sz(qq))
	 	{
	 		tmp = qq.front();
	 		qq.pop();
	 		pos[tmp] = cur;
	 		a[cur++] = tmp;
	 		trace(v[tmp], x)
	 		{
	 			indegree[x]--;
	 			if(indegree[x] == 0)qq.push(x);
	 		}
	 	}
	 	FOR(i,1,n+1)cin>>gift[i];
		return 0;
}