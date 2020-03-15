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
string s;
int n, done[L];
int prv[L], nxt[L];
std::vector<int> v[30];
bool check(int i)
{
	if(i < 0 || i >= n)return 0;
	if(nxt[i] < n && nxt[i] >= 0)
	{
		if(s[nxt[i]] == s[i] - 1)return 1;
	}
	if(prv[i] < n && prv[i] >= 0)
	{
		if(s[prv[i]] == s[i] - 1)return 1;
	}
	return 0;
}
void update(int i)
{
	if(prv[i] != -1)
	nxt[prv[i]] = nxt[i];
	if(nxt[i] != -1)
	prv[nxt[i]] = prv[i];
}
void ffs()
{
	cin >> n;
	cin >> s;
	FOR(i,0,n)
	{
		v[s[i]-'a'].pb(i);
		prv[i] = i-1;
		nxt[i] = i+1;
	}
	priority_queue<pair<char, int> > q;
	FOR(i,0,n)
		if(check(i))
			q.push({s[i], i});
	pair<char, int> cur;
	while(!q.empty())
	{
		cur = q.top();
		q.pop();
		done[cur.S] = 1;
		update(cur.S);
		if(check(prv[cur.S]))q.push({s[prv[cur.S]], prv[cur.S]});
		if(check(nxt[cur.S]))q.push({s[nxt[cur.S]], nxt[cur.S]});
	}
	int ans = 0;
	FOR(i,0,n)if(done[i])ans++;
	cout<<ans<<ln;
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