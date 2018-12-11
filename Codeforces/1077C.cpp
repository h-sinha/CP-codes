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
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	ll sumis = 0;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 		sumis += a[i];
	 		counter[a[i]]++;
	 	}
	 	ll tmp;
	 	std::vector<int> ans;
	 	FOR(i,0,n)
	 	{
	 		if((sumis-a[i])&1)continue;
	 		tmp = (sumis-a[i])/2;
	 		counter[a[i]]--;
	 		if(counter.find(tmp)!=counter.end() && counter[tmp]>0)ans.pb(i);
	 		counter[a[i]]++;
	 	}
	 	cout<<sz(ans)<<ln;
	 	trace(ans, x)cout<<x+1<<" ";
	 	cout<<ln;
		return 0;
}