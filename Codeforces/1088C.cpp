#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const ll L=1e6+7;
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
std::vector<pii> ans;
ll a[L], tmp;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n;
	 	cin >> n;
	 	FOR(i,0,n)cin >> a[i];
	 	ll val = n,sofar =0;
	 	RFOR(i,n-1,0)
	 	{
	 		a[i]+=sofar;
	 		tmp = a[i]%val;
	 		if(tmp <= i)ans.pb(mp(i,i-tmp)),sofar+=i-tmp;
	 		else ans.pb(mp(i,n+i-tmp)), sofar += n+i-tmp;
	 	}
	 	cout<<n+1<<ln;
	 	trace(ans,x)
	 	{
	 		cout<<"1 "<<x.F+1<<" "<<x.S<<ln;
	 	}
	 	cout<<"2 "<<n<<" "<<n<<ln;
		return 0;
}