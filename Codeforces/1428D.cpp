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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll b[L], a[L], nxt[L],done[L], n;
void fff()
{
	cin >> n;
	int co= 0;
	FOR(i,0,n)
	{
		cin >> a[i];
	}
	std::vector<pii> r1;
	std::vector<int>  r2;
	int prv = n-1;
	std::vector<pii> ans;
	RFOR(i,n-1,0)
	{
		if(a[i] == 0)continue;
		if(a[i] == 1)
		{
			ans.pb({i, prv});
			r1.pb({i,prv});
			r2.pb(i);
			prv--;
		}
		else if(a[i] == 2)
		{
			while(!r1.empty() && done[r1.back().F])r1.pop_back();
			if(r1.empty())
			{
				cout << -1 << ln;
				return;
			}
			done[r1.back().F] = 1;
			ans.pb({i, r1.back().S});
			r1.pop_back();
			r2.pb(i);
		}
		else if(a[i] == 3)
		{
			if(r2.empty())
			{
				cout << -1 << ln;
				return;
			}
			ans.pb({i, prv});
			ans.pb({r2.back(), prv});
			done[r2.back()] = 1;
			r2.pop_back();
			r2.pb(i);
			prv--;
		}
	}
	cout << sz(ans)<<ln;
	trace(ans, x)cout << x.S+1<<" "<<x.F+1<<ln;

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