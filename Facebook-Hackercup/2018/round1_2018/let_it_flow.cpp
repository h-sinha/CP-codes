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
#define debug3(x,y,z) cout<<x<<"--> "<<y<<"--> "<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
ll dp[3][1002][2],m=1e9+7,n;
char ch[3][1002];
ll solve(int i,int j,int prev)
{
	if(j==n && i==2)
		return 1;
	if(i<0 || j<0 || j==n || i>=3 || j>=n)return 0;
	if(ch[i][j]=='#')
		return 0;
	if(dp[i][j][prev]!=-1)
		return dp[i][j][prev]%m;
	ll ans=0;
	if(prev==1)
	{
		ans = solve(i-1,j,0)%m;
		ans = (ans%m +solve(i+1,j,0)%m);
	}
	if(prev==0)
		ans = solve(i,j+1,1)%m;
	return dp[i][j][prev]=ans;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int tc;
	 	char inp;
	 	cin>>tc;
	 	FOR(t,1,tc+1)
	 	{
	 		cin>>n;
	 		FOR(i,0,3)
	 		{
	 			FOR(j,0,n)
	 			{
	 				dp[i][j][0]=-1;
	 				dp[i][j][1]=-1;
	 				cin>>inp;
	 				ch[i][j]=inp;
	 			}
	 		}
	 		cout<<"Case #"<<t<<": "<<solve(0,0,1)<<ln;
	 	}
		return 0;
}