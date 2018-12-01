#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,tmp,val;
	 	cin>>n;
	 	ll a[100002];
	 	FOR(i,0,n)cin>>a[i];
	 	if(n==1){cout<<"-1";return 0;}
	 	sort(a,a+n);

	 	if(n==2)
	 	{
	 		tmp=a[1]-a[0];
	 		if(tmp==0)
	 		{
	 			cout<<"1\n"<<a[0]<<ln;
	 			return 0;
	 		}
	 		if(tmp&1)
	 		{
	 			cout<<"2\n";
	 			cout<<a[0]-tmp<<" "<<a[1]+tmp;
	 		}
	 		else 
	 		{
	 			cout<<"3\n";
	 			cout<<a[0]-tmp<<" "<<a[0]+(tmp>>1)<<" "<<a[1]+tmp;
	 		}
	 		return 0;
	 	}
	 	FOR(i,0,n-1)counter[a[i+1]-a[i]]++;
	 	if(sz(counter)==1)
	 	{
	 		trace(counter,x)tmp=x.F;
	 		if(tmp==0){cout<<"1\n"<<a[0];return 0;}
	 		cout<<"2\n";
	 		cout<<a[0]-tmp<<" "<<a[n-1]+tmp;
	 		return 0;
	 	}
	 	// cout<<sz(counter);
	 	if(sz(counter)==2)
	 	{
	 		ll mx=INT_MIN,mn=INT_MAX,xx,nn;
	 		trace(counter,x)
	 		{
	 			if(x.S>mx){mx=x.S;xx=x.F;}
	 			if(x.S<mn){mn=x.S;nn=x.F;}
	 		}
	 		// cout<<mx<<" "<<mn;
	 		if(mx==mn)
	 		{
	 			trace(counter,x)
	 			{
	 				xx=min(x.F,xx);
	 				nn=max(nn,x.F);
	 			}
	 		}
	 		// cout<<xx<<" "<<nn;
	 		if(counter[nn]>1){cout<<"0";return 0;}
	 		ll diff;
	 		FOR(i,0,n-1)
	 		{
	 			diff=a[i+1]-a[i];
	 			// cout<<diff<<" "<<nn<<" "<<xx;
	 			if(nn==diff && diff%2==0 && diff/2==xx)
	 			{
	 				cout<<"1\n";
	 				cout<<a[i]+xx;
	 				return 0;
	 			}
	 		}
	 	}
	 	cout<<"0";
		return 0;
}