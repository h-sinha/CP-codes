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
ll a[1002][1002],mark[1002];
set<ll>v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,k,d,cur=0;
	 	cin>>n>>k>>d;
	 	if(pow(k,d)<n){cout<<"-1";return 0;}
	 	FOR(i,1,n)
	 	{
	 		FOR(j,0,d)a[i][j]=a[i-1][j];
	 		RFOR(j,d-1,0)
	 		{
	 			a[i][j]++;
	 			a[i][j]%=k;
	 			if(a[i][j])break;
	 		}
	 	}
	 	FOR(i,0,d)
	 	{
	 		FOR(j,0,n)cout<<a[j][i]+1<<" ";
	 		cout<<ln;
	 	}
		return 0;
}