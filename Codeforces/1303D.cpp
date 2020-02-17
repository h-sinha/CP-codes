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
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll po[L], a[L];
void pre()
{
	po[0] = 1;
	FOR(i,1,60)po[i] = (po[i-1]*2LL);
}
void ffs()
{
	ll n, m, sumis = 0;
	cin >> n >> m;	
	std::vector<int> co(100);
	FOR(i,0,m)
	{
		cin >> a[i];
		sumis += a[i];
		co[log2(a[i])]++;
	}
	if(sumis < n)
	{
		cout<<"-1\n";
		return;
	}
	int ans = 0;
	FOR(i,0,60)
	{
		if(co[i])
		{
			if(n & po[i])co[i]--;
			co[i+1] += (co[i]/2);
		}
		else
		{
			if(n & po[i])
			{
				int f = 0;
				FOR(j,i+1,60)
				{
					if(co[j])
					{
						f = 1;
						co[j]--;
						RFOR(k,j-1,i)co[k]++, ans++;
					}
					if(f)break;
				}				
				if(!f)
				{
					cout<<"-1\n";
					return;
				}
				co[i]--;
			}
		}
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pre();
	int t;cin >> t;while(t--)
	ffs();
	return 0;
}