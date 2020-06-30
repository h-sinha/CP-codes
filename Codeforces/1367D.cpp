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
int co[30];
void fff()
{
	string s;
	int m, b;
	cin >> s;
	cin >> m;
	set<pii>v;
	FOR(i,0,m){cin >> b;v.insert({b,i});}	
	string t(m, 'A');
	init(co,0);
	trace(s,x)co[x-'a']++;
	int sofar = 0, idx = 0, i = 0, cit = 25;
	while(!v.empty())
	{
		std::vector<int> cur;
		while(!v.empty() && (*v.begin()).F == 0)cur.pb((*v.begin()).S), v.erase(v.begin());
		while(co[cit]<sz(cur))cit--;
		trace(cur,x)t[x] = char(cit+'a'), co[cit]--;
		set<pii>aux;
		cit--;
		trace(v,y)
		{
			int au = y.F;
			trace(cur,x)au -= abs(x-y.S);
			aux.insert({au, y.S});
		}
		v.clear();
		trace(aux,x)v.insert(x);
	}
	cout<<t<<ln;
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