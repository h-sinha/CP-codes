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
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
const ll L=1e6+7;
map<ll,ll> counter;
ll power[L], m=1e9+7;
void pre()
{
	power[0]=1;
	FOR(i,1,100001)power[i] = (power[i-1]*2)%m;
}
ll after[L], cont[L], mark[L], comp[L], aux[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	cin >> s;
	 	std::vector<ll> v;
	 	ll len = s.length();
	 	FOR(i,0,len)
	 	{
	 		if(s[i] == 'a')v.pb(1);
	 		else if(s[i]=='b')v.pb(0);
	 	}
	 	ll ss=sz(v), sofar=0;
	 	std::vector<ll> fin, num;
	 	FOR(i,0,ss)
	 	{
	 		if(!v[i])continue;
	 		sofar=0;
	 		ll idx = -1;
	 		FOR(j,i,ss)
	 		{
	 			if(!v[j])break;
	 			sofar++;
	 			idx = j;
	 		}

	 		i = idx;
	 		fin.pb(sofar);
	 		num.pb(sofar);
	 	}
	 	if(sz(fin)==0)
	 	{
	 		cout<<"0";
	 		return 0;
	 	}
	 	ll ans = 0;
	 	FOR(i,0,sz(fin))
	 	{
	 		fin[i]++;
	 	}
	 	RFOR(i,sz(fin)-2, 0)fin[i] = (fin[i]*fin[i+1])%m;
	 	// trace(fin,x)cout<<x<<" ";
	 	FOR(i,0,sz(fin)-1)
	 	{
	 		ans = (ans%m + (num[i]*fin[i+1])%m)%m;
	 	}
	 		ans = (ans%m + (num[sz(fin)-1])%m)%m;

	 	cout<<ans;
		return 0;
}