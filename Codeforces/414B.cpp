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
int m=1e9+7,n,k,dp[2002][2002];
std::vector<int> v[2002];
int solve(int idx, int len)
{
	if(idx > n)return 0;
	if(len == k-1)
	{
		dp[idx][len] = 1;
		return 1;
	}
	if(dp[idx][len])return dp[idx][len];
	dp[idx][len] = 0;
	// FOR(i,idx,n+1)
	trace(v[idx],i)
	{
		// if(i%idx == 0)
			dp[idx][len] = ( dp[idx][len]%m + solve(i,len+1) %m)%m;
	}
	return dp[idx][len];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> k;
	 	int ans=0;
	 	FOR(i,1,n+1)
	 		FOR(j,i,n+1)
	 			if(j%i == 0)v[j].pb(i);
	 	FOR(i,1,n+1)
	 		ans = (ans%m + solve(i,0)%m)%m;
		cout<<ans;
		return 0;
}