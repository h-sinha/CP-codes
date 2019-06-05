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

const int L=2002;
map<ll,ll> counter;
ld C[L][L];
void pre()
{
	C[0][0] = 1;
	FOR(i,1,2001)C[0][i] = 0;
	FOR(i,1,2001)
	{
		C[i][0] = 1;
		FOR(j,1,i+1)
		{
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	pre();
	 	ld p, ans = 0;
	 	int n, t;
	 	cin >> n >> p >> t;
	 	if(p == 1)
	 	{
	 		cout<<min(n,t);
	 		return 0;
	 	}
	 	if(1-p == 1)
	 	{
	 		cout<<0;
	 		return 0;
	 	}
	 	FOR(i,1,min(t,n))
	 		ans += (ld(i) * C[t][i] * pow(p, i) * pow(1-p, t-i));
	 	if(t>=n)
	 	{
	 		FOR(i,n,t+1)
	 		{
	 			ans += (ld(n) * C[i-1][n-1] * pow(p, n) * pow(1-p, i-n));
	 		}
	 	}
	 	else
	 		ans += (ld(t) * C[t][t] * pow(p, t));
	 	printf("%.10Lf\n",ans);
		return 0;
}