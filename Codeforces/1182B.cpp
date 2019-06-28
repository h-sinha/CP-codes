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

const int L=502;
char a[L][L];int h,w;
int mark[L][L], tot ;
bool markit(int x, int y)
{
	tot = 0;
	int i = x+1, j = y;
	int co = 0;
	mark[x][y]++;
	while(i<h)
	{
		if(a[i][j] != '.')
		{
			mark[i][j]++;
		}
		else break;
		i++;
	}
	i = x-1, j = y;
	while(i>=0)
	{
		if(a[i][j] != '.')
		{
			mark[i][j]++;
		}
		else break;
		i--;
	}
	i = x, j = y-1;
	while(j>=0)
	{
		if(a[i][j] != '.')
		{
			mark[i][j]++;
		}
		else break;
		j--;
	}
	i = x, j = y+1;
	while(j<w)
	{
		if(a[i][j] != '.')
		{
			mark[i][j]++;
		}
		else break;

		j++;
	}
	return 1;
}
bool check(int x, int y)
{
	int i = x+1, j = y;
	int co = 0;
	while(i<h)
	{
		if(a[i][j] != '.')
		{
			co++;
		}
		else break;

		i++;
	}
	if(co == 0)return 0;
	i = x-1, j = y;
	co = 0;
	while(i>=0)
	{
		if(a[i][j] != '.')
		{
			co++;
		}
		else break;

		i--;
	}
	if(co == 0)return 0;
	co = 0;
	i = x, j = y-1;
	while(j>=0)
	{
		if(a[i][j] != '.')
		{
			co++;
		}
		else break;

		j--;
	}
	if(co == 0)return 0;
	co = 0;
	i = x, j = y+1;
	while(j<w)
	{
		if(a[i][j] != '.')
		{
			co++;
		}
		else break;
		j++;
	}
	if(co == 0)return 0;
	markit(x,y);
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin >> h >> w;
		int co = 0;
		FOR(i,0,h)
		{
			FOR(j,0,w)
			{
				cin >> a[i][j];
				if(a[i][j] == '*')co++;
			}
		}	 
		int f = 0;
		FOR(i,0,h)
		{
			FOR(j,0,w)
			{
				// cout<<a[i][j];
				if(a[i][j] == '*')
				{
					if(check(i,j))
					{
						f = 1;
						break;
					}
				}
			}
			if(f)break;
		}
		FOR(i,0,h)
		{
			FOR(j,0,w)
			{
				if(a[i][j] == '*')
				{
					// debug(i,j,mark[i][j]);
					if(mark[i][j] != 1)
					{
						cout<<"NO\n";
						return 0;
					}
				}
			}
		}
		if(f)
		cout<<"YES\n";
		else cout<<"NO\n";

		return 0;
}