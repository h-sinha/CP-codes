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
#define F first
#define S second
typedef long long ll;
typedef long double ld;
ll n,counter[100002],arr[100002],point[100002],dp[100002][2];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin>>n;
		FOR(i,0,n)
		{
			cin>>arr[i];
			counter[arr[i]]++;
		}
		ll ans=0;
		FOR(i,0,100001)point[i]=i*counter[i];
		FOR(i,1,100001)
		{
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
			dp[i][1]=point[i]+dp[i-1][0];
		}
		// FOR(i,1,11)debug3(i,dp[i][0],dp[i][1]);
		cout<<max(dp[100000][0],dp[100000][1]);
	return 0;
}