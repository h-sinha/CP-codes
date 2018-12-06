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
std::vector< std::vector<int> > dp;
string s1, s2;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	cin >> t;
	 	while(t--)
	 	{
		 	cin >> s1 >> s2;
		 	int len1 = s1.length(), len2 = s2.length();
		 	if(len1 > sz(dp))dp.resize(len1+1);
		 	if(len2 > sz(dp[0]))
		 	{
		 		FOR(i,0,sz(dp))dp[i].resize(len2+1);
		 	}
		 	FOR(i,0,len1+1)dp[i][0] = i;
		 	FOR(j,0,len2+1)dp[0][j] = j;
		 	FOR(i,1,len1+1)
		 	{
		 		FOR(j,1,len2+1)
		 		{
		 			dp[i][j] = min(dp[i][j-1]+1 , min(dp[i-1][j]+1, dp[i-1][j-1] + !(s1[i-1] == s2[j-1])));
		 		}
		 	}
		 	cout<<dp[len1][len2]<<ln;
		}
		return 0;
}