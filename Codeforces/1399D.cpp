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
map<ll,ll> counter;
int ans[L], nz[L], no[L];
void fff()
{
	int n;
	cin >> n;
	string s;
	cin >> s;	
	no[n] = nz[n] = n;
	set<int>SET[2];
	RFOR(i,n-1,0)
	{
		ans[i] = 0;
		SET[s[i]-'0'].insert(i);
	}
	int idx, cur = 1;
	set<int>::iterator it;
	FOR(i,0,n)
	{
		if(ans[i])continue;
		idx = i;
		while(idx<n)
		{
			// debug(idx,cur);
			ans[idx] = cur;
			if(s[idx] == '1')
			{
				SET[1].erase(idx);
				if(SET[0].empty())break;
				it = SET[0].upper_bound(idx);
				if(it == SET[0].end())break;
				idx = *it;
			}
			else
			{
				SET[0].erase(idx);
				if(SET[1].empty())break;
				it = SET[1].upper_bound(idx);
				if(it == SET[1].end())break;
				idx = *it;
			}
		}
		cur++;
	}
	cout << cur-1<<ln;
	FOR(i,0,n)cout << ans[i]<<" ";
	cout << ln;
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