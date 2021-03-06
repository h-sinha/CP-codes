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
int a[L], co[L], co1[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,0,n)
	 		cin >> a[i];
	 	sort(a,a+n);
	 	vector<int> v;
	 	FOR(i,0,n)
	 	{
	 		FOR(j,i+1,n)
	 		{
	 			co[a[j]-a[i]]++;
	 			co1[a[j]-a[i]]++;
	 		}
	 	}
	 	FOR(i,1,5001)co[i] += co[i-1];
	 	ld num = 0, deno = pow(co[5000],3), tot;
	 	FOR(i,0,5000)
	 	{
	 		FOR(j,i,5000)
	 		{
	 			if(i+j>=5000)break;
	 			if(co1[i]*co1[j] == 0)continue;
	 			tot = co[5000]-co[i+j];
	 			if(i == j)num += tot*co1[i]*co1[j];
	 			else num += tot*co1[i]*co1[j]*2;
	 			// debug(i,j,co1[i],co1[j],tot);
	 		}
	 	}
	 			// debug(num,deno);
	 	printf("%.10Lf\n",num/deno);
		return 0;
}