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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,d;
	 	cin>>n>>d;
	 	FOR(i,0,n)cin>>a[i];
		sort(a,a+n);
		ll ans=2;
		// FOR(i,0,n)cout<<a[i];
		FOR(i,0,n-1)
		{
			ll tmp1=a[i]+d;
			ll tmp2=a[i+1]-d;
			if(tmp1==tmp2)ans++;
			else if(tmp1<tmp2)ans+=2;
			// cout<<a[i]<<" "<<a[i+1]<<ln;
			// cout<<tmp2-tmp1<<ln;
			// cout<<tmp1<<" "<<tmp2<<ln;
			// ans+=max(0LL,tmp2-tmp1+1);
		}	
		cout<<ans;
		return 0;
}