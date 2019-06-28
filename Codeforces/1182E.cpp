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

const int L=5;
ll f1, f2, f3, c;
ll mat[L][L], m = 1e9 + 7, temp[L][L], aux[L][L];
ll g0, g1, g2;
ll fastexpo(ll n)
{
	FOR(i,0,2)
		mat[i][i+1] = 1;
	FOR(i,0,3)mat[2][i] = 1;
	FOR(i,0,3)
	{
		FOR(j,0,3)
		{
			if(i == j)temp[i][j] = 1;
			else temp[i][j] = 0;
		}
	}
	while(n > 0)
	{
		if(n&1)
		{
			FOR(i,0,3)
			{
				FOR(j,0,3)
				{
					FOR(l,0,3)
					{
						aux[i][j] += (mat[i][l] * temp[l][j]);
						aux[i][j] %= m;
					}
				}
			}
			FOR(i,0,3)
			{
				FOR(j,0,3)
				{
					temp[i][j] = aux[i][j];
					aux[i][j] = 0;
				}
			}
		}
		FOR(i,0,3)
		{
			FOR(j,0,3)
			{
				FOR(l,0,3)
				{
					aux[i][j] += (mat[i][l] * mat[l][j])%m;
					aux[i][j] %= m;
				}
			}
		}
		FOR(i,0,3)
		{
			FOR(j,0,3)
			{
				mat[i][j] = aux[i][j];
				aux[i][j] = 0;
			}
		}
		n >>= 1;
	}
	ll ans = 0;
	ans += (temp[0][0] * g0);
	ans %= m;
	ans += (temp[0][1] * g1);
	ans %= m;
	ans += (temp[0][2] * g2);
	ans %= m;
	return ans%m;
}
ll fastexpoint(ll x,ll y)
{
	ll temp1=1;
	while(y>0)
	{
		if(y&1)temp1 = ((temp1%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp1%m;
}
ll find(ll x)
{
	ll cur = 1, co = 0;
	while(cur != x)
	{
		cur = (cur*5LL)%m;
		debug(x,cur,co);
		co++;
	}
	return co;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll n;
	 	cin >> n >> f1 >> f2 >> f3 >> c;
	 	n = 4;
	 	n--;
	 	g0 = find(f1), g1 = find((c * f2)%m), g2 = find(((c * c)%m * f3)%m);
	 	// debug(g0,g1,g2);
	 	ll ret = fastexpo(n);
	 	debug(ret);
	 	ret = fastexpoint(5, ret)%m;
	 	debug(ret);
	 	// debug(ret,c,n+1, fastexpoint(c, n+1));
	 	cout<<(ret * fastexpoint(fastexpoint(c, n+1)%m, m-2))%m;
		return 0;
}