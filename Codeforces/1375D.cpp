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
const int L=1e3+7;
int a[L], co[L];
void fff()
{
	int n;
	cin >> n;
	multiset<int>SET;
	FOR(i,0,n+5)a[i] = 0;
	FOR(i,0,n)
	{
		cin >> a[i];
		SET.insert(a[i]);
	}
	FOR(i,0,n+2)co[i] = 0;
	int cur = 0, pos, f, tmp;
	std::vector<int> ans;
	FOR(i,0,n)
	{
		if(a[i]!=i)
		{
			FOR(j,i+1,n)
			{
				if(a[j]==i)
				{
					cur = i;
					while(1)
					{
						if(SET.find(cur)!=SET.end())
						{
							cur++;
							continue;
						}
						if(cur<n&& a[cur] != cur)
						{
							tmp = a[cur];
							a[cur] = cur;
							ans.pb(cur);
							SET.erase(SET.find(tmp));
							SET.insert(cur);
							if(cur == j)break;
							if(SET.find(tmp) == SET.end() && tmp < cur)
							{
								a[j] = tmp;
								ans.pb(j);
								SET.erase(SET.find(i));
								SET.insert(tmp);
								break;
							}
						}
						else
						{
							a[j] = cur;
							ans.pb(j);
							SET.erase(SET.find(i));
							SET.insert(cur);
							break;
						}
					}					
				}
			}
			ans.pb(i);
			SET.erase(SET.find(a[i]));
			SET.insert(i);
			a[i] = i;
		}
	}
	cout << sz(ans)<<ln;
	trace(ans,x)cout << x+1 <<" ";
	cout << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}