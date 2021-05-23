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
#define eb emplace_back
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
const int L=67;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
struct node
{
	int x, r, p;
	node()
	{
		x = -1;
		r = -1;
		p = -1;
	}
	node(int _x, int _y, int _z)
	{
		x = _x;
		r = _y;
		p = _z;
	}


};
bool operator==(const node& lhs, const node& rhs)
	{
		return (lhs.x == rhs.x) && (lhs.r == rhs.r) && (lhs.p == rhs.p); 
	}
ld dp[L][L][L], w, e;
node nxt[L][L][L];
int xx;
ld target;
void assign(ld cur, ld &ret, int x, int r, int p, int x1, int r1, int p1)
{
	if(cur > ret)
	{
		ret = cur;
		nxt[x][r][p] = {x1, r1, p1};
	}
}
ld solve(int x, int r, int p)
{
	if(x >= 60)return 0;
	if(dp[x][r][p] != -INT_MAX)return dp[x][r][p];
	ld &ret = dp[x][r][p];
	ret = 0;
	ld pr, ps, pp;
	if(x == 0)pr = ld(1)/ld(3), ps = ld(1)/ld(3), pp = ld(1)/ld(3);
	else
	{
		ps = p/ld(x);
		pp = r/ld(x);
		pr = 1.0-ps-pp;
	}
	ld cur = 0;
	ld rock= solve(x+1, r+1, p);
	ld paper= solve(x+1, r, p+1);
	ld scissor= solve(x+1, r, p);
	// rock
	cur = w*ps +  e*pr + rock;
	assign(cur, ret, x, r, p, x+1, r+1, p);
	assign(cur, ret, x, r, p, x+1, r+1, p);
	// paper
	cur = w*pr + e*pp + paper;
	assign(cur, ret, x, r, p, x+1, r, p+1);
	// scissor
	cur = w*pp + e*ps + scissor;
	assign(cur, ret, x, r, p, x+1, r, p);
	return ret;
}
ld cc = 0;
void fff()
{
	xx++;
	cin >> w >> e;
	FOR(i,0,61)FOR(j,0,61)FOR(k,0,61)dp[i][j][k] = -INT_MAX, nxt[i][j][k] = {-1,-1,-1};
	solve(0,0,0);
	string ans;
	int x = 0, r = 0, p = 0;
	int x1 = 0, r1 = 0, p1 = 0;
	while(x < 60)
	{
		if(nxt[x][r][p] == node(x+1, r+1, p))ans += "R";
		else if(nxt[x][r][p] == node(x+1, r, p+1))ans += "P";
		else ans += "S";
		x1 = x, r1 = r, p1 = p;
		x = nxt[x1][r1][p1].x;
		r = nxt[x1][r1][p1].r;
		p = nxt[x1][r1][p1].p;
		assert(x != -1);
		assert(r != -1);
		assert(p != -1);
	}
	cout << "Case #"<<xx<<": "<<ans<<ln;
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;cin >> target;while(t--)
	fff();
	#endif
	return 0;
}