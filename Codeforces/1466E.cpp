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
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=1e6+7;
ll a[L], m = 1e9 + 7, n, po[L];
ll co[101];
void fff()
{
	FOR(i,0,61)co[i] = 0;
	cin >> n;
	FOR(i,0,n)
	{
		cin >> a[i];
		FOR(j,0,61)
		{
			if(a[i] & po[j])co[j]++;
		}
	}
	ll sa, so, ans = 0;
	FOR(i,0,n)
	{
		sa = 0, so = 0;
		FOR(j,0,61)
		{
			if(a[i] & po[j])
			{
				sa = (sa + ((po[j]%m) * co[j]) % m)%m;
				so = (so + ((po[j]%m) * n) % m)%m;
			}
			else
			{	
				so = (so + ((po[j]%m) * co[j]) % m)%m;
			}
		}
		ans = (ans + (sa * so)%m)%m;
	}
	cout << ans << ln;
}
int main()
{
	po[0] = 1;
	FOR(i,1,61)po[i] = (po[i-1]*2LL);
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}