#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,char>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
bool dp[102][102][30],done[102][102][30];
std::vector<pii> v[102];
int solve(int i,int j,int cur)
{
	if(done[i][j][cur])return dp[i][j][cur];
	trace(v[i],x)
		if( x.S-'a'>=cur && !solve(j,x.F,x.S-'a') )dp[i][j][cur]=1;
	done[i][j][cur]=1;
	return dp[i][j][cur];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int a,b,n,m;
		char c;
		cin>>n>>m;
		FOR(i,0,m)
		{
			cin>>a>>b>>c;
			v[a].pb(mp(b,c));
		}
		FOR(i,1,n+1)
		{
			FOR(j,1,n+1)
			{
				if(solve(i,j,0))cout<<'A';
				else cout<<'B';
			}
			cout<<ln;
		}
		return 0;
}