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
#define first F
#define second S
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
ll n,cost[100002],dp[100002][2];
string s[100002],rev[100002];
ll solve(int idx,int mark)
{
	if(idx>=n-1)return 0;
	if(dp[idx][mark])return dp[idx][mark];
	string temp;
	if(mark)
	{
		if(rev[idx]>s[idx+1])
		{
			if(rev[idx]>rev[idx+1])
				dp[idx][mark]=INT_MAX;
			else
			dp[idx][mark]=cost[idx+1]+solve(idx+1,1);
		}
		else 
			dp[idx][mark]=min(cost[idx+1]+solve(idx+1,1),solve(idx+1,0));
	}
	else
	{
		if(s[idx]>s[idx+1])
		{
			if(rev[idx]>s[idx+1] && s[idx]<=rev[idx+1])
				dp[idx][mark]=cost[idx+1]+solve(idx+1,1);
			else if(rev[idx]<s[idx+1] && s[idx]<rev[idx+1])
				dp[idx][mark]=min(cost[idx]+solve(idx+1,0),cost[idx+1]+solve(idx+1,1));
			else dp[idx][mark]=INT_MAX;
		}
		else 
			dp[idx][mark]=min(cost[idx+1]+solve(idx+1,1),solve(idx+1,0));
	}
	return dp[idx][mark];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	
	 	cin>>n;
	 	FOR(i,0,n)cin>>cost[i];
	 	FOR(i,0,n)cin>>s[i];
	 	FOR(i,0,n)
	 	{
	 		rev[i]=s[i];
	 		reverse(rev[i].begin(), rev[i].end());
	 	}
	 	dp[0][0]=0,dp[0][1]=cost[0];
	 	FOR(i,1,n)
	 	{
	 		if(s[i-1]<=s[i] && rev[i-1]<=s[i])
	 			dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
	 		else if(s[i-1]<=s[i])dp[i][0]=dp[i-1][0];
	 		else if(rev[i-1]<=s[i])dp[i][0]=dp[i-1][1];
	 		else dp[i][0]=1e14+2;

	 		if(s[i-1]<=rev[i] && rev[i-1]<=rev[i])
	 			dp[i][1]=cost[i]+min(dp[i-1][0],dp[i-1][1]);
	 		else if(s[i-1]<=rev[i])dp[i][1]=cost[i]+dp[i-1][0];
	 		else if(rev[i-1]<=rev[i])dp[i][1]=cost[i]+dp[i-1][1];
	 		else dp[i][1]=1e14+2;
	 	}
	 	ll ans=min(dp[n-1][0],dp[n-1][1]);
	 	if(ans>1e14)cout<<"-1";
	 	else cout<<ans;
		return 0;
}