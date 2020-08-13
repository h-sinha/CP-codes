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
const int L=1e2+7;
map<ll,ll> counter;
int done[L][L];
void fff()
{
	ll f = 0;
	ll n, m;
	ll x, y;
	cin >> n >> m >> x >> y;
	FOR(i,0,n+1)FOR(j,0,m+1)done[i][j]= 0;
	int cur = y;
	set<int>SET;
	FOR(i,1,m+1)SET.insert(i);
	while(sz(SET))
	{
		cout << x <<" "<< y << ln;
		done[x][y] = 1;
		SET.erase(y);
		if(f)
		{
			FOR(i,1,n+1)
			{
				if(!done[i][y])
				{
					cout << i <<" "<<y<<ln;
					done[i][y] = 1;
					x = i;
				}
			}
		}
		else
		{	
			RFOR(i,n,1)
			{
				if(!done[i][y])
				{
					cout << i <<" "<<y<<ln;
					done[i][y] = 1;
					x = i;
				}
			}
		}
		if(sz(SET))
		{
			y = *SET.begin();
		}
		f = 1-f;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}