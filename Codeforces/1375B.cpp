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
const int L=3e3+7;
map<ll,ll> counter;
int n, m, a[L][L], b[L][L], x[L][L];
void fff()
{	
	cin >> n >> m;
	FOR(i,0,n+2)FOR(j,0,m+2)x[i][j] = 0;
	FOR(i,1,n+1)FOR(j,1,m+1)cin >> a[i][j];
	int co;
	FOR(i,1,n+1)FOR(j,1,m+1)x[i][j] = 1;
	FOR(i,1,n+1)
	{
		FOR(j,1,m+1)
		{
			co = (x[i-1][j]>0);
			co += (x[i+1][j]>0);
			co += (x[i][j-1]>0);
			co += (x[i][j+1]>0);
			b[i][j] = co;
		}
	}
	FOR(i,1,n+1)
	{
		FOR(j,1,m+1)
		{
			if(b[i][j]<a[i][j])
			{
				cout <<"NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
	FOR(i,1,n+1)
	{
		FOR(j,1,m+1)cout << b[i][j]<<" ";
		cout << ln;
	}
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