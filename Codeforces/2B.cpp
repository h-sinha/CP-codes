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

const int L=1e3+7;
int a[L][L], f[L][L], t[L][L], n, z, x, y;
void init()
{
	int co2, co5, tmp;
	FOR(i,1,n+1)
	{
		FOR(j,1,n+1)
		{
			co2 = 0, co5 = 0;
			if(a[i][j] == 0)
			{
				z = 1;
				x = i, y = j;
			}
			else
			{
				tmp = a[i][j];
				while(tmp%2==0)co2++, tmp/=2;
				while(tmp%5==0)co5++, tmp/=5;
			}
			if(i-1>=1 && j-1>=1)
			{
				t[i][j] = min(t[i-1][j] , t[i][j-1]) + co2;
				f[i][j] = min(f[i-1][j] , f[i][j-1]) + co5;
			}
			else if(i-1>=1)
			{
				t[i][j] = t[i-1][j] + co2;
				f[i][j] = f[i-1][j] + co5;
			}
			else if(j-1>=1)
			{
				t[i][j] = t[i][j-1] + co2;
				f[i][j] = f[i][j-1] + co5;
			}
			else
			{
				t[i][j] = co2;
				f[i][j] = co5;
			}
		}
	}
}
void movet(int i, int j)
{
	if(i==1 && j==1)return;
	if(t[i-1][j]<t[i][j-1])
	{
		movet(i-1,j);
		cout<<"D";
	}
	else
	{
		movet(i,j-1);
		cout<<"R";
	}
}
void movef(int i, int j)
{
	if(i==1 && j==1)return;
	if(f[i-1][j]<f[i][j-1])
	{
		movef(i-1,j);
		cout<<"D";
	}
	else
	{
		movef(i,j-1);
		cout<<"R";
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
	 	FOR(i,1,n+1)
	 		FOR(j,1,n+1)
	 			cin >> a[i][j];
	 	init();
	 	int ans = min(f[n][n], t[n][n]);
	 	FOR(i,0,n+2)f[0][i] = t[0][i] = INT_MAX;
	 	FOR(i,0,n+2)f[n+1][i] = t[n+1][i] = INT_MAX;
	 	FOR(i,0,n+2)f[i][0] = t[i][0] = INT_MAX;
	 	FOR(i,0,n+2)f[i][n+1] = t[i][n+1] = INT_MAX;
	 	if(z)
	 	{
	 		ans = min(1, ans);
	 		if(ans == 1)
	 		{
	 			cout<<1<<ln;
	 			int i = 1, j = 1;
	 			while(i!=x){cout<<"D";i++;}
	 			while(j!=y){cout<<"R";j++;}
	 			while(x!=n){cout<<"D";x++;}
	 			while(y!=n){cout<<"R";y++;}
	 			return 0;
	 		}
	 	}
	 	cout<<ans<<ln;
	 	if(ans == t[n][n])movet(n,n);
	 	else movef(n,n);
		return 0;
}