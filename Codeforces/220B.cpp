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
struct node
{
	int l, r, q;
};
const int L=1e6+7;
int ans = 0, ss, co[L], counter[L], a[L], out[L];
std::map<int,int> code;
std::vector<node> v;
bool comp(node x, node y)
{
	if(x.l/400 == y.l/400)return x.r < y.r;
	return x.l < y.l;
}
void add(int i)
{
	int tmp;
	counter[co[i]]++;

	tmp = counter[co[i]];
	if(tmp == a[i])ans++;
	else if(tmp-1 == a[i])ans--;
}
void rem(int i)
{
	int tmp;
	counter[co[i]]--;
	tmp = counter[co[i]];
	if(tmp == a[i])ans++;
	else if(tmp+1 == a[i])ans--;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, hs = 0, l, r;
	 	cin >> n >> m;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> a[i];
	 		if(code.find(a[i]) == code.end())
	 		{
	 			code[a[i]] = hs;
	 			co[i] = hs++;
	 		}
	 		else co[i] = code[a[i]];
	 	}
	 	node tmp;
	 	FOR(i,0,m)
	 	{
	 		cin >> l >> r;
	 		tmp.l = l;
	 		tmp.r = r;
	 		tmp.q = i;
	 		v.pb(tmp);
	 	}
	 	sort(all(v), comp);
	 	int curl = 1, curr = 0;
	 	trace(v, x)
	 	{
	 		while(curr<x.r)add(++curr);
	 		while(curr>x.r)rem(curr--);
	 		while(curl<x.l)rem(curl++);
	 		while(curl>x.l)add(--curl);
	 		out[x.q] = ans;
	 	}
	 	FOR(i,0,m)cout<<out[i]<<ln;
		return 0;
}