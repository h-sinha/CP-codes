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
void fff()
{
	ll n, l, r;
	cin >> n >> l >> r;
	ll cur = 1, idx = 0;
	while(idx < l)
	{
		idx += 2*(n-cur);
		cur++;
		if(cur == n)break;
	}	
	int f1 = 0;
	ll lim = n*(n-1)+1;
	if(lim == r)r--, f1 = 1;
	if(idx < l)
	{
		cout<<1<<ln;
		return;
	}
	if(idx != l-1)
		cur--;

	ll lft = 2LL*(cur-1)*n;
	lft -= (cur-1)*cur;
	lft += 1;
	int f = 0;
	ll nxt = (l-lft+2)/2  + cur;
	if(l%2)f = 1;
	while(l<=r)
	{
		if(f)
		{
			cout<<cur<<" ";
			if(r-l>0)cout<<nxt<<" ";
			nxt++;
			l += 2;
		}
		else
		{
			cout<<nxt<<" ";
			if(r-l>0 && nxt != n)
			{
				cout<<cur<<" ";
				l += 2;
			}
			else l += 1;
			nxt++;
		}
		if(nxt > n)cur++,nxt = cur + 1, f = 1;
	}
	if(f1)cout<<1;
	cout<<ln;
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