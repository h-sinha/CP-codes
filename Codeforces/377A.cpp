#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
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
char a[502][502];
bool visit[502][502];
int co=0,n,m,k,flag=0;
int dx[5]={0,0,1,-1},dy[5]={1,-1,0,0};
bool go(int i,int j)
{	
	// if(i==2 && j==3)
	// cout<<i<<" "<<j<<" "<<a[i][j]<<ln;
	if(i>=n || j>=m || i<0 || j<0 || visit[i][j] || a[i][j]!='.')return 0;
	return 1;
}
void dfs(int i,int j)
{
	// cout<<i<<" "<<j<<ln;
	if(visit[i][j])return;
	if(flag)a[i][j]='X';
	co--;
	// cout<<i<<" "<<j<<" "<<co<<ln; 
	visit[i][j]=1;
	if(co==k)flag=1;
	FOR(q,0,4)
	{
		if(go(i+dx[q],j+dy[q]))
			dfs(i+dx[q],j+dy[q]);
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int f=0;
	 	cin>>n>>m>>k;
	 	FOR(i,0,n)
	 	{
	 		FOR(j,0,m)
	 		{
	 			cin>>a[i][j];
	 			if(a[i][j]=='.')co++;
	 		}
	 	}
	 	FOR(i,0,n)
	 	{
	 		FOR(j,0,m)
	 		{
	 			if(a[i][j]=='.')
	 			{
					dfs(i,j);
					FOR(i,0,n)
					{
						FOR(j,0,m)cout<<a[i][j];
						cout<<ln;
					}
		 			return 0;
	 			}
	 		}
	 	}
		return 0;
}