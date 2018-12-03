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
#define sz(a)	ll(a.size())
#define F first
#define S second
#define pb push_back
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
map<ll,ll> counter;
int a[L];
vector<int> v[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, g;
	 	cin >> n;
	 	FOR(i,1,n+1)cin >> a[i];
	 	FOR(i,1,n+1)
	 	{
	 		int l=i, r=i;
	 		FOR(j,i+1,n+1)
	 		{
	 			if(a[j]%a[i])break;
	 			r=j;
	 		}
	 		RFOR(j,i-1,1)
	 		{
	 			if(a[j]%a[i])break;
	 			l=j;
	 		}
	 		i = r+1;
	 		// debug(l,r);
	 		if(r>=l)
	 		v[r-l].pb(l);
	 	}
	 	RFOR(i,n,0)
	 	{
	 		debug(i,sz(v[i]));
	 		if(sz(v[i]))
	 		{
	 			cout<<sz(v[i])<<" "<<i<<ln;
	 			trace(v[i],x)cout<<x<<" ";
	 			break;
	 		}
	 	}
		return 0;
}