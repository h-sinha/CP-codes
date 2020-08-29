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
const int L=32;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
    ll temp=1;
    while(y>0)
    {
        if(y&1)temp = ((temp%m)*(x%m))%m;
        x = ((x%m)*(x%m))%m;
        y>>=1;
    }return temp;
}
ll d, m, dp[L];
ll solve(int x)
{
    if((1<<x)>d)return 1;
    ll &ret = dp[x];
    if(ret != -1)return ret;
    ret = 1;
    ll l, r;
    FOR(i,x,30)
    {
        r = (1LL<<(i+1)) - 1;
        l = 1LL<<i;
        if(l>d)break;
        dp[x] = (dp[x] + ((min(r, d) - l + 1) * solve(i+1))%m)%m;
    }
    return dp[x];
}
void fff()
{
    cin >> d >> m;
    FOR(i,0,31)dp[i] = -1;
    cout << (solve(0)-1+m)%m << ln;
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