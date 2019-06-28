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
set<string> v[L];
string s;
ll n,k;
ll ans = 0,cc;
void pre(int n)
{
	string cur, cur1;
	v[n].insert(s);
	k--;
	string y;
	RFOR(i,n-1,1)
	{
		if(k==0)return;
		trace(v[i+1], x)
		{
			FOR(j,0,i+1)
			{
				y = x;
				y.erase(y.begin()+j);
				v[i].insert(y);
			}
		}
		cc = min(k,sz(v[i]));
		ans += (cc*(n-i));
		k-=cc;
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin >> n >> k;
		cin >> s;
		pre(n);
		if(k == 1)
		{
			cout<<ans+n;
			return 0;
		}
		if(k>0)cout<<"-1";
		else cout<<ans;
		return 0;
}