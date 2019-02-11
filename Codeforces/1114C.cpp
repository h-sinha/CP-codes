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
#define FOR(i,a,b)   for(int i=a;i<b;++i)
#define RFOR(i,a,b)   for(int i=a;i>=b;--i)
#define ln     "\n"
#define mp make_pair
#define pb push_back
#define sz(a)  ll(a.size())
#define F first
#define S second
#define all(c)  c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef  priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
map<ll,ll> counter;
std::vector<ll> v;
void primeFactors(ll n) 
{ 
      if(n%2==0)v.pb(2);
    while (n%2 == 0) 
    { 
        n = n/2; 
    } 
  ll tmp = sqrt(n);
    for (ll i = 3; i <= tmp; i = i+2) 
    { 
      if(n%i==0)v.pb(i);
        while (n%i == 0) 
        { 
            n = n/i; 
        } 
    } 
    if (n > 2) 
      v.pb(n);
} 
ll out = LLONG_MAX;
void solve(ll tmp, ll n, ll b)
{
     ll cur = b,co=0;
   while(cur>1 && cur%tmp==0)
     {
        cur/=tmp;
        co++;
     }

     cur = tmp;
     ll ans = 0;
     ll d = tmp;
      while(cur<=n)
     {
      ans+=(n/cur);
      if(LLONG_MAX/cur <d)break;
      cur*=d;
     }
       out = min(out,ans/co);
}
int main()
{
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ll n,b, tmp;
     cin >> n >> b;
     primeFactors(b);
     trace(v,x)solve(x,n,b);
    cout<<out;
    return 0;
}
