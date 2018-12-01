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
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<int> adj[100002];
int level[100002],parent[100002][22],calc[100002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int dfs(int vertex,int pr,int lvl)
{
	parent[vertex][0]=pr;
	level[vertex]=lvl;
	calc[vertex]=1;
	for(auto &x:adj[vertex])
		if(x!=pr)
			calc[vertex]+=dfs(x,vertex,lvl+1);
	return calc[vertex];
}
int solve(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int dist=level[b]-level[a];
	int index=0;
	while(dist>0)
	{
		if(dist&1){b=parent[b][index];}
		dist>>=1;index++;
	}
	RFOR(i,18,0)
	{
		if(parent[a][i]!=-1 && parent[a][i]!=parent[b][i])
		{
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b)return a;
	return parent[a][0];
}
int find(int b,int dist)
{
	int index=0;
	while(dist>0)
	{
		if(dist&1){b=parent[b][index];}
		dist>>=1;index++;
	}
	return b;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,a,b;
	 	cin>>n;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		adj[a].pb(b);
	 		adj[b].pb(a);
	 	}
	 	dfs(1,-1,0);
	 	FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
	 	cin>>m;
	 	int dist,c1,c2,up;
	 	while(m--)
	 	{
	 		cin>>a>>b;
	 		up=solve(a,b);
	 		dist=level[a]+level[b]-2*level[up];
	 		// cout<<dist<<ln;
	 		if(a==b){cout<<n<<ln;continue;}
	 		if(dist&1){cout<<"0"<<ln;continue;}
	 		if(level[a]!=level[b])
	 		{
	 			// cout<<"up"<<up<<ln;
	 			if(level[a]>level[b])
	 			{
	 				c1=find(a,dist>>1);
	 				c2=find(a,(dist>>1)-1);
	 			}
	 			else
	 			{
	 				c1=find(b,dist>>1);
	 				c2=find(b,(dist>>1)-1);
	 				// cout<<"dis"<<(dist>>1)-1<<ln;
	 			}
	 			// cout<<"c1"<<c1<<" "<<"c2"<<c2<<ln;
	 			// cout<<calc[c1]<<" "<<calc[parent[c1][0]]<<" "<<calc[c2]<<ln;
	 			cout<<calc[c1]-calc[c2]<<ln;
	 		}
	 		else
	 		{
	 			c1=find(a,(dist>>1)-1);
	 			c2=find(b,(dist>>1)-1);
	 			// cout<<up;
	 			// cout<<"c1"<<c1<<" "<<"c2"<<c2<<ln;
	 			// cout<<"d"<<dist<<ln;
	 			// cout<<calc[c1]<<" "<<calc[parent[c1][0]]<<" "<<calc[c2]<<ln;
	 			// cout<<calc[up]-calc[c1]-calc[c2]<<ln;
	 			// cout<<calc[parent[up][0]]<<" "<<calc[up]<<ln;
	 		// 	if (parent[up][0]!=-1)
		 	// 		cout<<calc[parent[up][0]]+1-calc[up]<<ln;
				// else
				// cout<<"n"<<n<<calc[c1]<<" "<<calc[c2]<<ln;
	 			// cout<<calc[parent[up][0]]+1-calc[c1]-calc[c2]<<ln;
	 			cout<<n-calc[c1]-calc[c2]<<ln;

	 		}
	 	}
		return 0;

}