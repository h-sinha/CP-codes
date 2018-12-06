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
ld a[L], n, k, sumis;
bool check(ld mid)
{
	ld left = 0;
	int invader = n;
	FOR(i,0,k)
	{
		if(a[i] > mid)invader--;
		else left += a[i];
	}
	if(invader <= 0)return 1;
	left/=invader;
	if(left<mid)return 0;
	return 1;
}
ld ser(ld l, ld r)
{
	ld mid;
	while(l<r-0.0000000001)
	{
		mid=(l+r)/2.0;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	return r;
}
int main()
{
	 	cin>>n>>k;
	 	FOR(i,0,k)cin >> a[i], sumis += a[i];
	 	printf("%.10Lf",ser(0.0, sumis*1.0));
		return 0;
}