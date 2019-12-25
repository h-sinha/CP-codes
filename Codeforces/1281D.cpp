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

const int L=100;
string s[L];
int r, c, row[L], col[L];
int solve()
{
	int tot = 0, mxr = 0, mxc = 0;
	memset(row, 0, r*sizeof(int));
	memset(col, 0, c*sizeof(int));
	FOR(i,0,r)
	{
		FOR(j,0,c)
		{
			if(s[i][j] == 'A')
			{
				row[i]++;
				col[j]++;
				tot++;
			}
			mxc = max(mxc, col[j]);
		}
		mxr = max(mxr, row[i]);
	}
	if(tot == 0)return -1;
	if(tot == r*c)return 0;
	if(row[0] == c || row[r-1] == c || col[0] == r || col[c-1] == r)return 1;
	if(s[0][0] == 'A' || s[0][c-1] == 'A' || s[r-1][0] == 'A' || s[r-1][c-1] == 'A')return 2;
	if(mxr == c || mxc == r)return 2;
	if(row[0] >= 1 || row[r-1] >= 1 || col[0] >= 1 || col[c-1] >= 1)return 3;
	return 4;	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, ret;
	cin >> t;
	while(t--)
	{
		cin >> r >> c;
		FOR(i,0,r)cin >> s[i];
		ret = solve();
		if(ret != -1)cout<<ret<<ln;
		else cout<<"MORTAL\n";
	}	
	return 0;
}