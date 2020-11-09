#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define eb emplace_back
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
typedef	priority_queue<pii, std::vector<pii>, greater<pii> > revpr;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L = 1e6 + 7;
int a[L];
void fff()
{
	char type;
	int n;
	cin >> n;
	stack<int>st;
	FOR(i, 0, 2 * n)
	{
		cin >> type;
		if (type == '-')
		{
			cin >> a[i];
			if (st.empty())
			{
				cout << "NO\n";
				return;
			}
			a[st.top()] = -a[i];
			st.pop();
		}
		else st.push(i);
	}
	set<int>SET;
	FOR(i, 0, 2 * n)
	{
		if (a[i] < 0)SET.insert(-a[i]);
		else
		{
			debug(i,a[i],*SET.begin());
			if (SET.empty() || *SET.begin() > a[i])
			{
				cout << "NO\n";
				return;
			}
			SET.erase(SET.begin());
		}
	}
	cout << "YES\n";
	FOR(i, 0, 2 * n)if (a[i] < 0)cout << -a[i] <<" ";
}
int main()
{
#ifdef LOCAL_EXEC
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#endif
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}