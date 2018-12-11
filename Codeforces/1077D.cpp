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
const int L=2e5+7;
int ans, n,k;
int counter[L], done[L], a[L];
std::vector<pii> v;
bool comp(pii x, pii y)
{
	return x.F<y.F;
}
bool check(ll val)
{
	ll tot =0;
	trace(v,x)
	{
		tot += (x.F/val);
	}
	if(tot>=k)return 1;
	return 0;
}
void ser()
{
	int l=0,r=n,mid;
	FOR(i,0,n)
	{
		cin >> a[i];
		counter[a[i]]++;
	}
	FOR(i,0,n)
	{
		if(!done[a[i]])
		{
			v.pb(mp(counter[a[i]], a[i]));
			 done[a[i]] = 1;
		}
	}
	sort(all(v), comp);
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	int tmp, sofar = 0;
	// debug(r);
	trace(v,x)
	{
		if(sofar==k)break;
		tmp = x.F/r;
		// debug(x.F, x.S, tmp);
		FOR(j,0,tmp)
		{
			cout<<x.S<<" ";
			sofar++;
			if(sofar==k)break;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>k;
	 	ser();
		return 0;
}