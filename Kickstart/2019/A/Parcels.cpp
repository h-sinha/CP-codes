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
#define pb insert_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
struct node
{
	int i, j, dist;	
};

class comp
{
public:
    bool operator() (node x, node y)
    {
        return x.dist < y.dist;
    }
};
typedef	priority_queue<node,std::vector<node>,comp > revpr;

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
string grid[255];
int dist[255][255],dist1[255][255], r, c;
// revpr q;
multiset<node, comp>q;
void init()
{
	node temp;
	while(!q.empty())q.erase(q.begin());
	FOR(i,1,r+1)
	{
		FOR(j,1,c+1)
		{
			if(grid[i][j] == '1')
	 		{
	 			dist[i][j] = 0;
	 			temp.i = i, temp.j = j, temp.dist = 0;
	 			q.insert(temp);
	 		}
	 		else dist[i][j] = INT_MAX;
	 	}
	 }
}
bool danger(int i, int j)
{
	if(i < 1 || j < 1 || i > r || j > c)return 0;
	return 1;
}
int bfs()
{
	node cur, temp;
	int ans = INT_MIN;
	// debug(sz(q));
	while(!q.empty())
	{
		cur = *q.begin();
		// debug(cur.i, cur.j,cur.dist);
		q.erase(q.begin());
		if(danger(cur.i + 1, cur.j) && dist[cur.i + 1][cur.j] >= cur.dist + 1)
		{
			temp.i = cur.i + 1;
			temp.j = cur.j;
			temp.dist = cur.dist + 1;
			q.insert(temp);
	 			// debug(temp.i, temp.j, temp.dist);
			dist[temp.i][temp.j] = temp.dist;
		}
		if(danger(cur.i, cur.j + 1) && dist[cur.i][cur.j + 1] >= cur.dist + 1)
		{
			temp.i = cur.i;
			temp.j = cur.j + 1;
			temp.dist = cur.dist + 1;
			q.insert(temp);
	 			// debug(temp.i, temp.j, temp.dist);
			dist[temp.i][temp.j] = temp.dist;
		}
		if(danger(cur.i - 1, cur.j) && dist[cur.i - 1][cur.j] >= cur.dist + 1)
		{
			temp.i = cur.i - 1;
			temp.j = cur.j;
			temp.dist = cur.dist + 1;
			q.insert(temp);
	 			// debug(temp.i, temp.j, temp.dist);
			dist[temp.i][temp.j] = temp.dist;
		}
		if(danger(cur.i, cur.j - 1) && dist[cur.i][cur.j - 1] >= cur.dist + 1)
		{
			temp.i = cur.i;
			temp.j = cur.j - 1;
			temp.dist = cur.dist + 1;
			q.insert(temp);
	 			// debug(temp.i, temp.j, temp.dist);
			dist[temp.i][temp.j] = temp.dist;
		}
	}
	// cout<<ln;
	FOR(i,1,r+1)FOR(j,1,c+1)ans = max(ans, dist[i][j]);
	return ans;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	string ss;
	 	cin >> t;
	 	node temp;
	 	FOR(i,1,t+1)
	 	{
	 		cin >> r >> c;
	 		int flg = 0;
	 		FOR(i,1,r+1)
	 		{
	 			cin >> ss;
	 			grid[i] = "1" + ss;
	 		}
	 		init();
	 		// int ans = bfs(), f = 0;
	 		int out =bfs();
	 		// FOR(i,1,r+1)FOR(j,1,c+1)dist1[i][j] = dist[i][j];
	 		FOR(i,1,r+1)
	 		{
	 			FOR(j,1,c+1)
	 			{
	 				if(grid[i][j] == '0')
	 				{
	 					init();
	 					dist[i][j] = 0;
	 					temp.i = i, temp.j = j, temp.dist = 0;
	 					q.insert(temp);
	 					out = min(out, bfs());
	 				}
	 			}
	 		}
	 		cout<<"Case #"<<i<<": "<<out<<ln;
	 	}
		return 0;
}