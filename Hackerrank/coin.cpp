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
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
char arr[52][52];
int dist[52][52];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,m,k;
		cin>>n>>m>>k;
		FOR(i,1,n+1)FOR(j,1,m+1)cin>>arr[i][j];
		queue<pii>q;
		FOR(i,1,n+1)
		{
			FOR(j,1,m+1)
			{
				if(arr[i][j]=='*')
				{
					// cout<<i<<j<<endl;
					dist[i][j]=0;
					q.push(mp(i,j));
				}
				else dist[i][j]=INT_MAX;
			}
		}
		while(sz(q))
		{
			pii temp=q.front();
			q.pop();
			if(temp.F+1<=n && dist[temp.F+1][temp.S]>dist[temp.F][temp.S]+1)
			{
				dist[temp.F+1][temp.S]=dist[temp.F][temp.S]+1;
				q.push(mp(temp.F+1,temp.S));
			}
			if(temp.F-1>=1 && dist[temp.F-1][temp.S]>dist[temp.F][temp.S]+1)
			{
				dist[temp.F-1][temp.S]=dist[temp.F][temp.S]+1;
				q.push(mp(temp.F-1,temp.S));
			}
			if(temp.S+1<=m && dist[temp.F][temp.S+1]>dist[temp.F][temp.S]+1)
			{
				dist[temp.F][temp.S+1]=dist[temp.F][temp.S]+1;
				q.push(mp(temp.F,temp.S+1));
			}
			if(temp.S-1>=1 && dist[temp.F][temp.S-1]>dist[temp.F][temp.S]+1)
			{
				dist[temp.F][temp.S-1]=dist[temp.F][temp.S]+1;
				q.push(mp(temp.F,temp.S-1));
			}
		}
		int i=1,j=1,t=0;
		while(1)
		{
			if(arr[i][j]=='U')i-=1;
			if(arr[i][j]=='D')i+=1;
			if(arr[i][j]=='R')j+=1;
			if(arr[i][j]=='L')j-=1;
			if(arr[i][j]=='*' && t<=k)
			{
				cout<<"0";
				return 0;
			}
			else break;
			t++;

		}
		}
		return 0;
}