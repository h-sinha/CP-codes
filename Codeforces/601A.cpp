#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
set<int>v[402];
std::vector<int> depth(402,INT_MAX);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m, a, b, tmp;
	 	cin >> n >> m;
	 	FOR(i,0,m)
	 	{
	 		cin >> a >> b;
	 		v[a].insert(b);
	 		v[b].insert(a);
	 	}
	 	queue<int> qq;
	 	if(v[1].find(n) == v[1].end())
	 	{
	 		qq.push(1);
		 	depth[1]=0;
	 		while(sz(qq))
	 		{
	 			tmp = qq.front();
	 			// cout<<tmp<<ln;
	 			qq.pop();
	 			trace(v[tmp],x)
	 			{
	 				if(depth[x] > depth[tmp] + 1)
	 				{
	 					depth[x] = depth[tmp] + 1;
	 					qq.push(x);
	 				}
	 			}
	 			if(tmp == n)break;
	 		}
	 		// cout<<depth[n]<<ln;
	 		if(depth[n] == INT_MAX)
	 		{
	 			cout<<"-1";
	 			return 0;
	 		}
	 		cout<<max(depth[n],1);
	 		return 0;
	 	}
	 	qq.push(1);
	 	depth[1]=0;
	 	while(sz(qq))
	 	{
	 		tmp = qq.front();
	 		qq.pop();
	 		FOR(x,1,n+1)
	 		{
	 			if(x == tmp || v[tmp].find(x) != v[tmp].end() || depth[x] < depth[tmp] + 1)continue;
	 			depth[x] = depth[tmp] + 1;
	 			qq.push(x);
	 		}
	 		if(tmp == n)break;
	 	}
	 	if(depth[n] == INT_MAX)
	 	{
	 		cout<<"-1";
	 		return 0;
	 	}
	 	cout<<max(depth[n],1);
		return 0;
}return 0;
	 	}
	 	cout<<max(depth[n],1);
		return 0;
}