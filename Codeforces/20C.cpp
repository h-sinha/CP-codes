#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define wt(x)	x.first
#define node(x)	x.second
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
vector<bool>visit(100002);
std::vector<ll> dist(100002);
ll modu=1000000007,p[100002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,vertex,k,a,b,c,source,dest;
	// cin>>t;
	// while(t--)
	// {
		priority_queue<pii,std::vector<pii>,greater<pii> > qq;
		cin>>vertex>>k;
		std::vector<pii> v[100002];
		while(k--)
		{
			cin>>a>>b>>c;
			v[a].pb(mp(c,b));
			v[b].pb(mp(c,a));
		}
	fill(dist.begin(), dist.end(),LLONG_MAX);
		source=1;dest=vertex;
		qq.push(mp(0,source));
	pii temp;

		dist[source]=0;
		int f=0;
	while(sz(qq))
	{
		temp=qq.top();
		visit[node(temp)]=1;
		qq.pop();
		FOR(i,0,sz(v[node(temp)]))
		{
			if(dist[node(v[node(temp)][i])]>=dist[node(temp)]+wt(v[node(temp)][i]))
			{
				if(visit[node(v[node(temp)][i])]){f=1;break;}
				dist[node(v[node(temp)][i])]=dist[node(temp)]+wt(v[node(temp)][i]);
				p[node(v[node(temp)][i])]=temp.second;
				// if(wt((v[node(temp)][i]))>rest1 && (wt((v[node(temp)][i]))>=rest2))flag=1;
				wt((v[node(temp)][i]))=dist[node(v[node(temp)][i])];
				qq.push(v[node(temp)][i]);
			}
		}
		if(f)break;
	}
		if(dist[dest]==LLONG_MAX)cout<<"-1"<<endl;
		else
		{
			std::vector<ll> ans;
			ll parent=dest;
			while(parent>0)
			{
				ans.pb(parent);
				parent=p[parent];
			}
			// cout<<sz(ans);
			RFOR(i,sz(ans)-1,0)cout<<ans[i]<<" ";
		}
	// }
	return 0;
}