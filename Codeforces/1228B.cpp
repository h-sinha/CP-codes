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
ll m = 1e9 + 7;
int r[L], c[L];
ll fastexpo(ll x,ll y)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int a[1003][1003],  b[1003][1003];
void verify(int n, int m)
{
	FOR(i,0,n)
	{
		int co = 0;
		FOR(j,0,m)
		{
			if(a[i][j] == 1 || b[i][j] == 1)co++;
			else break;
		}
		if(co != r[i])
		{
			cout<<"0";
			exit(0);
		}
	}
	FOR(i,0,m)
	{
		int co = 0;
		FOR(j,0,n)
		{
			if(a[j][i] == 1 || b[j][i] == 1)co++;
			else break;
		}
		if(co != c[i])
		{
			cout<<"0";
			exit(0);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	FOR(i,0,n)
	{
		cin >> r[i];
		FOR(j,0,r[i])a[i][j] = 1;
	}
	FOR(i,0,m)
	{
		cin >> c[i];
		FOR(j,0,c[i])
		{
			b[j][i] =1;
		}
	}
	ll co = 0;
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(a[i][j-1] == 0 && b[i-1][j] == 0)
			{
				// a[i][j] = 3;
				co++;
			}
		}
	}
	verify(n, m);
	ll md = 1e9+7;
	cout<<fastexpo(2LL, co);
	return 0;
}