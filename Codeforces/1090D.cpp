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
set<int>v[L];
int a[L], b[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, x, y;
	 	cin >> n >> m;
	 	FOR(i,0,m)
	 	{
	 		cin >> x >> y;
	 		v[x].insert(y);
	 		v[y].insert(x);
	 	}
	 	if(n==1 || 2*m == n*(n-1))
	 	{
	 		cout<<"NO";
	 		return 0;
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(sz(v[i]) != n-1)
	 		{
	 			FOR(j,1,n+1)
	 			{
	 				if(i==j)continue;
	 				if(v[i].count(j))continue;
	 				a[i] = 1, a[j] = 2;
	 				b[i] = b[j] = 1;
	 				int cur = 3;
	 				FOR(k,1,n+1)
	 				{
	 					if(k ==i || k == j)continue;
	 					a[k] = b[k] = cur++;
	 				}
	 				cout<<"YES\n";
	 				FOR(k,1,n+1)cout<<a[k]<<" ";
	 				cout<<ln;
	 				FOR(k,1,n+1)cout<<b[k]<<" ";
	 				return 0;
	 			}
	 		}
	 	}
	 	return 0;
}