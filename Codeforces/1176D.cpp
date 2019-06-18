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

const int L=4e6+7;
int n, b[L], isprime[L], mxf[L], idx[L], co[L];
set<int> v[L];
std::vector<int> primearr;
bool ans[L];
void pre()
{
	int cur, tot = 0;
	FOR(i,2,2750132)
	{
		cur = sqrt(i);
		FOR(j,2,cur+1)
		{
			if(i % j == 0)
			{
				mxf[i] = i/j;
				break;
			}
		}
		if(!mxf[i])
		{
			tot++;
			idx[i] = tot ;
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
	 	FOR(i,0,2*n)
	 	{
	 		cin >> b[i];
	 		co[b[i]]++;
	 	}
	 	sort(b, b+2*n);
	 	pre();
	 	RFOR(i,2*n-1,0)
	 	{
	 		if(co[b[i]] == 0)continue;
	 		if(mxf[b[i]] == 0)
	 		{
	 			primearr.pb(b[i]);
	 			v[b[i]].insert(i);
	 			continue;
	 		}
	 		ans[i] = 1;
	 		co[mxf[b[i]]]--;
	 		co[b[i]]--;
	 	}
	 	trace(primearr,x)
	 	{
	 		while(sz(v[x]) > co[x])
	 		{
	 			v[x].erase(v[x].begin());
	 		}
	 	}
	 	int cur;
	 	RFOR(i,2*n-1,0)
	 	{
	 		if(co[b[i]])
	 		{
	 			cur = idx[b[i]];
	 			if(co[cur] == 0)continue;
	 			ans[*v[cur].begin()] = 1;
	 			co[b[i]]--;
	 			co[cur]--;
	 			v[cur].erase(v[cur].begin());
	 			v[b[i]].erase(v[b[i]].begin());
	 		}
	 	}
	 	FOR(i,0,2*n)
	 		if(ans[i])
	 			cout<<b[i]<<" ";
		return 0;
}