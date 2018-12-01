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
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
const int L=1e6+7;
ll p[L],xoris[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll ans=0,n,a,div,rem;
	 	cin>>n;
	 	FOR(i,1,1000001)xoris[i]=xoris[i-1]^i;
		FOR(i,1,n+1)
		{
			cin>>a;
			div=i/n;
			rem=i%n;
			if(div==0)ans+=xoris[rem]^a;
			else
			{
				if(div&1)
					ans+=(xoris[rem]^xoris[n])^a;
				else
					ans+=xoris[rem]^a;
			}
		}
		cout<<ans;
		return 0;
}