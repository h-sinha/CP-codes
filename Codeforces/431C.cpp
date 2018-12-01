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
ll m=1e9+7,k,d,dp[100002][2];
ll solve(ll n,int mark)
{
	if(n==0 && mark)return 1;
	if(n<=0)return 0;
	if(n<d && !mark)return 0;
	if(dp[n][mark])return dp[n][mark];
	FOR(i,1,d)
		dp[n][mark]=(dp[n][mark]%m + solve(n-i,mark)%m)%m;
	FOR(i,d,k+1)
		dp[n][mark]=(dp[n][mark]%m + solve(n-i,1)%m)%m;
	return dp[n][mark];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n;
		cin>>n>>k>>d;
		cout<<solve(n,0);
		return 0;
}