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
const int L=2007;
int co[30], visit[L];
int n, k;
bool check(int x)
{
	FOR(i,0,x)visit[i] = 0;
	int c;
	std::vector<int> cc;
	FOR(i,0,x)
	{
		if(visit[i])continue;
		c = 0;
		int cur = i;
		while(!visit[cur])
		{
			c++;
			visit[cur] = 1;
			cur = (cur+k)%x;
		}
		cc.pb(c);
	}	
	sort(rall(cc));
	priority_queue<pii>q;
	FOR(i,0,26)q.push({co[i],i});
	pii cur;
	trace(cc,x)
	{
		cur = q.top();
		q.pop();
		if(cur.F<x)return 0;
		cur.F -= x;
		q.push({cur});
	}
	return 1;
}
void fff()
{
	cin >> n >> k;
	ll l =0, r = n, mid;
	string s;
	cin >> s;
	FOR(i,0,26)co[i] = 0;
	int f = 0;
	FOR(i,0,n)
	{
		co[s[i]-'a']++;
		if(co[s[i]-'a'] == n)f = 1;
	}
	RFOR(i,n,0)
	{
		if(check(i))
		{
			cout<<i<<ln;
			return;
		}
	}
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