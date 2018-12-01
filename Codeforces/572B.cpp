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
ll sellq[L],buyq[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,s,p,q;
	 	char type;
	 	cin>>n>>s;
	 	while(n--)
	 	{
	 		cin>>type>>p>>q;
	 		if(type=='S')sellq[p]+=q;
	 		else buyq[p]+=q;
	 	}
	 	int co=0;
	 	std::vector<pii> v;
	 	FOR(i,0,100001)
	 	{
	 		if(co==s)break;
	 		if(sellq[i])
	 		{
	 			v.pb(mp(i,sellq[i]));
	 			co++;
	 		}
	 	}
	 	RFOR(i,sz(v)-1,0)cout<<"S "<<v[i].F<<" "<<v[i].S<<ln;
	 	co=0;
	 	RFOR(i,100000,0)
	 	{
	 		if(co==s)break;
	 		if(buyq[i])
	 		{
	 			cout<<"B "<<i<<" "<<buyq[i]<<ln;
	 			co++;
	 		}
	 	}
		return 0;
}