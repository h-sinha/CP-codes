#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int n,num[1000002],parent[1000002],mark[1000002],p[1000002][22];
std::vector<int> v[1000002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
void dfs(int pr,int vertex,int cur)
{
	parent[vertex]=pr;
	num[vertex]=cur+1;
	for(auto &x:v[vertex])
	{
		if(x==pr)continue;
		dfs(vertex,x,cur+1);
	}
}
void addver(int vertex,int cur)
{
	while(vertex!=cur && vertex>0)
	{
		vertex=parent[vertex];
		mark[vertex]=1;
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int k,cur,a,b;
	 	cin>>n>>k;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	parent[n]=n;
	 	dfs(-1,n,-1);
	 	for(int i = 1 ; i <= n ; ++i)
        	for(int j = 0 ; j <= 21 ; ++j)
            	p[i][j] = -1; 
	 	FOR(i,1,n+1)p[i][0]=parent[i];
	 	for (int j = 1; j<=21; ++j)
	 		FOR(i,1,n+1)
	 			if(p[i][j-1] != -1)
	 				p[i][j]=p[p[i][j-1]][j-1];
	 	k=n-k;
	 	mark[n]=1;k--;
	 	RFOR(i,n-1,1)
	 	{
	 		if(!mark[i])
	 		{
	 			cur=i;
	 			RFOR(j,21,0)
	 				if(!mark[p[cur][j]] && p[cur][j]!=-1){cur=p[cur][j];}
	 			if(k>=num[i]-num[cur]+1){mark[i]=1;addver(i,cur);k-=(num[i]-num[cur]+1);}
	 			if(!k)break;
	 		}
	 	}
	 	FOR(i,1,n+1)if(!mark[i])cout<<i<<" ";
		return 0;
}