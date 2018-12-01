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
ll dp[100002],ans[100002],m=1e9+7;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int t,k,a,b;
		cin>>t>>k;
		FOR(i,0,k)dp[i]=1;
		dp[k]=2;
		FOR(i,k+1,100001)dp[i]=(dp[i-1]%m+dp[i-k]%m)%m;
		// FOR(i,1,5)cout<<dp[i]<<" ";
		// cout<<ln;
		FOR(i,1,100001)ans[i]=(ans[i-1]%m + dp[i]%m )%m;
		while(t--)
		{
			cin>>a>>b;
			// cout<<ans[b]-ans[a-1]<<ln;
			ll temp=(ans[b]-ans[a-1])%m;
			if(temp<0)temp+=m;
			cout<<temp<<ln;
		}
		return 0;
}