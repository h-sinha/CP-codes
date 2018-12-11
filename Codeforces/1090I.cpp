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
typedef long long int ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
map<ll,ll> counter;
ll b[L], a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	ll ans =INT_MAX,n,l,r,x,y,z,cur;
	 	cin >> t;
	 	multiset<ll>SET;
	 	multiset<ll>::iterator tmp;
	 	while(t--)
	 	{
	 		ans = INT_MAX;
	 		cin >> n >> l >> r >> x >> y >> z >> b[0] >> b[1];
	 		a[0] = l + (b[0]%(r-l+1));
	 		a[1] = l + (b[1]%(r-l+1));
	 		FOR(i,2,n)
	 		{
	 			b[i] = ((b[i-2]*x) + (b[i-1]*y)  + z ) ;
	 			a[i] = (b[i]%(r-l+1)) + l;
	 		}
	 		// FOR(i,0,n)debug(i,a[i],b[i]);
	 		FOR(i,0,n)SET.insert(a[i]);
	 		FOR(i,0,n-1)
	 		{
	 			cur = *SET.begin();
	 			SET.erase(SET.find(cur));
	 			tmp = SET.upper_bound(cur);
	 			if(tmp == SET.end())continue;
	 			debug(cur, *tmp);
	 			ans =min(ans, cur * (*tmp));
	 		}
	 		if(ans == INT_MAX)cout<<"IMPOSSIBLE\n";
	 		else cout<<ans<<ln;
	 	}
		return 0;
}