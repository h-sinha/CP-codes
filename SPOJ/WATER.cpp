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
int a[102][102],b[102][102],n,m,starti,startj,start;
int solve()
{
	queue<int>qq;
	qq.push(mp(starti,startj));
	int vertex;
	while(sz(qq))
	{
		vertex=qq.top();
		i=vertex.first;
		j=vertex.second;
		mini=min(b[i+1][j],min(b[i-1][j],min(b[i][j+1],b[i][j-1])));		
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	cin>>t;
	 	while(t--)
	 	{
	 		start=INT_MAX;
	 		cin>>n>>m;
	 		FOR(j,0,m+4)b[0][j]=-1;
	 		FOR(j,0,m+4)b[n+1][j]=-1;
	 		FOR(i,0,n+4)b[i][0]=-1;
	 		FOR(i,0,n+4)b[i][m+1]=-1;
	 		FOR(i,1,n+1)
	 		{
	 			FOR(j,1,m+1)
	 			{
	 				cin>>a[i][j];b[i][j]=a[i][j];
	 				if((i==1 || i==n) && (j==1||j==m) && a[i][j]<start)start=arr[i][j],starti=i,startj=j;
	 			}
	 		}
	 		solve();
	 	}
		return 0;
}