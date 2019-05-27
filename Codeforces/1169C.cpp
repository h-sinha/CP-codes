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
typedef long double ld;
typedef long long ll;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=3e5+7;
map<ll,ll> counter;
ll n,m;
ll a[L];
bool check(ll val)
{
	ll tmp,cur = 0;
	FOR(i,0,n)
	{
		if(a[i]>cur)
		{
			tmp = m-a[i]+cur;
		}
		else
		{
			tmp = cur - a[i];
		}
		if(tmp<=val)continue;
		if(a[i]>=cur)cur = a[i];
		else return 0;
	}
	return 1;
}
void ser()
{
	cin >> n >> m;
	FOR(i,0,n)cin >> a[i];
	ll l=0,r=m,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else l=mid;
	}
	while(r>=0&&check(r))r--;
	cout<<r+1;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ser();
		return 0;
}