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
const int L=1e6+7;
std::vector<int> v[L];
ll a[L], spf[L], ans[L];
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<L; i++) 
        spf[i] = i; 
    for (int i=4; i<L; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<L; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<L; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int go(ll x)
{
	ll tx = x, f = 0, cur;
	while (x != 1) 
    { 
    	if(sz(v[spf[x]]))f = 1;
        v[spf[x]].pb(x);
        cur = spf[x];
        while(x%cur == 0)x/=cur;
    } 
    return f;
}
void fff()
{
	sieve();
	int n;
	cin >> n;
	ll g = 0;
	int co = 0;
	FOR(i,0,n)
	{
		cin >> a[i];
		ans[i] = go(a[i]);
		co += ans[i];
		g = __gcd(g, a[i]);
	}
	if(co == 0)cout <<"pairwise coprime\n";
	else if(g == 1) cout << "setwise coprime\n";
	else cout <<"not coprime\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}