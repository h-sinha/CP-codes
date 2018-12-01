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
ll x[100002],h[100002],n,dp[100002][2];
ll func(int i,int mark)
{
	if(i>=n)return 0;
	if(dp[i][mark])return dp[i][mark];
	if(mark==1)
	{
		if(x[i]-h[i]>x[i-1]+h[i-1])return dp[i][mark]=1+func(i+1,0);
		else if(x[i+1]-x[i]>h[i])
			return dp[i][mark]=max(1+func(i+1,1),func(i+1,0));
		return dp[i][mark]=func(i+1,0);
	}
	else
	{
		if(x[i]-x[i-1]>h[i])return dp[i][mark]=1+func(i+1,0);
		if(x[i+1]-x[i]>h[i])
		return dp[i][mark]=max(1+func(i+1,1),func(i+1,0));
		return dp[i][mark]=func(i+1,0);
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin>>n;
		FOR(i,0,n)cin>>x[i]>>h[i];
		x[n]=INT_MAX;
		cout<<1+func(1,0);
		return 0;
}