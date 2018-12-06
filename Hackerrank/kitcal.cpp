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
std::vector<int> v[200005];
int m = 1e9+7;
int parent[200002],level[200002],p[200002][22];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
void dfs(int pr,int vertex,int depth)
{
	level[vertex]=depth+1;
	parent[vertex]=pr;
	for(auto &x:v[vertex])
	{
		if(x==pr)continue;
		dfs(vertex,x,depth+1);
	}
	return;
}
bool comp(int a,int b)
{
	return level[a]>level[b];
}
int findlca(int x,int y)
{
	if(level[x]<level[y])swap(x,y);
	int dist=level[x]-level[y];
	while(dist>0)
	{
		int tmp=log2(dist);
	 	x=p[x][tmp];
        dist -= (1<<tmp) ; 
	 }
	 if(x==y)return x;
	 for(int j = 20 ; j >= 0 ; --j)
	 {
       	if((p[x][j] != -1) && (p[x][j] != p[y][j]))
       	{
       	     x = p[x][j] ; 
       	 	 y = p[y][j] ; 
       	}
   	}
	return parent[x];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int ans,q,temp,d1,d2,a,b,n,t,k,arr[200002];
	 	int co,x,y;
	 	cin>>n>>t;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	dfs(1,1,-1);
	 	FOR(i,1,n+1)FOR(j,0,21)p[i][j]=-1;
	 	FOR(i,1,n+1)p[i][0]=parent[i];
	 	FOR(j,1,21)FOR(i,1,n+1)if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
		while(t--)
		{
			cin>>k;
			co=0,ans=0;
			FOR(i,0,k)cin>>arr[i];
			sort(arr,arr+k,comp);
			if(k==1){cout<<"0"<<ln;continue;}
			temp=findlca(arr[0],arr[1]);
			d1=level[arr[0]]-level[temp];
			d2=level[arr[1]]-level[temp];
			d1+=d2;
			ans = ( ans + (arr[0] * arr[1] * d1%m)%m)%m;
			int prev=d1;
			int cur=temp;
			FOR(i,2,k)
			{
				temp=findlca(arr[i],cur);
				d1=level[cur]-level[temp];
				d2=level[arr[i]]-level[temp];
				ans = ( ans%m + (ans * (d1+d2)%m)%m + arr[i]*i*(prev+d1+d2)%m) %m;
				cur=temp,prev=(d1+d2)%m;
			}
			cout<<ans<<ln;
		}
		return 0;
}