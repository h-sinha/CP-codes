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
int x[102],y[102];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,a,b,ans=0;
	 	cin>>n>>a>>b;
	 	FOR(i,0,n)
	 	{
	 		cin>>x[i]>>y[i];
	 	}
	 	FOR(i,0,n)
	 	{
	 		FOR(j,i+1,n)
	 		{
	 			if(x[i]*y[i] + x[j]*y[j] <= a*b)
	 			{
	 				if(x[i]+y[j]<=a && x[j]<=b &&  y[i]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[i]+y[j]<=b && x[j]<=a && y[i]<=a)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[i]+x[j]<=a && y[j]<=b && y[i]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[i]+x[j]<=b && y[j]<=a && y[i]<=a)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(y[i]+y[j]<=a && x[j]<=b && x[i]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(y[i]+y[j]<=b && x[j]<=a && x[i]<=a)ans=max(ans,x[i]*y[i] + x[j]*y[j]);

	 				if(x[j]+y[i]<=a && x[i]<=b &&  y[j]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[j]+y[i]<=b && x[i]<=a && y[j]<=a)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[i]+x[j]<=a && y[i]+y[j]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[i]+x[j]<=b && y[i]+y[j]<=a)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(x[i]+y[j]<=a && y[i]+x[j]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				if(y[i]+x[j]<=a && x[i]+y[j]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);

	 				// if(x[i]+y[j]<=a && x[j]+y[i]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);
	 				// if(x[i]+y[j]<=a && x[j]+y[i]<=b)ans=max(ans,x[i]*y[i] + x[j]*y[j]);

	 			}
	 		}
	 	}
	 	cout<<ans;
		return 0;
}