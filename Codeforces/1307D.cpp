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
#define pii pair<int,int>
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
int n, m, k, sp[L], s[L], d[L], mx[L];	
std::vector<int> v[L];
void ffs()
{
	int tmp,a,b;
	cin >> n >> m >> k;
	FOR(i,0,k)
	{
		cin >> a;
		sp[a] = 1;
	}
	FOR(i,0,m)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	queue<int>q;
	q.push(1);
	init(d, 1e6);
	init(s, 1e6);
	s[1] = 0, d[n] = 0;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		trace(v[tmp], x)
		{
			if(s[tmp] + 1 < s[x])
			{
				s[x] = s[tmp] + 1;
				q.push(x);
			}
		}
	}
	int ans = d[n];
	q.push(n);
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		trace(v[tmp], x)
		{
			if(d[tmp] + 1 < d[x])
			{
				d[x] = d[tmp] + 1;
				q.push(x);
			}
		}
	}
	std::vector<pii> v1, v2;
	FOR(i,1,n+1)
	{
		if(sp[i])
		{
			v1.pb({d[i], i});
			v2.pb({s[i], i});
		}
	}
	sort(all(v1));
	sort(all(v2));
	RFOR(i,sz(v1)-1,0)
		mx[i] = max(mx[i+1], s[v1[i].S]);
	FOR(i,0,sz(v1)-1)
		ans = max(ans, v1[i].F + mx[i+1]);
	cout<<min(ans+1,s[n])<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	ffs();
	return 0;
}