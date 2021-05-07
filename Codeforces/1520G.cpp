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
#define eb emplace_back
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
const int L=2e3+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll n, m, w, a[L][L];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool danger(int x, int y)
{
	if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] == -1)return 1;
	return 0;
}
void bfs(int sx, int sy, std::vector<std::vector<ll> > &d)
{
	revpr q;
	q.push({0, sx*n+sy});
	d[sx][sy] = 0;
	int cx, cy, nx, ny;
	pii tmp;
	while(!q.empty())
	{
		tmp = q.top();
		q.pop();
		cx = tmp.S/n;
		cy = tmp.S%n;
		FOR(i,0,4)
		{
			nx = cx + dx[i];
			ny = cy + dy[i];
			if(!danger(nx, ny))
			{
				if(d[nx][ny] > d[cx][cy] + w)
				{
					d[nx][ny] = d[cx][cy] + w;
					q.push({d[nx][ny], nx*n + ny});
				}
			}
		}
	}
}
void fff()
{
	cin >> n >> m >> w;
	FOR(i,0,n)FOR(j,0,m)cin >> a[i][j];
	if(n < m)
	{
		FOR(i,0,n)
		{
			FOR(j,0,i)
			{
				swap(a[i][j], a[j][i]);
			}
		}
		swap(n, m);
	}
	std::vector<ll> tmp(m, 1e16);
	std::vector<std::vector<ll> > ds(n, tmp);
	std::vector<std::vector<ll> > de(n, tmp);
	bfs(0, 0, ds);
	bfs(n-1, m-1, de);
	ll ans = 1e16;
	ans = ds[n-1][m-1];
	ll bst = 1e16;
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(a[i][j] > 0)
			bst = min(bst, ds[i][j] + a[i][j]);
		}
	}
	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if(a[i][j] > 0)
			ans = min(ans, de[i][j] + a[i][j] + bst);
		}
	}

	if(ans == 1e16)cout << -1 << ln;
	else cout << ans << ln;
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}