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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

const int L=2e5+7;
map<ll,ll> counter;
ll n, tot;
set<int>ans[L], s[L];
void solve() 
{
	if (n == 2) 
	{
		trace(s[0], x)
		{
			if(!sz(ans[0]))ans[0].insert(x);
			else ans[1].insert(x);
		}
		return;
	}
	ll x = *s[0].begin();
	tot = (n*(n-1))/2;
	std::vector<int> check;
	FOR(i,0,tot)
	{
		if(s[i].find(x) != s[i].end())check.pb(i);
	}
	int f = 1;
	trace(s[0], x)
	{
		f = 1;
		trace(check, y)
		{
			if(s[y].find(x) == s[y].end())
			{
				f = 0;
				break;
			}
		}
		if(f)ans[0].insert(x);
	}
	FOR(i,0,sz(check))
	{
		trace(s[check[i]], y)
		{
			if(ans[0].find(y) == ans[0].end())
			{
				ans[i+1].insert(y);
			}
		}
	}
}

void fff()
{
	ll x, y, k;
	cin >> n;
	tot = (n*(n-1))/2;
	FOR(i,0,tot)
	{
		cin >> k;
		while(k--)
		{
			cin >> y;
			s[i].insert(y);
		}
	}
	solve();
	set<int>aux;
	FOR(i,0,201)
	{
		if(sz(ans[i]))
		{
			cout << sz(ans[i])<<" ";
			trace(ans[i], x)cout << x <<" ",aux.insert(x);
			cout << ln;
		}
	}	 
	set<int>aa;
	FOR(i,0,tot)
	{
		trace(s[i], y)
		{
			if(aux.find(y) == aux.end())
			{
				aa.insert(y);
			}
		}
	}
	if(sz(aa))
	{
		cout << sz(aa)<<" ";
		trace(aa,x)cout << x <<" ";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}