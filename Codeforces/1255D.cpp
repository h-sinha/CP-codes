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

const int L=1e2+7;
int r, c, k;
string str[L];
std::vector<char> v;
char ans[L][L];
void merge(int x1, int y1, int x2, int y2, char val)
{
	if(x1 == x2)
	{
		if(y1 > y2)swap(y1,y2);
		while(y1 < y2)ans[x1][y1++] = val;
		return;
	}
	int j = y1;
	if(x1&1)while(j >= 0)ans[x1][j--] = val;
	else while(j < c)ans[x1][j++] = val;
	FOR(i,x1+1,x2)
		FOR(j,0,c)
			ans[i][j] = val;
	j = y2;
	if(x2%2==0)while(j >= 0)ans[x2][j--] = val;
	else while(j < c)ans[x2][j++] = val;
}
void process(int &idx, int &prx, int &pry, int &tf, int &f, int &co, int i, int j)
{
	co++;
	ans[i][j] = v[idx];
	if(co > 1)merge(prx, pry, i, j, v[idx]);
	prx = i, pry = j;
	if(f && co == tf)
	{
		f--;
		co = 0;
		prx = -1, pry = -1;
		idx++;
	}
	else if(!f && co == tf + 1)
	{
		co = 0;
		prx = -1, pry = -1;
		idx++;
	}
}
void solve()
{
	memset(ans, '*', sizeof(ans));
	cin >> r >> c >> k;
	int co = 0;
	FOR(i,0,r)
	{
		cin >> str[i];
		FOR(j,0,c)
			if(str[i][j] == 'R')co++;
	}
	int idx = 0, prx, pry, tf = co/k;
	int f = k - co%k;
	co = 0;
	FOR(i,0,r)
	{
		if(i%2==0)
		{
			FOR(j,0,c)
				if(str[i][j] == 'R')
					process(idx, prx, pry, tf, f, co, i, j);
		}
		else
		{
			RFOR(j,c-1,0)
				if(str[i][j] == 'R')
					process(idx, prx, pry, tf, f, co, i, j);
		}
	}
	char prv = 'a';
	FOR(i,0,r)
	{
		if(i&1)
		{
			RFOR(j,c-1,0)
			{
				if(ans[i][j] == '*')ans[i][j] = prv;
				else prv = ans[i][j];
			}
		}
		else
		{
			FOR(j,0,c)
			{
				if(ans[i][j] == '*')ans[i][j] = prv;
				else prv = ans[i][j];
			}
		}
	}
	FOR(i,0,r)
	{
		FOR(j,0,c)cout<<ans[i][j];
		cout<<ln;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	FOR(i,0,26)v.pb(char('a' + i));
	FOR(i,0,26)v.pb(char('A' + i));
	FOR(i,0,10)v.pb(char('0' + i));
	cin >> t;
	while(t--)solve();
	return 0;
}