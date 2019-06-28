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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L= 515;
int po[L];
std::vector<pii> co[L];
int counter[L];
void pre()
{
	po[0] = 1;
	FOR(i,1,10)po[i] = (po[i-1] * 2);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, cur, f, b, cost;
	 	cin >> n >> m;
	 	pre();
	 	set<int>req;
	 	set<int>av;
	 	FOR(i,0,n)
	 	{
	 		cin >> f;
	 		cur = 0;
	 		FOR(j,0,f)
	 		{
	 			cin >> b;
	 			cur |= po[b-1];
	 		}
	 		req.insert(cur);
	 	}
	 	FOR(i,0,m)
	 	{
	 		cin >> cost;
	 		cin >> f;
	 		cur = 0;
	 		FOR(j,0,f)
	 		{
	 			cin >> b;
	 			cur |= po[b-1];
	 		}
	 		counter[cur]++;
	 		// debug(cur);
	 		av.insert(cur);
	 		co[cur].pb(mp(cost,i));
	 	}
	 	FOR(i,0,513)sort(all(co[i]));
	 	std::vector<int> v;
	 	trace(av,x)v.pb(x);
	 	av.clear();
	 	FOR(i,0,sz(v))
	 	{
	 		if(counter[v[i]]>1)av.insert(v[i]|v[i]);
	 		FOR(j,i+1,sz(v))
	 			av.insert(v[i]|v[j]);
	 	}
	 	int ctr = 0, ans = -1;
	 	set<int>val;
	 	trace(av,x)
	 	{
	 		ctr = 0;
	 		trace(req,y)
	 		{
	 			if((x&y) == y)ctr++;
	 		}
	 		if(ans < ctr)
	 		{
	 			ans = ctr;
	 		}
	 	}
	 	trace(av,x)
	 	{
	 		ctr = 0;
	 		trace(req,y)
	 		{
	 			if((x&y) == y)ctr++;
	 		}
	 		if(ans == ctr)
	 		{
	 			val.insert(x);
	 		}
	 	}
	 	int ans1 = -1, ans2 = -1 , tot = INT_MAX;
	 	trace(val,x)
	 	{
		 	FOR(i,0,sz(v))
		 	{
		 		if(counter[v[i]] > 1)
		 		{
		 			if((v[i]|v[i]) == x)
		 			{
		 				if(co[v[i]][0].F + co[v[i]][1].F < tot)
			 			{
			 				tot = co[v[i]][0].F + co[v[i]][1].F;
			 				ans1 = co[v[i]][0].S + 1;
			 				ans2 = co[v[i]][1].S + 1;
			 			}
		 			}
		 		}
		 		FOR(j,i+1,sz(v))
		 		{
		 			if((v[i]|v[j]) == x)
		 			{
		 				if(v[i] != v[j] && co[v[i]][0].F + co[v[j]][0].F < tot)
		 				{
		 					tot = co[v[i]][0].F + co[v[j]][0].F;
		 					ans1 = co[v[i]][0].S + 1;
		 					ans2 = co[v[j]][0].S + 1;
		 				}
		 				else if(v[i] == v[j] && co[v[i]][0].F + co[v[j]][1].F < tot)
		 				{
		 					tot = co[v[i]][0].F + co[v[j]][1].F;
		 					ans1 = co[v[i]][0].S + 1;
		 					ans2 = co[v[j]][1].S + 1;
		 				}
		 			}
		 		}
		 	}
		 }
	 	cout<<ans1<<" "<<ans2<<ln;
		return 0;
}