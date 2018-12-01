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
int c[100002],dp[5002][5002],counter[5002],righty[100002],lefty[100002];
int main()
{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n)cin>>c[i];
	 	sort(c,c+n);
	 	int cur=n-1;
	 	RFOR(i,n-1,0)
	 	{
	 		while(c[cur]>2*c[i])cur--;
	 		righty[i]=n-1-cur;
	 	}
	 	cur=0;
	 	int ans=INT_MAX;
	 	FOR(i,0,n)
	 	{
	 		ans=min(ans,righty[i]+i);
	 	}
	 	cout<<ans;
		return 0;
}