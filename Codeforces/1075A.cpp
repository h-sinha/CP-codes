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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,s11,s22;
	 	cin >> n;
	 	ll x,y;
	 	cin >> x >> y;
	 	ll s1 = min(x,y) - 1;
	 	ll tmp = min(x,y);
	 	if(tmp == x)s1+=abs(y-tmp);
	 	else s1+=abs(x-tmp);

	 	 s11 = max(x,y) - 1;
	 	 tmp = max(x,y);
	 	if(tmp == x)s11+=abs(y-tmp);
	 	else s11+=abs(x-tmp);
	 	s1=min(s1,s11);
	 	// debug(tmp,y,tmp,x);
	 	ll s2 = abs(min(x,y) - n);
	 	if(tmp == x)s2+=abs(y-tmp);
	 	else s2+=abs(x-tmp);
	 	 s22 = abs(max(x,y) - n);
	 	 tmp = max(x,y);
	 	 // debug(s22);
	 	if(tmp == x)s22+=abs(y-tmp);
	 	else s22+=abs(x-tmp);
	 	s2=min(s2,s22);
	 	// debug(s22,x,y,tmp);
	 	// debug(s1,s2,s22);
	 	if(s1 <= s2)
	 	{
	 		cout<<"White";
	 	}
	 	else cout<<"Black";
		return 0;
}