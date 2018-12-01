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
map<ll,ll> counter;
int a[10];
char ans[102][102];
int solve(int istart,int col1,int col2)
{
	int mxi=istart,co=0;
	if(col2==0)a[0]++;
	FOR(i,0,50)ans[istart][i]=char(col1+65);
	FOR(i,istart+1,50)
	{
		if(a[col2]==1)break;
		mxi=max(i,mxi);
		if(co%2==0)
		{
			for(int j=2;j<49;j+=2)
			{
				ans[i][j]=char(col2+65);
				a[col2]--;
				if(a[col2]==1)break;
			}
		}
		else
		{
			for(int j=1;j<49;j+=2)
			{
				ans[i][j]=char(col1+65);
			}
		}
		co++;
	}
	FOR(i,istart,mxi+1)FOR(j,0,50)if(ans[i][j]=='X')ans[i][j]=char(col1+65);
	FOR(i,0,50)ans[mxi+1][i]=char(col1+65);
		a[col1]--;
	return mxi+2;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int cur,mx;
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		// a[0]--,a[1]--,a[2]--,a[3]--;
		FOR(i,0,51)FOR(j,0,51)ans[i][j]='X';
		mx=solve(0,0,1);
		mx=solve(mx,1,2);
		mx=solve(mx,2,3);
		mx=solve(mx,3,0);
		cout<<mx<<" "<<50<<ln;
		FOR(i,0,mx)
		{
			FOR(j,0,50)cout<<ans[i][j];
			cout<<ln;
		}
		return 0;
}