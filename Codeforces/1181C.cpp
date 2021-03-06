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
string s[L];
bool done[L][L];
int co[L][L], n, m, ans;
void mark(int x, int y, int co1, int co2, int co3)
{
	int j = y;
	int t1, t2, t3, sofar = 0;
	while(j<m)
	{
		t1 = t2 = t3 = 0;
		FOR(i,x,x+co1)
			if(s[i][j] == s[i][y])t1++;
		FOR(i,x+co1,x+co1+co2)
			if(s[i][j] == s[i][y])t2++;
		FOR(i,x+co1+co2,x+co1+co2+co3)
			if(s[i][j] == s[i][y])t3++;
		if(t1 != co1 || t2 != co2 || t3 != co3)
		{
			ans += (sofar * (sofar + 1))/2;
			return;
		}
		done[x][j] = 1;
		sofar++;
		j++;
	}
	ans += (sofar * (sofar + 1))/2;
}
void check(int x, int y)
{
	int co1 = 0, co2 = 0, co3 = 0;
	int i1 = x, i2, i3;
	while(i1 < n)
	{
		if(s[i1][y] == s[x][y])co1++;
		else break;
		i1++;
	}
	i2 = i1;
	while(i2 < n)
	{
		if(s[i2][y] == s[i1][y])co2++;
		else break;
		i2++;
	}
	i3 = i2;
	while(i3 < n && co3 < co2)
	{
		if(s[i3][y] == s[i2][y])co3++;
		else break;
		i3++;
	}
	if(co1 == co2 && co2 == co3)
		mark(x,y,co1,co2,co3);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin >> n >> m;
		FOR(i,0,n)cin >> s[i];
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(!done[i][j])
					check(i,j);
			}
		}
		cout<<ans;
		return 0;
}

