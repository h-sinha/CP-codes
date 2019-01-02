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
std::vector<ll> ans(182,INT_MAX);
std::vector<bool> done(182);
void pre()
{
	ld fl, ce;
	int aux, tmp;
	FOR(i,1,180)
	{
		fl = floor(360.0/(180.0-i));
		ce = ceil(360.0/(180.0-i));
		if(fl != ce || fl <= 2)continue;
		ans[i] = fl;
	}
	RFOR(i,179,1)
	{
		if(ans[i]-2 <= 0 || done[i])continue;
		tmp = i/(ans[i]-2);
		if((ans[i]-2)*tmp != i)continue;
		aux = i;
		while(aux > 0)
		{
			ans[aux] = min(ans[i], ans[aux]);
			if(ans[aux] == ans[i])done[aux] = 1;
			aux -= tmp;
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	pre();
	 	int n, t;
	 	cin >> t;
	 	while(t--)
	 	{
	 		cin >> n;
	 		if(ans[n] == INT_MAX)cout<<"-1\n";
	 		else cout<<ans[n]<<ln;
	 	}
		return 0;
}