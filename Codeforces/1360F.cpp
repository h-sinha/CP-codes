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
const int L=11;
string s[L], ans;
int n, m;
bool check(int x, int y)
{
	ans = "";
	int c;
	FOR(i,0,m)ans += s[x][i];
	set<char>SET;
	FOR(i,0,n)
	{
		if(x == i)continue;
		c = 0;
		FOR(j,0,m)
		{
			if(s[i][j] == ans[j] || j == y)continue;
			c++;
		}
		if(c>1)return 0;
		if(c == 1)SET.insert(s[i][y]);
	}
	if(sz(SET) > 1)return 0;
	if(sz(SET) == 1)ans[y] = *SET.begin();
	return 1;
}
void fff()
{
	cin >> n >> m;
	FOR(i,0,n)cin >> s[i];
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(check(i,j))
			{
				cout<<ans<<ln;
				return;
			}
		}
	}	
	cout<<"-1\n";
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