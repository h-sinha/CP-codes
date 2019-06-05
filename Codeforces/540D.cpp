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

const int L=102;
ld dp[L][L][L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int rr, ss, pp;
	 	cin >> rr >> ss >> pp;
	 	dp[rr][ss][pp] = 1.0;
	 	// solve(rr, ss, pp);
	 	RFOR(r,rr,0)
	 	{
	 		RFOR(s,ss,0)
	 		{
	 			RFOR(p,pp,0)
	 			{
	 				if(r == 0 && s == 0)continue;
	 				if(r == 0 && p == 0)continue;
	 				if(p == 0 && s == 0)continue;
	 				ld tot = r*p + s*p + r*s;
	 				if(r>0 && p>0)
	 					dp[r-1][s][p] += (dp[r][s][p] * (ld(r*p)/tot));
	 				if(r>0 && s>0)
	 					dp[r][s-1][p] += (dp[r][s][p] * (ld(s*r)/tot));
	 				if(s>0 && p>0)
	 					dp[r][s][p-1] += (dp[r][s][p] * (ld(s*p)/tot));
	 			}
	 		}
	 	}
	 	ld sumis = 0;
	 	FOR(i,1,rr+1)
	 		sumis += dp[i][0][0];
	 	printf("%.10Lf ",sumis);
	 	sumis = 0;
	 	FOR(i,1,ss+1)
	 		sumis += dp[0][i][0];
	 	printf("%.10Lf ",sumis);
	 	sumis = 0;
	 	FOR(i,1,pp+1)
	 		sumis += dp[0][0][i];
	 	printf("%.10Lf ",sumis);
		return 0;
}