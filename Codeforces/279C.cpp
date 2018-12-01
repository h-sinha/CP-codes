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
ll lft[100002],rht[100002],a[100002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,l,r;
	 	cin>>n>>m;
	 	FOR(i,0,n)cin>>a[i];
	 	lft[0]=1,rht[n-1]=1;
	 	FOR(i,1,n)
	 	{
	 		if(a[i]<=a[i-1])
	 			lft[i]=lft[i-1]+1;
	 		else
	 			lft[i]=1;
	 	}
	 	RFOR(i,n-2,0)
	 	{
	 		if(a[i]<=a[i+1])
	 			rht[i]=rht[i+1]+1;
	 		else
	 			rht[i]=1;
	 	}
	 	while(m--)
	 	{
	 		cin>>l>>r;
	 		l--,r--;
	 		if(lft[r]+rht[l] >= (r-l)+1)cout<<"Yes\n";
	 		else cout<<"No\n";
	 	}
		return 0;
}