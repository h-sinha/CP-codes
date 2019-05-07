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
int a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >>n;
	 	FOR(i,0,n)cin >> a[i];
		FOR(i,0,n-1)
		{
			if(a[i] == a[i+1])
			{
				cout<<"Infinite";
				return 0;
			}
			if(a[i]==2 && a[i+1]==3)
			{
				cout<<"Infinite";
				return 0;
			}
			if(a[i]==3 && a[i+1]==2)
			{
				cout<<"Infinite";
				return 0;
			}
		}
		int ans = 0;
		cout<<"Finite\n";
		FOR(i,0,n-1)
		{
			if(a[i]==1 && a[i+1] == 2)ans+=3;
			else if(a[i]==2 && a[i+1] == 1)ans+=3;
			else if(a[i]==1 && a[i+1] == 3)ans+=4;
			else if(a[i]==3 && a[i+1] == 1)ans+=4;
			if(i-1>=0 && a[i+1] == 2 && a[i-1] == 3)ans--; 
		}
		cout<<ans;
		return 0;
}