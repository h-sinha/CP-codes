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
int pos[L], a[L];
std::vector<pii> ans;
void cswap(int i, int j)
{
	int tmp1, tmp2;
	ans.pb(mp(i,j));
	tmp1 = a[i];
	tmp2 = a[j];
	a[j] = tmp1;
	a[i] = tmp2;
	pos[tmp1] = j;
	pos[tmp2] = i;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, tmp;
	 	cin >> n;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> a[i];
	 		pos[a[i]] = i;
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(a[i] == i)continue;
	 		if((pos[i] - i)*2 < n)
	 		{
	 			if(i<=n/2 && pos[i] <= n/2)
	 			{
	 				cswap(i,n);
	 				cswap(pos[i],n);
	 				cswap(i,n);
	 			}
	 			else if(i<=n/2 && pos[i]>n/2)
	 			{
	 				tmp = pos[i];
	 				cswap(pos[i],1);
	 				cswap(i,n);
	 				cswap(1,n);
	 				cswap(1,tmp);
	 				cswap(i,n);
	 			}
	 			else if(i>n/2 && pos[i]>n/2)
	 			{
	 				tmp = pos[i];
	 				cswap(1,pos[i]);
	 				cswap(1,i);
	 				cswap(1, tmp);
	 			}
	 		}
	 		else
	 		{
	 			cswap(i, pos[i]);
	 		}
	 	}
	 	

	 	cout<<sz(ans)<<ln;
	 	trace(ans,x)cout<<x.F<<" "<<x.S<<ln;
		return 0;
}