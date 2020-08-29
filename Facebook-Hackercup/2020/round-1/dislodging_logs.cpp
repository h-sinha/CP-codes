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
int xx;
ll n, m, k, s, p[L], q[L];
bool check(ll val)
{
	ll prv = 0, l = 0, tmp;
	ll cur;
	set<int>SET, SET1;
	FOR(i,0,m)
	{
		SET1.insert(q[i]);
	}
	while(l<n)
	{
		while(sz(SET1) && *SET1.begin() < p[l])
		{
			SET.insert(*SET1.begin());
			SET1.erase(SET1.begin());
		}
		tmp = val;
		if(!SET.empty())
		{
			cur = *SET.begin();
			if(p[l] - cur > val)
			{
				break;
			}
			SET.clear();
			tmp = val - 2*(p[l]-cur);
		}
		while(!SET1.empty() && *SET1.begin() - p[l]<= tmp)
		{
			SET1.erase(SET1.begin());
		}
		l++;
	}
	if(sz(SET) == 0 &&  sz(SET1) == 0)return 1;
	SET.clear();
	SET1.clear();
	l = n-1;
	FOR(i,0,m)
	{
		SET1.insert(q[i]);
	}
	while(l>= 0)
	{
		while(sz(SET1) && *SET1.rbegin() > p[l])
		{
			SET.insert(*SET1.rbegin());
			SET1.erase(*SET1.rbegin());
		}
		tmp = val;
		if(!SET.empty())
		{
			cur = *SET.rbegin();
			if(cur-p[l] > val)
			{
				break;
			}
			SET.clear();
			tmp = val - 2*(cur-p[l]);
		}
		while(!SET1.empty() && p[l] - *SET1.rbegin()<= tmp)
		{
			SET1.erase(*SET1.rbegin());
		}
		l--;
	}
	debug(val, sz(SET), sz(SET1));
	if(sz(SET) == 0 &&  sz(SET1) == 0)return 1;
	return 0;
}
void fff()
{
	xx++;
	ll ap, bp, cp, dp;
	ll aq, bq, cq, dq;
	cin >> n >> m >> k >> s;
	FOR(i,0,k)cin >> p[i];
	cin >> ap >> bp >> cp >> dp;
	FOR(i,0,k)cin >> q[i];
	cin >> aq >> bq >> cq >> dq;
	FOR(i,k,n)p[i] = ((ap * p[i-2])%dp + (bp * p[i-1])%dp + cp)%dp + 1;
	FOR(i,k,m)q[i] = ((aq * q[i-2])%dq + (bq * q[i-1])%dq + cq)%dq + 1;
	sort(p,p+n);
	sort(q,q+m);
	// FOR(i,0,n)debug(i,p[i]);
	// FOR(i,0,m)debug(i,q[i]);
	ll l = 0, r = 1e18;
	ll mid;
	while(l<r-1)
	{
		mid = (l+r)/2;
		if(check(mid))r = mid;
		else l = mid;
		// debug(n,m,l,r,mid);
	}
	if(!check(r))r= l;
	cout << "Case #"<<xx<<": "<<r<<ln;
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