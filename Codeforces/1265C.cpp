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
const int L=1e6+7;
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
	int n;
	int a[L];
std::vector<int> v;
int mxidx;
bool check(ll val)
{
	int g = 0, s = 0, b = 0, idx = 0;
	FOR(i,0,val+1)g += v[i];
	FOR(i,val+1,sz(v))
	{
		s += v[i];
		idx = i;
		if(s > g)break;
	}
	FOR(i,idx+1,mxidx)
	{
		b += v[i];
		idx = i;
	}
	if(g >= s || g>=b)return 0;
	if(g+s+b > n/2)return 0;
	return 1;
}
void find(int val)
{
	int g = 0, s = 0, b = 0, idx = 0;
	FOR(i,0,val+1)g += v[i];
	FOR(i,val+1,mxidx)
	{
		s += v[i];
		idx = i;
		if(s > g)break;
	}
	FOR(i,idx+1,mxidx)
	{
		b += v[i];
		idx = i;
	}
	cout<<g<<" "<<s<<" "<<b<<ln;
}
void ser()
{
	cin >> n;
	v.clear();
	FOR(i,0,n)cin >> a[i];
	int sofar = 1, prv = a[0], co = 1, idx, f = 0;
	FOR(i,1,n)
	{
		if(a[i] == prv) sofar++;
		else 
		{
			v.pb(sofar);
			sofar = 1;
			prv = a[i];
		}
		co++;
		if(co > n/2 && !f)
		{
			f = 1;
			idx = sz(v)-1;
		}
	}
	v.pb(sofar);
	ll l=0,r=idx,mid;
	mxidx = r+1;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	if(!check(r))
	{
		cout<<"0 0 0\n";
		return;
	}
	find(r);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	cin >> t;
	 	while(t--)ser();
		return 0;
}