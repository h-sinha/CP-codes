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
int a[52][52],mov=0,mark[102];
struct node{
	int i, j, car;
};
std::vector<node> ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,k;
	 	cin>>n>>k;
	 	FOR(i,0,4)
	 		FOR(j,0,n)
	 			cin>>a[i][j];
	 	int mov=0;
	 	node temp;
	 	int f=0;
	 	while(mov<20000)
	 	{
	 		f=0;
	 		FOR(j,0,n)
	 		{
	 			if(!a[1][j])continue;
		 		if(a[1][j]==a[0][j])
		 		{
		 			mov++;
		 			mark[a[1][j]]=1;
		 			a[1][j]=0;
		 			temp.car=a[0][j];
		 			temp.i=0,temp.j=j;
		 			ans.pb(temp);
		 		}
		 		else if(j!=0 && a[1][j-1]==0)
		 		{
		 			temp.i=1,temp.j=j-1,temp.car=a[1][j];
		 			mov++;
		 			ans.pb(temp);
		 			swap(a[1][j-1],a[1][j]);
		 			f=1;
		 		}
		 		else if(j==0 && a[2][j]==0)
		 		{
		 			temp.i=2,temp.j=j,temp.car=a[1][j];
		 			mov++;
		 			ans.pb(temp);swap(a[2][j],a[1][j]);
		 			f=1;
		 		}

		 	}
		 	RFOR(j,n-1,0)
		 	{
	 			if(!a[2][j])continue;
		 		if(a[2][j]==a[3][j] && a[2][j]!=0)
		 		{
		 			mov++;
		 			temp.car=a[2][j];
		 			mark[a[2][j]]=1;
		 			a[2][j]=0;
		 			temp.i=3,temp.j=j;
		 			ans.pb(temp);
		 		}
		 		else if(j!=n-1 && a[2][j+1]==0)
		 		{
		 			temp.i=2,temp.j=j+1,temp.car=a[2][j];
		 			mov++;
		 			ans.pb(temp);
		 			swap(a[2][j+1],a[2][j]);
		 			f=1;
		 		}
		 		else if(j==n-1 && a[1][j]==0)
		 		{
		 			temp.i=1,temp.j=j,temp.car=a[2][j];
		 			mov++;
		 			ans.pb(temp);
		 			swap(a[1][j],a[2][j]);
		 			f=1;
		 		}
		 	}
		 	if(!f)break;
	 	}
	 	FOR(i,1,k+1)
	 	{
	 		if(!mark[i] || mov>20000)
	 		{
	 			cout<<"-1";return 0;
	 		}
	 	}
	 	cout<<mov<<ln;
	 	trace(ans,x)cout<<x.car<<" "<<x.i+1<<" "<<x.j+1<<ln;
	 	return 0;
}