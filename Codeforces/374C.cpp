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
int n, m, dp[1002][1002], dx[5] = {1,-1,0,0},dy[5]={0,0,1,-1}, grey[1002][1002];
char ch[1002][1002];
bool visit[1002][1002];
char aux[5] = {'D','I','M','A'};
bool danger(int i, int j)
{
	if(i>=n || j>=m || j<0 || i<0)return 0;
	return 1;
}
int dfs(int i, int j, int cur)
{	
	if(grey[i][j])return INT_MIN;
	if(visit[i][j])return dp[i][j];
	int ans = 0, f=0, auxi, flg=0;
	grey[i][j] = 1;
	visit[i][j] = 1;
	FOR(kk,0,4)
	{
		if(danger(i+dx[kk],j+dy[kk]))
		{
			if(ch[i+dx[kk]][j+dy[kk]] == aux[(cur+1)%4])
			{
				auxi =dfs(i+dx[kk],j+dy[kk],(cur+1)%4);
				flg = 1;
				if(auxi != INT_MIN)f=1;
				ans = max(ans,auxi);
			}
		}
	}
	if(cur == 3)ans++;
	// cout<<f<<" "<<flg<<" ";debug3(i,j,ans);
	grey[i][j] = 0;
	if(f || !flg)return dp[i][j] = ans;
	else return dp[i][j] = INT_MIN;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int auxi, ans = 0, f=0, flg=0;
		cin >> n >> m;
		FOR(i,0,n)FOR(j,0,m)cin >> ch[i][j];
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(ch[i][j] == 'D')
				{
					flg = 1;
					auxi = dfs(i,j,0);
					// cout<<auxi<<ln;
					if(auxi == INT_MIN)f=1;
					ans = max(ans,auxi);
				}
			}
		}
		if(f && flg)cout<<"Poor Inna!";
		else if(!ans)cout<<"Poor Dima!";
		else cout << ans;
		return 0;
}