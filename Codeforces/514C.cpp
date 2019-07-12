#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
ll m = 1e12 + 39, po37[L], po53[L];
set<pii>string_hash[L];
void pre()
{
	po37[0] = po53[0] = 1;
	FOR(i,1,1000001)
	{
		po37[i] = (po37[i-1] * 37LL)%m;
		po53[i] = (po53[i-1] * 53LL)%m;
	}
}
void process(string s)
{
	int n = s.length();
	ll h1 = 0, h2 = 0;
	FOR(i,0,n)
	{
		h1 = (h1 + (po37[i]*ll(s[i]-'a'+1))%m)%m;
		h2 = (h2 + (po53[i]*ll(s[i]-'a'+1))%m)%m;
	}
	string_hash[n].insert({h1,h2});
}
bool check(string s)
{
	int n = s.length();
	if(string_hash[n].empty())return 0;
	ll h1 = 0, h2 = 0, t1, t2;
	FOR(i,0,n)
	{
		h1 = (h1 + (po37[i]*ll(s[i]-'a'+1))%m)%m;
		h2 = (h2 + (po53[i]*ll(s[i]-'a'+1))%m)%m;
	}
	FOR(i,0,n)
	{
		FOR(j,1,4)
		{
			if(j-1 == s[i] - 'a')continue;
			t1 = h1, t2 = h2;
			t1 = (t1 - (po37[i]*(s[i]-'a'+1))%m + m)%m;
			t2 = (t2 - (po53[i]*(s[i]-'a'+1))%m + m)%m;
			t1 = (t1 + (po37[i]*j)%m)%m;
			t2 = (t2 + (po53[i]*j)%m)%m;
			if(string_hash[n].find({t1,t2}) != string_hash[n].end())return 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	string s;
	cin >> n >> m;
	pre();
	while(n--)
	{
		cin >> s;
		process(s);
	}
	while(m--)
	{
		cin >> s;
		if(check(s))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}