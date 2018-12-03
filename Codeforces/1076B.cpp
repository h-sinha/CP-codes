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
const int L=1e7+7;
map<ll,ll> counter;
int lps[L];
void pre()
{
	lps[1] = 1;
	FOR(i,2,10000001)
	{
		if(lps[i])continue;
		for (int j = i; j <= 10000000 ; j+=i)
		{
			lps[j] = i;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, ans=0;
	 	cin >> n;
	 	int tmp = sqrt(n);
	 	if(n%2==0)
	 	{
	 		cout<<n/2;
	 		return 0;
	 	}
	 	for (ll i = 3; i <= tmp+1; i+=2)
	 	{
	 		// debug(i,n);
	 		if(n%i == 0)
	 		{
	 			cout<<(n-i)/2 + 1;
	 			return 0;
	 		}
	 	}
	 	cout<<"1";
		return 0;
}