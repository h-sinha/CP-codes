#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
map<ll,ll> counter;
int ans[3002],parent[3002],deg[1002],info[1002];
void find(int vertex)
{
	if (ans[vertex] == -1) 
	{
        find(parent[vertex]);
        ans[vertex] = ans[parent[vertex]]+1;
    }
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int par,a,b,top,n;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a>>b;
	 		deg[a]++;
	 		deg[b]++;
	 		info[b]^=a;
	 		info[a]^=b;
	 	}
	 	queue<int>q;
	 	FOR(i,1,n+1)if(deg[i]==1)q.push(i);
	 	while(sz(q))
	 	{
	 		top=q.front();
			q.pop();
			ans[top]=-1;
	 		par=info[top];
	 		parent[top]=par;
	 		info[par]^=top;
	 		deg[par]--;
	 		if(deg[par]==1)q.push(par);
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		find(i);
	 		cout<<ans[i]<<" ";
	 	}
		return 0;
}