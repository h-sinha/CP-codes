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
map<ll,ll> counter;
int a[L][3];
string s[L];
void fff()
{
	int n, m;
	cin >> n >> m;
	FOR(i,0,n)cin >> s[i];	
	if(min(n,m)>=4)
	{
		cout << -1 << ln;
		return;
	}
	int f = 0;
	if(n<m)
	{
		swap(n,m);
		f = 1;
	}
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(f)a[i][j] = (s[j][i] - '0');
			else a[i][j] = (s[i][j] - '0');
		}
	}
	int ans = INT_MAX, cur;
	if(m == 1)
	{
		cout << 0 << ln;
		return;
	}
	if(m == 2)
	{
		for(auto d:{0,1})
		{
			cur = 0;
			FOR(i,0,n)
			{
				cur += (a[i][0] ^ a[i][1] ^ d);
				d ^= 1; 
			}
			ans = min(ans, cur);
		}
		cout << ans << ln;
		return;
	}
	std::vector<pii> v{{0,0}, {0,1}, {1,1}, {1,0}};
	for(auto [x, y]:v)
	{
		cur = 0;
		FOR(i,0,n)
		{
			cur += ((a[i][0]^a[i][1]^x) || (a[i][1] ^ a[i][2] ^ y));
			x ^= 1;
			y ^= 1;
		}
		ans = min(ans, cur);
	}
	cout << ans << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}