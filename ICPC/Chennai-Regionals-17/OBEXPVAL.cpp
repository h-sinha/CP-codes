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
ld x[L];
int main()
{
	 	int t;
	 	cin >> t;
	 	ld n ,  e, tmp;
	 	while(t--)
	 	{
	 		cin >> n >> e;
	 		int idx = -1;
	 		FOR(i,0,n)
	 		{
	 			scanf("%Lf", &x[i]);
	 			if(x[i] == e)idx = i;
	 		}
	 		if(idx != -1)
	 		{
	 			FOR(i,0,n)
	 			{
	 				if(idx == i)printf("1.00000000000000 ");
	 				else printf("0 ");
	 			}
	 			printf("\n");
	 			continue;
	 		}
	 		int big = -1, small = -1;
	 		FOR(i,0,n)
	 		{
	 			if(x[i] > e)big = i;
	 			else small = i;
	 		}
	 		ld sm = -1, bi = -1;
	 		if(big == -1 || small == -1)printf("-1\n");
	 		else
	 		{
	 			sm = (e - x[small])/(x[big] - x[small]);
	 			bi = (x[big] - e)/(x[big] - x[small]);
	 			FOR(i,0,n)
		 		{
		 			if(i == small)printf("%.20Lf ",sm );
		 			else if(i == big)printf("%.20Lf ",bi );
		 			else printf("0 ");
		 		}
		 		printf("\n");
	 		}
	 		

	 	}
		return 0;
}