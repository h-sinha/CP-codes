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
const int L=3e5+7;
map<ll,ll> counter;
ll power[L],m =1e9+7;
void pre()
{
	power[0] = 1;
	FOR(i,1,300001)power[i] = (power[i-1]*2)%m;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		pre();
		ll n,x[L],tmp,ans=0;
		cin >> n;
		FOR(i,0,n)cin >> x[i];
		sort(x,x+n);
		FOR(i,0,n)
		{
			ans = (ans % m+ (x[i]*(power[i]-power[n-i-1]+m)%m)%m)%m;
		}
		cout<<ans;
		return 0;
}