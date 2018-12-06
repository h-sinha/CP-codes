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
ll dp[100002];
std::vector<bool> visit(100002);
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
ll func(string s)
{
	int len = s.length();
	dp[0]=dp[1]=1;
	FOR(i,2,len+1)
	{
		dp[i]=0;
		int c1 = s[i-2]-'0', c2 = s[i-1]-'0';
		if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2];
		if(c2!=0) dp[i] += dp[i-1];
	}
	return dp[len];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string num;
	 	while(1)
	 	{
	 		cin>>num;
	 		if(num=="0")return 0;
	 		cout<<func(num)<<ln;
	 	}
		return 0;
} 