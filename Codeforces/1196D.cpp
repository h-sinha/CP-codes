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

const int L=2e5+7;
map<char,int> h;
int co[L][3][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, k;
	cin >> t;
	string s;
	h['R'] = 0;
	h['G'] = 1;
	h['B'] = 2;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		FOR(i,0,n+3)FOR(j,0,3)FOR(kk,0,3)co[i][j][kk] = 0;
		FOR(i,0,n)
		{
			co[i][h[s[i]]][i%3]++;
		}
		FOR(i,1,n+3)
		{
			FOR(j,0,3)
			{
				FOR(kk,0,3)
				{
					co[i][j][kk] += co[i-1][j][kk];
				}
			}
		}
		int ans = k, cur1, cur2, cur3;
		FOR(i,0,n)
		{
			if(i+k-1>=n)break;
			FOR(j,0,3)
			{
				if(i==0)
				{
					cur1 = co[i+k-1][(j+1)%3][0]  + co[i+k-1][(j+2)%3][0] ;
					cur2 = co[i+k-1][(j)%3][1] - co[i][(j)%3][1] + co[i+k-1][(j+2)%3][1] - co[i][(j+2)%3][1];
					cur3 = co[i+k-1][(j+1)%3][2] - co[i+1][(j+1)%3][2] + co[i+k-1][(j)%3][2] - co[i+1][(j)%3][2];
					if(k == 1)cur2 = cur3 = 0;
					if(k == 2)cur3 = 0;
					ans = min(ans, cur1+cur2+cur3);
					continue;
				}
				cur1 = co[i+k-1][(j+1)%3][i%3] - co[i-1][(j+1)%3][i%3] + co[i+k-1][(j+2)%3][i%3] - co[i-1][(j+2)%3][i%3];
				cur2 = co[i+k-1][(j)%3][(i+1)%3] - co[i][(j)%3][(i+1)%3] + co[i+k-1][(j+2)%3][(i+1)%3] - co[i][(j+2)%3][(i+1)%3];
				cur3 = co[i+k-1][(j+1)%3][(i+2)%3] - co[i+1][(j+1)%3][(i+2)%3] + co[i+k-1][(j)%3][(i+2)%3] - co[i+1][(j)%3][(i+2)%3];
				if(k == 1)cur2 = cur3 = 0;
				if(k == 2)cur3 = 0;
				ans = min(ans, cur1+cur2+cur3);
			}
		}
		cout<<ans<<ln;
	}
	return 0;
}