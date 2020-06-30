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
int a[L], ans[L], ans1[L];
int spf[10000002];
void pre()
{
	spf[1] = 1;
	FOR(i,2,10000001)
	{
		if(spf[i])continue;
		for (int j = i; j <= 10000000; j += i)
		{
			if(spf[j] == 0)
			spf[j] = i;
		}
	}
}
void go(int x, int id)
{
	std::vector<int> v;
	int cur;
	int ax = x;
	while(x>1)
	{
		v.pb(spf[x]);
		cur = spf[x];
		while(x%cur == 0)x/=cur;
	}
	sort(all(v));
	if(v[0] == v.back())return;
	int gc = v[0];
	ans[id] = 1;
	ans1[id] = 1;
	trace(v,y)
	{
		if(y == v[0])ans[id] *= y;
		else ans1[id]*= y;
	}
}
void fff()
{
	int n, idx = 0;
	cin >> n;
	init(ans,-1);
	init(ans1,-1);
	FOR(i,0,n)
	{
		cin >> a[i];
		go(a[i], i);
	}	
	FOR(i,0,n)cout<<ans[i]<<" ";
	cout<<ln;
	FOR(i,0,n)cout<<ans1[i]<<" ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}