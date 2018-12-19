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
int b[3][3], a[3][3];
bool checkRow(int sumis)
{
	int sum1 = 0;
	FOR(i,0,3)
	{
		sum1 = 0;
		FOR(j,0,3)
		{
			sum1 += b[i][j];
		}
		// debug(sum1);
		if(sum1 != sumis)return 0;
	}
	return 1;
}
bool checkCol(int sumis)
{
	int sum1 = 0;
	FOR(j,0,3)
	{
		sum1 = 0;
		FOR(i,0,3)
		{
			sum1 += b[i][j];
		}
		if(sum1 != sumis)return 0;
	}
	return 1;
}
bool checkDiag(int sumis)
{
	int sum1  = b[0][0] + b[1][1] + b[2][2];
	int sum2  = b[0][2] + b[1][1] + b[2][0];
	if(sum1 != sumis || sum2 != sumis)return 0;
	return 1;
}
int calc()
{
	int ans = 0;
	FOR(i,0,3)FOR(j,0,3)ans += abs(a[i][j] - b[i][j]);
	return ans;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int ans = INT_MAX, sumis;
	 	FOR(i,0,3)FOR(j,0,3)cin >> a[i][j];
	 	int aux[9] = {1,2,3,4,5,6,7,8,9};
	 	do{
	 		FOR(i,0,3)FOR(j,0,3)b[i][j] = aux[i*3 + j];
	 		sumis = b[0][0] + b[1][1] + b[2][2];
	 		if(checkDiag(sumis) && checkRow(sumis) && checkCol(sumis))
	 		{
	 				ans = min(ans, calc());
	 		}
	 	}while(next_permutation(aux, aux+9));
	 	cout<<ans;
		return 0;
}