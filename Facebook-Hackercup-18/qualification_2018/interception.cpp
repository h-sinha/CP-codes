#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t,f=1,n;
	 	cin>>t;
	 	while(t--)
	 	{
	 		cin>>n;
	 		FOR(i,0,n+1)cin>>a[i];
	 		int flag=0;
	 		RFOR(i,n,1)
	 		{
	 			if(i+a[i-1]<0)flag=1;
	 			// cout<<t<<" "<<i+a[i-1]<<ln;
	 		}
	 		if(flag)
	 		{
	 			cout<<"Case #"<<f<<": "<<0<<ln;
	 		}
	 		else 
	 		{
	 			cout<<"Case #"<<f<<": "<<1<<ln;
	 			cout<<"0.0"<<ln;
	 		}
	 		f++;
	 	}
		return 0;
}