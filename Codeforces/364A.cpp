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
const int L=4005;
map<ll,int> counter;
ll sumis[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll a, tmp;
		cin >> a;
		string s;
		cin >> s;
		int n = s.length();
		FOR(i,0,n)
		{
			sumis[i+1] = s[i] - '0';
			sumis[i+1] += sumis[i];
		}
		FOR(i,1,n+1)
			FOR(j,i,n+1)
				counter[sumis[j]-sumis[i-1]]++;
		ll ans = 0;
		FOR(i,1,n+1)
		{
			FOR(j,i,n+1)
			{
				tmp = sumis[j] - sumis[i-1];
				if(tmp == 0)
				{
					if(a == 0)ans += (n*n)/2 + (n+1)/2;
					continue;
				}
				if(a % tmp)continue;
				ans += counter[a/tmp];
			}
		}
		cout<<ans;
		return 0;
}