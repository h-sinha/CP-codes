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
string s[4][1002];
ll ans[4][2],n;
void solve(int idx)
{
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if( (i+j)%2  && s[idx][i][j] == '0')ans[idx][0]++;
			if( (i+j)%2==0  && s[idx][i][j] == '1')ans[idx][0]++;
		}
	}
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if( (i+j)%2  && s[idx][i][j] == '1')ans[idx][1]++;
			if( (i+j)%2==0  && s[idx][i][j] == '0')ans[idx][1]++;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
	 	FOR(i,0,4)
	 	{
	 		FOR(j,0,n)
	 		cin >> s[i][j];
	 	}
	 	FOR(i,0,4)solve(i);
	 	ll out = ans[0][0] + ans[1][0] + ans[2][1] + ans[3][1];
	 	 out = min(out,ans[0][0] + ans[2][0] + ans[1][1] + ans[3][1]);
	 	 out = min(out,ans[0][0] + ans[3][0] + ans[1][1] + ans[2][1]);
	 	 out = min(out,ans[0][1] + ans[1][0] + ans[2][0] + ans[3][1]);
	 	 out = min(out,ans[0][1] + ans[1][0] + ans[2][1] + ans[3][0]);
	 	 out = min(out,ans[0][1] + ans[1][1] + ans[2][0] + ans[3][0]);
	 	 cout<<out;
		return 0;
}