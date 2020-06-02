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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=5007;
std::vector<int> visit(L), col(L,-1);
std::vector<int> v[L];
std::vector<int> comp[L];
int cur_comp, counter[L][2], dp[L][L][2], aux[L][2];
int n, m, n1, n2, n3, a, b, f1;
int solve(int i, int s, int f)
{
	if(f1)return 0;
	if(i >= cur_comp-1)
	{
		if(s == n2)
		{
			aux[i][f] = 1;
			f1 = 1;
			return 1;
		}
		return 0;
	}
	if(dp[i][s][f] != -1)return dp[i][s][f];
	int &ret = dp[i][s][f]; 
	ret = 0;
	ret = solve(i+1,s+counter[i+1][0],0);
	ret |= solve(i+1,s+counter[i+1][1],1);
	if(ret)aux[i][f] = 1;
	return ret;
}
void dfs(int vertex, int c = 0)
{
	if(visit[vertex])
	{
		if(col[vertex] != c)
		{
			cout<<"NO\n";
			exit(0);
		}
		return;
	}
	comp[cur_comp].pb(vertex);
	col[vertex] = c;
	counter[cur_comp][c]++;
	visit[vertex] = 1;
	trace(v[vertex], x)
	{
		dfs(x, 1-c);
	}

}
void fff()
{
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	FOR(i,0,m)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i,0,n+1)
	{
		FOR(j,0,n)FOR(k,0,2)dp[i][j][k] = -1;
		if(i>0&&!visit[i])
		{
			dfs(i);
			cur_comp++;
		}
	}
	int c,ret = solve(0,counter[0][0],0);
	int co = 0;
	if(ret)
	{
		string s = "";
		FOR(i,0,n)s += "0";
		FOR(i,0,cur_comp)
		{
			if(aux[i][0])c = 0;
			else c = 1;
			trace(comp[i],x)
			{
				if(col[x] == c)s[x-1] = '2';
				else if(co<n1)s[x-1] = '1',co++;
				else s[x-1] = '3';
			}
		}
		cout<<"YES\n";
		cout<<s<<ln;
	}
	else 
	{
		ret = solve(0,counter[0][1],1);
		if(ret == 0)
		{
			cout<<"NO\n";
			return;
		}
		string s = "";
		FOR(i,0,n)s += "0";
		FOR(i,0,cur_comp)
		{
			if(aux[i][0])c = 0;
			else c = 1;
			trace(comp[i],x)
			{
				if(col[x] == c)s[x-1] = '2';
				else if(co<n1)s[x-1] = '1',co++;
				else s[x-1] = '3';
			}
		}
		cout<<"YES\n";
		cout<<s<<ln;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}