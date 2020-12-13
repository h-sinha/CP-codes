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
#define eb emplace_back
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
const int L=2e3+7;
string s[L];
int mxr[12], mnr[12], mxc[12], mnc[12];
int dpr[L][12][2], dpc[L][12][2], ans[12];
void fff()
{
	int n;
	cin >> n;
	FOR(i,0,n)
	{
		cin >> s[i];
		FOR(j,0,10)dpr[i][j][0] = -1, dpr[i][j][1] = 1e6,dpc[i][j][0] = -1, dpc[i][j][1] = 1e6;
	}
	FOR(i,0,10)
	{
		mxr[i] = mxc[i] = -1;
		mnr[i] = mnc[i] = 1e6;
		ans[i] = 0;
	}
	int cur;
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			cur = s[i][j] - '0';
			mxr[cur] = max(mxr[cur], i);
			mnr[cur] = min(mnr[cur], i);
			mxc[cur] = max(mxc[cur], j);
			mnc[cur] = min(mnc[cur], j);
			dpr[i][cur][0] = max(dpr[i][cur][0], j);
			dpr[i][cur][1] = min(dpr[i][cur][1], j);
			dpc[j][cur][0] = max(dpc[j][cur][0], i);
			dpc[j][cur][1] = min(dpc[j][cur][1], i);
		}
	}
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			cur = s[i][j] - '0';
			if(mxr[cur] != -1)
			{
				ans[cur] = max(ans[cur], abs(mxr[cur]-i) * (j));
				ans[cur] = max(ans[cur], abs(mxr[cur]-i) * (n-j-1));
			}
			if(mxc[cur] != -1)
			{
				ans[cur] = max(ans[cur], abs(mxc[cur]-j) * (i));
				ans[cur] = max(ans[cur], abs(mxc[cur]-j) * (n-i-1));
			}
			if(mnr[cur] != 1e6)
			{
				ans[cur] = max(ans[cur], abs(mnr[cur]-i) * (j));
				ans[cur] = max(ans[cur], abs(mnr[cur]-i) * (n-j-1));
			}
			if(mnc[cur] != 1e6)
			{
				ans[cur] = max(ans[cur], abs(mnc[cur]-j) * (i));
				ans[cur] = max(ans[cur], abs(mnc[cur]-j) * (n-i-1));
			}
		}
	}
	FOR(i,0,10)
	{
		// same row
		FOR(j,0,n)
		{
			if(dpr[j][i][0]!=-1)
			{
				ans[i] = max(ans[i], (dpr[j][i][0]-dpr[j][i][1]) * (j));
				ans[i] = max(ans[i], (dpr[j][i][0]-dpr[j][i][1]) * (n-j-1));
			}
		}
		// same col
		FOR(j,0,n)
		{
			if(dpc[j][i][0]!=-1)
			{
				ans[i] = max(ans[i], (dpc[j][i][0]-dpc[j][i][1]) * (j));
				ans[i] = max(ans[i], (dpc[j][i][0]-dpc[j][i][1]) * (n-j-1));
			}
		}
	}
	FOR(i,0,10)cout << ans[i]<<" ";
	cout << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
	  freopen("in.txt", "r", stdin);
	  freopen("out.txt", "w", stdout);
	#else
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	#endif
	int t;cin >> t;while(t--)
	fff();
	return 0;
}