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
std::map<string, int > val;
string t[L];
int dp[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, len;
	string s, u;
	cin >> n;
	cin >> s;
	reverse(all(s));
	cin >> m;
	set<string>SET;
	FOR(i,0,m)
	{
		cin >> t[i];
		u = t[i];
		len = t[i].length();
		FOR(j,0,len)u[j] = tolower(u[j]);
		val[u] = i;
		SET.insert(u);
	}
	FOR(i,0,n)dp[i] = -1;
	string cur;
	RFOR(i,n-1,0)
	{
		cur = "";
		FOR(j,0,min(1001,n-i))
		{
			cur += s[i+j];
			if((i+j+1==n || dp[i+j+1]!=INT_MAX) && SET.find(cur)!=SET.end())
			{
				dp[i] = i+j+1;
				break;
			}
		}
		if(dp[i] == -1)dp[i] = INT_MAX;
	}
	int idx = 0;
	std::vector<int> ans;
	while(idx < n)
	{
		cur = "";
		FOR(i,idx,dp[idx])cur += s[i];
		ans.pb(val[cur]);
		idx = dp[idx];
	}
	RFOR(i,sz(ans)-1,0)cout<<t[ans[i]]<<" ";
	return 0;
}