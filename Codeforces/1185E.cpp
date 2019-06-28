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

const int L=2002;
char a[L][L], b[L][L];
std::map<char, int> li, ri, lj, rj;
std::map<int, char> row, col;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, cur, no, x, y, n, m;
	 	char mx;
	 	cin >> t;
	 	while(t--)
	 	{
	 		no = 0;
	 		cin >> n >> m;
	 		li.clear();
	 		ri.clear();
	 		lj.clear();
	 		rj.clear();
	 		row.clear();
	 		col.clear();
	 		FOR(i,0,n)
	 		{
	 			FOR(j,0,m)
	 			{
	 				cin >> a[i][j];
	 				if(a[i][j] == '.')
	 				{
	 					b[i][j] = '.';
	 					continue;
	 				}
	 				if(li.find(a[i][j]) == li.end())
	 					li[a[i][j]] = i;
	 				else
	 					li[a[i][j]] = min(li[a[i][j]],i);
	 				ri[a[i][j]] =  max(ri[a[i][j]],i);
	 				if(lj.find(a[i][j]) == lj.end())
	 					lj[a[i][j]] = j;
	 				else
	 					lj[a[i][j]] = min(lj[a[i][j]],j);
	 				rj[a[i][j]] =  max(rj[a[i][j]],j);
	 			}
	 		}
	 		if(li.empty())
	 		{
	 			cout<<"YES\n0\n";
	 			continue;
	 		}
	 		for (char i = 'a'; i <= 'z'; ++i)
	 		{
	 			if(li.find(i) == li.end())continue;
	 			mx = i;
	 			if(li[i]!=ri[i] && lj[i]!=rj[i])
	 			{
	 				no = 1;
	 				break;
	 			}
	 			FOR(l,li[i],ri[i]+1)
	 				FOR(r,lj[i],rj[i]+1)
	 					b[l][r] = i;
	 		}
	 		if(no)
	 		{
				cout<<"NO\n";
	 			continue;
	 		}
	 		FOR(i,0,n)
	 		{
	 			FOR(j,0,m)
	 			{
	 				if(b[i][j] != a[i][j])
	 				{
	 					no = 1;
	 					break;
	 				}
	 			}
	 		}
	 		if(no)
	 		{
				cout<<"NO\n";
	 			continue;
	 		}
	 		x = li[mx]+1, y = lj[mx]+1;
	 		cout<<"YES\n"<<(mx-'a'+1)<<ln;
	 		for (char i = 'a'; i <= mx; ++i)
	 		{
	 			if(li.find(i) == li.end())cout<<x<<" "<<y<<" "<<x<<" "<<y<<ln;
	 			else
	 			{
	 				cout<<li[i]+1<<" "<<lj[i]+1<<" "<<ri[i]+1<<" "<<rj[i]+1<<ln;
	 			}
	 		}
	 	}
		return 0;
}