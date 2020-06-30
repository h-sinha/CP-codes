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
void fff()
{
	int n;
	cin >> n;	
	if(n<=2)
	{
		if(n==1)
		{
			cout<<7<<ln;
			cout<<0<<" "<<0<<ln<<0<<" "<<1<<ln;
			cout<<1<<" "<<0<<ln<<1<<" "<<1<<ln<<1<<" "<<2<<ln;
			cout<<2<<" "<<1<<ln<<2<<" "<<2<<ln;
		}
		else if(n == 2)
		{
			cout<<10<<ln;
			cout<<0<<" "<<0<<ln<<0<<" "<<1<<ln;
			cout<<1<<" "<<0<<ln<<1<<" "<<1<<ln<<1<<" "<<2<<ln;
			cout<<2<<" "<<1<<ln<<2<<" "<<2<<ln<<2<<" "<<3<<ln;
			cout<<3<<" "<<2<<ln<<3<<" "<<3<<ln;
		}
		else
		{

		}
		return;
	}
	int l = sqrt(n);
	int r = n/l;
	l+=2,r+=2;
	cout<<l*r-4<<ln;
	FOR(j,1,r-1)cout<<0<<" "<<j<<ln;
	FOR(i,1,l-1)FOR(j,0,r)cout<<i<<" "<<j<<ln;
	FOR(j,1,r-1)cout<<l-1<<" "<<j<<ln;
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