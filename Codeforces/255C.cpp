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
std::map<int,int> counter;
int dp[4002][4002],a[4002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,ans=1,cur=0;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		if(counter.find(a[i])==counter.end())counter[a[i]]=cur,a[i]=cur++;
	 		else a[i]=counter[a[i]];
	 	}
	 	// FOR(i,0,n)cout<<a[i]<<" ";
	 	// cout<<ln;
	 	FOR(i,0,n)FOR(j,0,n)dp[i][j]=1;
	 	FOR(i,0,n)
	 	{
	 		RFOR(j,i-1,0)
	 		{
	 			dp[i][a[j]]=max(dp[i][a[j]],1+dp[j][a[i]]);
	 			ans=max(ans,dp[i][a[j]]);
	 			// debug3(i,a[j],dp[i][a[j]]);
	 		}
	 	}
	 	cout<<ans;
		return 0;
}