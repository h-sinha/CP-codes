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
int a[L], pos[L], dp[L], r[L];
void fff()
{
	int n, cur;
	cin >> n;
	set<int>prv, nxt;
	FOR(i,0,n)r[i] = 0;
	FOR(i,0,n)
	{
		r[i+1] = 0;
		cin >> a[i];
		pos[a[i]] = i;
		nxt.insert(a[i]);
	}
	pos[0] = -1;
	FOR(i,1,n+1)
	{
		r[i] = max(r[i-1],  pos[i-1]);
	}
	dp[n] = 0;	
	RFOR(i,n-1,0)dp[i] = max(dp[i+1],a[i]);
	FOR(i,0,n)
	{
		if(sz(prv) && *prv.begin()<a[i])
		{
			prv.insert(a[i]);
		}
		else
		{
			cur = 0;
			if(r[a[i]]>i)
			{
				cur = dp[r[a[i]]+1];
				if(cur < a[i])
				{
					cout << "NO\n";
					return;
				}
			}
			prv.insert(a[i]);
		}
	}
	cout << "YES\n";
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