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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=2e3+7;
int n, m, lmax, rmax, r, c;
string s[L];
int dist[L][L], dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
bool danger(int x, int y)
{
	if(x<0 || y <0 || x>=n || y>=m || s[x][y]=='*')return 1;
	return 0;
}
void solve()
{
	queue<pii>q;
	q.push({r,c});
	dist[r][c] = 0;
	pii tmp;int x, y;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		x = tmp.F, y = tmp.S;
		FOR(i,0,4)
		{
			if(!danger(x + dx[i], y + dy[i]))
			{
				if(dy[i] == -1 && dist[x + dx[i]][y + dy[i]] > dist[x][y] + 1)
				{
					dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
					q.push({x + dx[i], y + dy[i]});
				}
				else if(dy[i] != -1 && dist[x + dx[i]][y + dy[i]] > dist[x][y])
				{
					dist[x + dx[i]][y + dy[i]] = dist[x][y] ;
					q.push({x + dx[i], y + dy[i]});
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> r >> c;
	cin >> lmax >> rmax;
	r--,c--;
	FOR(i,0,n)cin >> s[i];
	FOR(i,0,n)FOR(j,0,m)dist[i][j] = lmax+1;
	solve();
	int co = 0, co1 = 0;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(dist[i][j] != lmax + 1 && j-c+dist[i][j] <= rmax)
			{
				co++;
			}
		}
	}
	cout<<co;
	return 0;
}