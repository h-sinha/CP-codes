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
const int L=1e6+7;
map<ll,ll> counter;
ll power[L], sumis[L], m=1e9+7, one[L], zero[L];
void pre()
{
	power[0] = sumis[0] = 1;
	FOR(i,1,100001)power[i] = (power[i-1]*2)%m;
	FOR(i,1,100001)sumis[i] = (sumis[i-1] + power[i])%m;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll n, q, l, r;
		string s;
		cin >> n >> q;
		cin >> s;
		pre();
		FOR(i,0,n)
		{
			if(s[i] == '1')one[i+1]++;
			else zero[i+1]++;
		}
		FOR(i,1,n+1)one[i] += one[i-1], zero[i] += zero[i-1];
		ll zz,oo;
		ll a1, a2;
		while(q--)
		{
			cin >> l >> r;
			zz = zero[r] - zero[l-1];
			oo = one[r] - one[l-1];
			if(oo)a1 = sumis[oo-1];
			else a1 = 0;
			a2 =( (power[oo]-1) *sumis[zz-1])%m;
			// debug(oo,zz, a1, a2, sumis[oo-1]);

			cout<<(a1+a2)%m<<ln;
		}
		return 0;
}