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
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
set<char>SET[102];
ll k=1e9+7;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,co;
	 	string s;
	 	cin>>n>>m;
	 	FOR(i,0,n)
	 	{
	 		cin>>s;
			FOR(j,0,m)SET[j].insert(s[j]);
		}
		ll ans=1;
		FOR(i,0,m)
			ans =(ans%k * sz(SET[i])%k )%k;
		cout<<ans;
		return 0;
}