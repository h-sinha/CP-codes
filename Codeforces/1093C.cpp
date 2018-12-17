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
ll b[L], a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,1,n/2 + 1)cin >> b[i];
	 	a[1] = 0;a[n] = b[1];
	 	FOR(i,2,n/2 + 1)
	 	{
	 		if(b[i] <= b[i-1])
	 		{
	 			a[i] = a[i-1];
	 			a[n-i+1] = b[i] - a[i];
	 		}
	 		else 
	 		{
	 			a[n-i+1] = a[n-i+2];
	 			a[i] = b[i] - a[n-i+1];
	 		}
	 	}
	 	FOR(i,1,n+1)cout<<a[i]<<" ";
		return 0;
}