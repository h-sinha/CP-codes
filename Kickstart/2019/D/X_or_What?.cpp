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
int a[L], csum[L], co[L];
void pre()
{
	FOR(i,1,1000000)
	{
		co[i] = __builtin_popcount(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, q, p , v, tmp, tt = 1;
	cin >> t;
	pre();
	while(t--)
	{
		cin >> n >> q;
		FOR(i,0,n)cin >> a[i];
		csum[0] = a[0];
		FOR(i,1,n)
		{
			csum[i] = a[i];
			csum[i] ^= csum[i-1];
		}
		cout <<"Case #"<<tt<<": ";
		while(q--)
		{
			cin >> p >> v;
			tmp = a[p];
			a[p] = v;
			FOR(i,p,n)
			{
				csum[i]^=tmp;
				csum[i]^=v;
			}
			int cur = 0, f = 0;
			RFOR(i,n,1)
			{
				FOR(j,0,n)
				{
					if(j+i-1 >= n)break;
					cur = csum[j+i-1];
					if(j!=0)cur ^= csum[j-1];
					if(co[cur]%2==0)
					{
						f= 1;
						cout << i<<" ";
						break;
					}
				}
				if(f)break;
			}
			if(!f)cout << 0<<" ";

		}
		cout<<ln;
		tt++;
	}
	return 0;
}