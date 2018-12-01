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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
char a[1002][1002];
bool visit[1002][1002];
int ans[1002][1002],cur=0,dx[5]={1,-1,0,0},dy[5]={0,0,1,-1},n,m,k;
std::vector<pii> done;
int danger(int i,int j)
{
	if(i>=n || j>=m || i<0|| j<0 || visit[i][j])return 0;
	if(a[i][j]=='*')return 1;
	return 2;
}
void dfs(int x,int y)
{
	int tmp;
	visit[x][y]=1;
	FOR(i,0,4)
	{
		tmp = danger(x+dx[i],y+dy[i]);
		if(tmp==1)cur++;
		if(tmp==2)
			dfs(x+dx[i],y+dy[i]);
	}
	done.pb(mp(x,y));
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int x,y;
	 	cin >> n >> m >> k;
	 	FOR(i,0,n)FOR(j,0,m)cin >> a[i][j];
	 	FOR(i,0,k)
	 	{
	 		cin >> x >> y;
	 		--x,--y;
	 		cur=0;
	 		if(!visit[x][y])
	 		{
	 			dfs(x,y);
	 			trace(done,xx)ans[xx.F][xx.S]=cur;
	 			done.clear();
	 		}
	 		cout<<ans[x][y]<<ln;
	 	}
		return 0;
}