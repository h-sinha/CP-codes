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
int m, d, mod = 1e9+7;
string a, b;
int lena, lenb;
int dp[2002][2002][2][2][2];
int solve(int sofar,int i, int gr,int fl, int cur)
{
	int ans = 0;
	if(i > lenb)return 0;
	sofar%=m;
	int tr = gr, tl = fl ;
	if(i == lenb)
	{
		if(sofar == 0 && gr && fl)return 1;
		return 0;
	}
	if(dp[sofar][i][gr][fl][cur] != -1)return dp[sofar][i][gr][fl][cur];
	if(cur&1)
	{
		if(d < b[i] - '0')tl = 1;
		if(!fl && d > b[i] - '0')return 0;
		if(!gr && d < a[i] - '0')return 0;
		if(d > (a[i]-'0'))tr = 1;
		ans = (ans%mod + solve(sofar*10+d, i + 1, tr,tl, 1 - cur)%mod)%mod;
	}
	else
	{
		FOR(j,0,10)
		{
			tl = fl, tr = gr;
			if(!fl && j > b[i]-'0')continue;
			if(!gr && j < a[i]-'0')continue;
			if(j == d)continue;
			if(j>a[i]-'0')tr = 1;
			if(j<b[i] - '0')tl = 1;
			ans = (ans%mod +  solve((sofar*10)+j, i + 1, tr,tl, 1-cur)%mod)%mod;
		}
	}
	return dp[sofar][i][gr][fl][cur] = ans;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string ta = "";
	 	cin >> m >> d;
	 	cin >> ta >> b;
	 	lena = ta.length();
	 	lenb = b.length();
	 	FOR(i,0,2001)FOR(j,0,2001)FOR(k,0,2)FOR(l,0,2)FOR(z,0,2)dp[i][j][k][l][z]=-1;
	 	a = "";
	 	FOR(i,0,lenb-lena)a+="0";
	 	a += ta;
	 	int tmp = solve(0,0,0,0,0);
	 	int f =0, vl = 0;
	 	for (int i = 1; i < lena; i += 2)
	 	{
	 		if(ta[i]-'0' != d)
	 		{
	 			f = 1;
	 			break;
	 		}
	 	}
	 	FOR(i,0,lena)
	 		vl = (vl*10 + (ta[i] - '0'))%m;

	 	for (int i = 0; i < lena; i += 2)
	 	{
	 		if(ta[i]-'0' == d)
	 		{
	 			f = 1;
	 			break;
	 		}
	 	}
	 	if(!f && !vl)tmp++;
	 	vl = 0, f=0;
	 	for (int i = 1; i < lenb; i += 2)
	 	{
	 		if(b[i]-'0' != d)
	 		{
	 			f = 1;
	 			break;
	 		}
	 	}
	 	FOR(i,0,lenb)
	 		vl = (vl*10 + (b[i] - '0'))%m;
	 	for (int i = 0; i < lenb; i += 2)
	 	{
	 		if(b[i]-'0' == d)
	 		{
	 			f = 1;
	 			break;
	 		}
	 	}
	 	if(!f && ta != b && !vl)tmp++;
	 	cout<<tmp%mod;
		return 0;
}