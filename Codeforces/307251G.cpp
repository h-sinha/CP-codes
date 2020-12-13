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
std::vector<int> v[L];
ll deg[L], dur[L], tot[L];
void fff()
{
	int n, a, d;
	cin >> n;
	FOR(i,1,n+1)
	{
		cin >> dur[i] >> d;
		FOR(j,0,d)
		{
			cin >> a;
			v[i].pb(a);
			deg[a]++;
		}
	}
	priority_queue<pii, std::vector<pii> , greater<pii> >q;
	FOR(i,1,n+1)
	{
		if(deg[i] == 0)q.push({dur[i],i});
	}
	pii cur;
	ll ans = 0, tot = 1;
	while(!q.empty())
	{
		cur = q.top();
		ans = max(ans, n-tot + cur.F);
		q.pop();
		tot++;
		trace(v[cur.S], x)
		{
			deg[x]--;
			if(deg[x] == 0)
			{
				q.push({dur[x],x});
			}
		}
	}
	cout << ans << ln;
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