#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif
template <typename X> ostream& operator << (ostream& x,const vector<X>& v){for(int i=0;i<v.size();++i) x<<v[i]<<" ";return x;} 
template <typename X> ostream& operator << (ostream& x,const set<X>& v){for(auto it:v) x<<it<<" ";return x;} 
template <typename X, typename Y> ostream& operator << (ostream& x, const pair<X,Y>& v) {x<<v.first<<" => "<<v.second<<"\n";return x;} 
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (auto it : v) os << it.first << " => " << it.second << endl; return os; }
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
ll dp[L][2], n, h[L][2];
ll solve(int i, int cur)
{
	if( i >= n)return 0;
	if(dp[i][cur] != 0)return dp[i][cur];
	ll ret1 = h[i][cur] + solve(i+1,1-cur);
	ret1 = max(ret1, solve(i+1,cur));
	return dp[i][cur] =ret1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	FOR(i,0,n)
	cin >> h[i][0];
	FOR(i,0,n)
	cin >> h[i][1];
	cout<<max(solve(0,0), solve(0,1));
	return 0;
}