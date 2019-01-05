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
#define sz(a)	int(a.size())
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
struct node
{
	int i, open, close;
};
string s[L];
node inp[L];
void solve(int i)
{
	stack <int>st;
	int len = s[i].length();
	FOR(j,0,len)
	{
		if(s[i][j] == '(')st.push(j);
		else
		{
			if(!st.empty())st.pop();
			else inp[i].close++;
		}
	}
	inp[i].open = sz(st);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> s[i];
	 		inp[i].i=i;
	 		inp[i].open=0;
	 		inp[i].close=0;
	 		solve(i);
	 	}
		int ans = 0, co = 0;
	 	multiset<int>cl,op;
		FOR(i,0,n)solve(i);
		FOR(i,0,n)
		{
			if(inp[i].open == inp[i].close && inp[i].open == 0)co++;
			else if(inp[i].open == 0)cl.insert(inp[i].close);
			else if(inp[i].close == 0)op.insert(inp[i].open);
		}
		ans += co/2;
		trace(cl,x)
		{
			if(op.find(x) != op.end())
			{
				ans++;
				op.erase(op.find(x));
			}
		}
		cout<<ans;
		return 0;
}