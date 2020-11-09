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
std::vector<ld> a(L);
ld lft[L], rgt[L], l, spl[L], spr[L];
ll n;
void fff()
{
	cin >> n >> l;
	ld cur = 1;
	FOR(i,1,n+1)cin >> a[i];
	n+=2;
	a[0] = 0, a[n-1] = l;
	spl[0] = cur;
	lft[0] = 0;
	FOR(i,1,n)
	{
		lft[i] = lft[i-1] + (a[i] - a[i-1])/cur;
		cur++;
		spl[i] = cur;
	}
	rgt[n-1] = 0;
	cur = 1;
	spr[n-1] = cur;
	RFOR(i,n-2,0)
	{
		rgt[i] = rgt[i+1] + (a[i+1]-a[i])/cur;
		cur++;
		spr[i] = cur;
	}
	ld ans = 0, diff,aux;
	FOR(i,0,n)
	{
		if(lft[i] <= rgt[i])continue;
		if(i>0)
		{
			diff = rgt[i] - lft[i-1];
			if(diff > 0)
			{
				aux = (spl[i]-1)*diff;
				ans = lft[i-1] + + diff + (a[i]-a[i-1]-aux)/(spl[i] - 1 + spr[i]);
			}
			else if(diff < 0)
			{
				aux = (spr[i])*diff;
				ans = lft[i-1] + (a[i]-a[i-1]+aux)/(spl[i] - 1 + spr[i]);
			}
			else
			{
				ans = lft[i-1] + (a[i]-a[i-1])/(spl[i] - 1 + spr[i]);
			}
		}
		else if(i == 0)
		{
			ans = 0;
		}
		printf("%.10Lf\n",ans );
		return;
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