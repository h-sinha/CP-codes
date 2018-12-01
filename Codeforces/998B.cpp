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
int n,b;
ll a[102],dp[102][102][102],cal[102];
ll solve(int idx,int cost,int cuts)
{
	if(dp[idx][cost][cuts]!=-1)return dp[idx][cost][cuts];
	// cout<<idx<<" "<<eve<<" "<<odd<<" "<<" "<<cost<<ln;
	if(cost>b)return INT_MIN;
	// debug2(idx,cost);
	// debug2(idx,cuts);
	// cout<<idx<<" "<<cost<<" "<<eve<<" "<<cuts<<endl;
	// if(idx>=n && odd!=eve)dp[idx][cost][cuts] INT_MAX;
	if(idx>=n-1 && cost<=b )
	{
		// if(a[idx]&1)eve--;
		// else eve++;
		if(cal[idx]==0)return cuts;
	}
		// dp[idx][cost][cuts] cuts;
	if(idx>=n-1)return INT_MIN;
		if(cal[idx]==0)
		{
			dp[idx][cost][cuts]= max(solve(idx+1,cost+abs(a[idx]-a[idx+1]),cuts+1) , solve(idx+1,cost,cuts));
		}
		else
		{
			dp[idx][cost][cuts] =solve(idx+1,cost,cuts);
		}
	return dp[idx][cost][cuts];
	// debug2(idx,dp[idx][eve][odd][cost]);
	// dp[idx][cost][cuts] dp[idx][eve][cost][cuts];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int ans;
	 	cin>>n>>b;
	 	FOR(i,0,n)cin>>a[i];
	 	if(a[0]%2==0)cal[0]=1;
	 	else cal[0]=-1;
	 	FOR(i,1,n)
	 	{
	 		cal[i]+=cal[i-1];
	 		if(a[i]&1)cal[i]--;
	 		else cal[i]++;
	 	}
	 	// FOR(i,0,n)cout<<i<<" "<<cal[i]<<ln;
	 	FOR(i,0,101)FOR(j,0,101)FOR(k,0,101)dp[i][j][k]=-1;
	 	ans=solve(0,0,0);
	 	cout<<ans;
		return 0;
}