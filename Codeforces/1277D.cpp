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
std::vector<int> oo, zz, oz, zo;
map<string,int>counter;
string s[L], ns[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, len;
	cin >> t;
	while(t--)
	{
		cin >> n;
		zo.clear();
		oo.clear();
		oz.clear();
		zz.clear();
		FOR(i,0,n)
		{
			cin >> s[i];
			ns[i] = s[i];
			reverse(all(ns[i]));
			counter[ns[i]]++;
			len = s[i].length();
			if(s[i][0] == '0' && s[i][len-1] == '0')zz.pb(i);
			else if(s[i][0] == '0' && s[i][len-1] == '1')zo.pb(i);
			else if(s[i][0] == '1' && s[i][len-1] == '0')oz.pb(i);
			else if(s[i][0] == '1' && s[i][len-1] == '1')oo.pb(i);
		}
		int co = sz(oz) + sz(zo);
		if(co == 0 && sz(oo) > 0 && sz(zz) > 1)
		{
			cout<<"-1\n";
			continue;
		}
		if(co&1)co++;
		// debug(co);
		std::vector<int> ans;
		int cur = 0, idx = 0; 
		while(idx < sz(zo) && cur < sz(zo) - co/2)
		{
			if(counter.find(s[zo[idx]]) != counter.end())
			{
				idx++;
				continue;
			}
			ans.pb(zo[idx]);
			idx++;
			cur++;
		}
		cur = 0, idx = 0; 
		while(idx < sz(oz) && cur < sz(oz) - co/2)
		{
			if(counter.find(s[oz[idx]]) != counter.end())
			{
				idx++;
				continue;
			}
			ans.pb(oz[idx]);
			idx++;
			cur++;
		}
		cout<<sz(ans)<<ln;
		trace(ans,x)cout<<x+1<<" ";
		cout<<ln;

	}
	return 0;
}