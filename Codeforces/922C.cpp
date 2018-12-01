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
map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,k,tmp;
	 	cin>>n>>k;
	 	for (ll i = 1; i <= 10000000 && i<=k; ++i)
	 	{
	 		tmp=n%i;
	 		tmp=n-tmp;
	 		if(tmp/i<50)
	 		cout<<tmp/i<<ln;
	 		if(tmp/i <=k && tmp/i>=1 &&tmp/i!=i && n%(tmp/i)==n%i)
	 		{
	 			// cout<<i<<" "<<tmp/i<<ln;
	 			cout<<"No\n";
	 			return 0;
	 		}
	 	}
	 	cout<<"Yes\n";
		return 0;
}