#include<bits/stdc++.h>
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
const int L=1e6+7;
struct node
{
	int l, r, d;
};
int n, m, k, t;
std::vector<int> a;
node w[L];
bool check(int val)
{
	std::vector<pii> v;
	int mx = a[val];
	FOR(i,0,k)
		if(w[i].d > mx)
			v.pb({w[i].l, w[i].r});
	sort(all(v));
	int moves = n + 1;
	int idx, r;
	FOR(i,0,sz(v))
	{
		idx = i;
		r = v[i].S;
		while(idx+1 < sz(v) && v[idx+1].F <= r)
		{
			idx++;
			r = max(r, v[idx].S);
		}
		moves += (r - v[i].F + 1)*2;
		i = idx;
	}
	return moves <= t;
}
void ser()
{
	int l=0,r=m-1,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	if(!check(r))r = -1;
	cout<<r+1;	
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> m >> n >> k >> t;
	 	a.resize(m);
	 	FOR(i,0,m)cin >> a[i];
	 	sort(all(a));
	 	reverse(all(a));
	 	FOR(i,0,k)cin >> w[i].l >> w[i].r >> w[i].d;
	 	ser();
		return 0;
}