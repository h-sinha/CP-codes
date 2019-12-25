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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
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
ll m = 1e9 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,x;
	cin >> t;
	ll ans = 0;
	while(t--)
	{
		ans = 0;
		cin >> x ;
		string s;
		cin >> s;
		ll ans = s.length();
		FOR(i,1,x+1)
		{
			if(s.length() < x)
			{
				string tmp = s.substr(i);
				if(s[i-1] != '1')s.append(tmp);
				if(s[i-1] == '3')s.append(tmp);
			}
			ans = (ans + (ans - i) * (s[i-1] - '1'))%m;
			if(ans < 0)ans = (ans + m)%m;
		}
		cout<<ans%m<<ln;
	}
	return 0;
}