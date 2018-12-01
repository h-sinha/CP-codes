#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int seg[20005],arr[5001],dp[5001][5001];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int q,n,l,r;
	 	cin>>n;
	 	FOR(i,0,n)cin>>arr[i];
	 	cin>>q;
	 	FOR(i,0,n)dp[0][i]=arr[i];
	 	FOR(i,1,n)FOR(j,0,n-i+1)dp[i][j]=dp[i-1][j]^dp[i-1][j+1];
	 	FOR(i,1,n)FOR(j,0,n-i+1)dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
	 	while(q--)
	 	{
	 		cin>>l>>r;
	 		int len=r-l;
	 		cout<<dp[len][l-1]<<ln;
	 	}
		return 0;
}