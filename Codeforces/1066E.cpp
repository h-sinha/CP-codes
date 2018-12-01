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
const int L=5e5+7;
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
int ss[L],ans[L];
ll power[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m;
	 	cin >> n >> m;
	 	string a,b;
	 	cin >> a ;
	 	cin >> b;
	 	reverse(all(a));
	 	reverse(all(b));
	 	// debug(a,b);
	 	FOR(i,0,m)
	 	{
	 		if(b[i]=='1')ss[i]++;
	 	}
	 	RFOR(i,m-2,0)ss[i]+=ss[i+1];
	 	FOR(i,0,n)if(a[i]=='1')ans[i]=ss[i];
	 	FOR(i,0,n)
	 	{
	 		if(ans[i]<=1)continue;
	 		if(ans[i]&1)
	 		{
	 			ans[i+1]+=ans[i]/2;
	 			ans[i]=1;
	 		}
	 		else
	 		{
	 			ans[i+1]+=ans[i]/2;
	 			ans[i]=0;
	 		}
	 	}
	 	int cur = n;
	 	while(1)
	 	{
	 		if(ans[cur]==0)break;
	 		ans[cur+1]+=ans[cur]/2;
	 		if(ans[cur]&1)ans[cur]=1;
	 		else ans[cur]=0;
	 		cur++;
	 	}
	 	ll mod=998244353;
	 	power[0]=1;
	 	ll out=0;
	 	FOR(i,1,cur+2)power[i] = (power[i-1]*2)%mod;
	 	FOR(i,0,cur)out = (out%mod + (power[i]*ans[i])%mod)%mod;
	 	// FOR(i,0,cur)cout<<ans[i]<<ln;
	 	cout<<out;
		return 0;
}