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
int a[L], p[L], s[L], mxp[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		FOR(i,0,n)
			cin >> a[i];
		cin >> m;
		FOR(i,0,n+2)mxp[i] = 0;
		FOR(i,0,m)
		{
			cin >> p[i] >> s[i];
			mxp[s[i]] = max(mxp[s[i]], p[i]);
		}
		RFOR(i,n-1,0)
		{
			mxp[i] = max(mxp[i], mxp[i+1]);
		}
		int f = 0, r = 0, ans = 0, co, sofar;
		while(r<n)
		{
			co = 1;
			sofar = 0;
			if(mxp[co] < a[r])
			{
				f = 1;
				break;
			}
			ans++;
			while(r<n && mxp[co] >= a[r] && mxp[co] >= sofar)
			{
				// debug(mxp[co],a[r],co,r);
				sofar = max(sofar, a[r]);
				r++;
				co++;
			}
			// debug(r,co,ans);
		}
		if(f)cout<<"-1\n";
		else cout<<ans<<ln;
	}
	return 0;
}