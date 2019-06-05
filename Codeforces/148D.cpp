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
ld dp[L][L][2];
ld solve(int w, int b, int flg)
{
	if(w <= 0 && b <= 0)return 0; 
	else if(w <= 0)return 0;
	else if(b <= 0)
	{
		if(flg)return 1.0;
		else return 0;		
	}
	else if(dp[w][b][flg] != -1)return dp[w][b][flg];
	if(flg == 1)	
		dp[w][b][flg] = ld(w)/ld((w+b)) + (ld(b)/ld(w+b)) * solve(w,b-1,1-flg);
	else
	{
		ld ret = 0;
		if(b > 1)
		ret = (ld(b)/ld(b+w)) * (ld(b-1)/ld(b+w-1)) * solve(w, b-2, 1-flg);
		ret += (ld(b)/ld(b+w)) * (ld(w)/ld(b+w-1)) * solve(w-1, b-1, 1-flg);
		dp[w][b][flg] = ret;
	}
	return dp[w][b][flg];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int w, b;
	 	cin >> w >> b;
	 	FOR(i,0,w+1)FOR(j,0,b+1)FOR(k,0,2)dp[i][j][k] = -1;
		printf("%.20Lf\n",solve(w,b,1));
		return 0;
}