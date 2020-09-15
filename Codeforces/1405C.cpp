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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=1e6+7;
bool check(string s, int k)
{
	int n = s.length();
	int co = 0;
	FOR(i,0,k)
	{
		if(s[i] == '1')co++;
		else co--;
	}
	if(co)return 0;
	FOR(i,k,n)
	{
		if(s[i] != s[i-k])return 0;
	}
	return 1;
}
void fff()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;	
	FOR(i,0,k)
	{
		set<char>SET;
		for (int j = i; j < n; j += k)
		{
			if(s[j] != '?')SET.insert(s[j]);
		}
		if(sz(SET) > 1)
		{
			cout << "NO\n";
			return;
		}
		if(sz(SET) == 1)
		{
			for (int j = i; j < n; j += k)
			{
				s[j] = *SET.begin();
			}
		}
	}
	int co = 0;
	FOR(i,0,k)
	{
		if(s[i] == '1')co++;
		else if(s[i] == '0')co--;
	}
	FOR(i,0,k)
	{
		if(s[i] == '?')
		{
			if(co>0)s[i] = '0', co--;
			else s[i] = '1', co++;
		}
	}
	FOR(i,k,n)
	{
		if(s[i] == '?')
		{
			if(s[i-k] == '1')s[i] = '1';
			else s[i] = '0';
		}
	}
	if(check(s,k))cout <<"YES\n";
	else cout << "NO\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}