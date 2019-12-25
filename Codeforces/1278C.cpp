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
int a[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int tot = 0;
		FOR(i,1,2*n+1)
		{
			cin >> a[i];
			if(a[i] == 2)a[i] = -1;
		}
		std::map<int, int> pos;
		int cur = 0, ans = 2*n;
		pos[0] = 0;
		FOR(i,1,n+1)
		{
			cur += a[i];
			pos[cur] = i;
			if(cur == 0)ans = min(ans, 2*n - i);
		}
		cur = 0;
		RFOR(i,2*n,n+1)
		{
			cur += a[i];
			if(cur == 0)ans = min(ans, i - 1);
			if(pos.find(-cur) != pos.end())ans = min(ans, i - pos[-cur] - 1);
		}
		cout<<ans<<ln;
	}
	return 0;
}