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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
std::vector<int> done(30), co(30);
set<int>v[L];
string out = "";
void dfs(int vertex)
{
	char cur = char(97+vertex);
	done[vertex] = 1;
	FOR(i,0,co[vertex])out += cur;
	trace(v[vertex], x)
	{
		if(!done[x])
			dfs(x);
	}
}
bool check(int len)
{
	int l1 = out.length();
	if(len != l1)return 0;
	FOR(i,0,len-1)
	{
		if(abs(out[i]-out[i+1])==1)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, cur, a, b;
	 	cin >> t;
	 	string s;
	 	set<int>ver;
	 	while(t--)
	 	{
	 		out = "";
	 		cin >> s;
	 		int len = s.length();
	 		fill(all(co),0);
	 		FOR(i,0,27)v[i].clear();
	 		FOR(i,0,len)
	 		{
	 			cur = s[i]-'a';
	 			co[cur]++;
	 		}
	 		sort(all(s));
	 		ver.clear();
	 		FOR(i,0,len)
	 		{
	 			ver.insert(s[i]-'a');
	 			FOR(j,0,len)
	 			{
	 				if(abs(s[i]-s[j]) > 1)
	 				{
	 					a = s[i] - 'a';
	 					b = s[j] - 'a';
	 					v[a].insert(b);
	 					v[b].insert(a);
	 				}
	 			}
	 		}
	 		int f = 0;
	 		trace(ver, x)
	 		{
	 			fill(all(done), 0);
	 			dfs(x);
	 			if(check(len))
	 			{
	 				f = 1;
	 				break;
	 			}
	 			out = "";
	 		}
	 		fill(all(done), 0);
	 		ver.clear();
	 		if(f)cout<<out<<ln;
	 		else cout<<"No answer\n";
	 	}
		return 0;
}