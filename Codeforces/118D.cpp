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
int n1, n2, k1, k2, m=1e8, dp[102][102][12][12], cal[102][102][12][12];
int solve(int one, int two, int soone, int sotwo)
{
	// cout<<one<<" "<<two<<" "<<k1<<" "<<k2<<endl;
	if(one > n1 || two > n2 || soone > k1 || sotwo > k2)return 0;
	if(cal[one][two][soone][sotwo])return dp[one][two][soone][sotwo];
	cal[one][two][soone][sotwo]=1;
	if(one == n1 && two == n2)
	{
		dp[one][two][soone][sotwo]=1;
		return dp[one][two][soone][sotwo];
	}
	dp[one][two][soone][sotwo] = ( solve(one+1,two,soone+1,0)%m + solve(one,two+1,0,sotwo+1)%m)%m;
	return dp[one][two][soone][sotwo];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n1 >> n2 >> k1 >> k2;
		cout<<solve(0,0,0,0);
		return 0;
}