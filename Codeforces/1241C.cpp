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
ll aa[L], x, a, y, b, k, n;
bool check(ll val)
{
	ll af = val/a;
	ll bf = val/b;
	ll bt = (a*b)/__gcd(a,b);
	bt = val/bt;
	// debug(af,bf,val);
	af -= bt;
	bf -= bt;
	int cur = n-1;
	ll tot = 0;
	while(cur>=0 && bt >0)
	{
		tot += (x+y)*(aa[cur]/100);
		if(tot>=k)return 1;
		cur--;
		bt--;
	}
	if(x>y)
	{
		while(cur>=0 && af >0)
		{
			tot += (x)*(aa[cur]/100);
			if(tot>=k)return 1;
			cur--;	
			af--;
		}
		while(cur>=0 && bf >0)
		{
			tot += (y)*(aa[cur]/100);
			if(tot>=k)return 1;
			cur--;	
			bf--;
		}
	}
	else
	{
		while(cur>=0 && bf >0)
		{
			tot += (y)*(aa[cur]/100);
			if(tot>=k)return 1;
			cur--;	
			bf--;
		}
		while(cur>=0 && af >0)
		{
			tot += (x)*(aa[cur]/100);
			if(tot>=k)return 1;
			cur--;	
			af--;
		}
	}
	if(tot<k)return 0;
	return 1;
}
void solve()
{
	cin >> n;
	FOR(i,0,n)cin >> aa[i];
	cin >> x >> a;
	cin >> y >> b;
	// debug(x,a,y,b);
	cin >> k;
	sort(aa, aa+n);
	ll l=1,r=n,mid, ans = -1;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			ans=mid,r=mid;
		else l=mid;
	}
	if(check(r))ans=r;
	if(l<=r && check(l))ans = l;
	// debug(l,r);
	cout<<ans<<ln;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int q;
	 	cin >> q;
	 	while(q--)solve();
		return 0;
}