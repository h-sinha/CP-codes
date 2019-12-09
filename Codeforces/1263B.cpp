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
multiset<string>SET;
string s[11], t[11];
void change(int x, int y)
{
	string tmp;
	FOR(i,0,4)
	{
		FOR(j,0,10)
		{
			tmp = t[y];
			tmp[i] = char(j + '0');
			if(SET.find(tmp) == SET.end())
			{
				SET.erase(SET.find(t[y]));
				t[y] = tmp;
				SET.insert(t[y]);
				return; 
			}
		}
	}
}
void solve()
{
	int n;
	cin >> n;
	SET.clear();
	FOR(i,0,n)
	{
		cin >> s[i];
		SET.insert(s[i]);
		t[i] = s[i];
	}
	FOR(i,0,n)
	{
		FOR(j,i+1,n)
		{
			if(t[i] == t[j])
			{
				change(i, j);
			}
		}
	}
	int ans = 0;
	FOR(i,0,n)
	{
		FOR(j,0,4)
		{
			ans += (s[i][j] != t[i][j]);
		}
	}
	cout<<ans<<ln;
	FOR(i,0,n)cout<<t[i]<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}