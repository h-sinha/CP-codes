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
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll l,r;
	 	cin >> l>> r;
	 	ll val = l^r;
	 	int co=0,msb=0;
	 	while(val)
	 	{
	 		co++;
	 		if(val&1)msb=co;
	 		val>>=1;
	 	}
	 	if(msb==0)
	 	{
	 		cout<<"0";
	 		return 0;
	 	}
	 	ll temp=pow(2,msb-1),ans=0;
	 	while(msb>0)
	 	{
	 		ans +=temp; 
	 		msb--;
	 		temp>>=1;
	 	}
	 	cout<<ans;
		return 0;
}