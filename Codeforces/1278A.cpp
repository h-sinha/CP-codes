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

const int L=1e2+7;
int co[L][30];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string p,h;
	cin >> t;
	while(t--)
	{
		std::vector<int> co1(L);
		cin >> p;
		cin >> h;
		memset(co, 0, sizeof(co));
		int n = p.length();
		int m = h.length();
		FOR(i,0,n)
			co1[p[i]-'a']++;
		FOR(i,0,m)
			co[i][h[i]-'a']++;
		FOR(i,1,m)
			FOR(j,0,26)co[i][j] += co[i-1][j];
		int ans = 0;
		FOR(i,0,m)
		{
			int f = 0;
			if(i+n-1 >= m)break;
			FOR(j,0,26)
			{
				if(i==0)
				{
					if(co1[j] != co[i+n-1][j])
					{
						f = 1;
						break;
					}
				}
				else
				{
					if(co1[j] != co[i+n-1][j] - co[i-1][j])
					{
						f = 1;
						break;
					}
				}
			}
			if(!f)
			{
				ans = 1;
				break;
			}
		}
		if(ans == 1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}