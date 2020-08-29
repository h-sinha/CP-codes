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
ll m = 1e9 + 7;
ll h[L], l[L];
map<ll,ll>hmap;
map<ll,ll>hmap1;
void handle(ll x, ll hei)
{
	ll cur = hmap[x], cur1 = hmap1[x];
	// debug(x,hei,cur,cur1);
	if(cur == 0)
	{
		hmap[x] = hei;
	}
	else if(cur1 == 0)
	{
		if(cur > hei)hmap1[x] =  hei;
		else
		{
			hmap1[x] = cur;
			hmap[x] = hei;
		}
	}
	else
	{
		if(cur <= hei)
		{
			hmap1[x] = cur;
			hmap[x] = hei;
		}
		else if(cur1 <= hei)
		{
			hmap1[x] = hei;
		}
	}
	// debug(x,hei, hmap1[x], hmap[x]);
}
void fff()
{
	xx++;
	hmap.clear();
	hmap1.clear();
	ll n, k, w, al, bl, cl, dl, ah, bh, ch, dh;
	cin >> n >> k >> w;
	FOR(i,0,k)cin >> l[i];
	cin >> al >> bl >> cl >> dl;
	FOR(i,0,k)cin >> h[i];
	cin >> ah >> bh >> ch >> dh;
	FOR(i,k,n)
	{
		l[i] = ((al * l[i-2])%dl + (bl * l[i-1])%dl + cl)%dl + 1;
		h[i] = ((ah * h[i-2])%dh + (bh * h[i-1])%dh + ch)%dh + 1;
	}
	ll ans = 1, cur = 0,cur1 = 0, base = 0, height = 0, lft = 0, rgt = 0;
	FOR(i,0,n)
	{
		if(l[i]>rgt)
		{
			base += (rgt - lft);
			lft = l[i], rgt = l[i] + w;
			base %= m;
		}
		rgt = l[i] + w;
		FOR(j,0,w+1)
		{
			height -= (hmap[l[i] + j] - hmap1[l[i] + j]);
			height = (height + m)%m;
		}
		// debug(height);
		handle(l[i], h[i]);
		handle(l[i]+w, h[i]);
		FOR(j,l[i]+1,l[i]+w)
		{
			if(hmap[j] == 0)
			{
				hmap[j] = hmap1[j] = h[i];
			}
			else 
			{
				if(hmap[j]<h[i])
				{
					hmap1[j] = hmap[j] = h[i];
				}
				else handle(j, h[i]);
			}
		}
		FOR(j,0,w+1)
		{
			height += (hmap[l[i] + j] - hmap1[l[i] + j]);
			height %= m;
		}
		cur = (2LL * base)%m;
		cur = (cur + (2LL * (rgt - lft))%m)%m;
		cur = (cur + height)%m;
		ans = (ans * cur) % m;
	}
	cout << "Case #"<<xx<<": "<<ans<<ln;
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