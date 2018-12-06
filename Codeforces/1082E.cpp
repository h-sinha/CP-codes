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
std::map<int, int> counter;
int a[L], req[L];
std::vector<int> first(L,-1), last(L);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, c, ans = INT_MIN;
	 	cin >> n >> c;
	 	std::vector<int> v;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 		req[i] = c - a[i];
	 		counter[req[i]]++;
	 		if(first[req[i]] == -1)first[req[i]] = i;
	 		last[req[i]] = i;
	 		ans = max(ans, counter[req[i]]);
	 		if(req[i] == 0)v.pb(i);
	 	}
	 	trace(counter,x)
	 	{
	 		if(x.F == 0)continue;
	 		l = upper_bound(all(v), first[x.F]) - v.begin();
	 		r = upper_bound(all(v), first[x.F]) - v.begin();
	 		ans = max(ans, x.S + )
	 	}
	 	cout<<ans;
		return 0;
}