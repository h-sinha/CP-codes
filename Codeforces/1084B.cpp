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
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
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
const int L=1e5+7;
map<ll,ll> counter;
ll ans=0;
ll a[L];
ll co,temp,cur,n,s;
bool check(ll val)
{
	ll sumis = 0;
	FOR(i,0,n)sumis += max(a[i]-val, 0LL);
	if(sumis>=s)return 1;
	return 0;
}
void ser()
{
	ll l = 0,r =INT_MIN, tot=0;
	FOR(i,0,n)
	{
		cin >> a[i];
		tot+=a[i];
		r = max(r,a[i]);
	}
	ll mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	if(r == 0 && tot!=s)
	{
		cout<<"-1";
		return;
	}
	cout<<r;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>s;
	 	ser();
		return 0;
}