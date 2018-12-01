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
std::vector<int> v[100002],type[102],node[100002];
int d[100002][102];
void bfs(int cur)
{
	queue<int>qq;
	for(auto &x:type[cur]){qq.push(x);d[x][cur]=0;}
	while(sz(qq))
	{
		int temp=qq.front();
		qq.pop();
		for(auto &x:v[temp])
		{
			if(d[x][cur]==-1)
			{
				d[x][cur]=d[temp][cur]+1;
				qq.push(x);
			}
		}
	}
	return;

}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll t,n,m,k,s,a,b;
	 	cin>>n>>m>>k>>s;
	 	FOR(i,1,n+1){cin>>t;type[t].pb(i);}
	 	FOR(i,0,100001)FOR(j,0,101)d[i][j]=-1;
	 	FOR(i,0,m)
	 	{
	 		cin>>a>>b;
			v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	FOR(i,1,k+1)bfs(i);
		FOR(i,1,n+1)
		{
			sort(d[i],d[i]+k+1);
			int ans=0;
			FOR(j,1,s+1)
				ans+=d[i][j];
			cout<<ans<<" ";	
		}
		return 0;
}