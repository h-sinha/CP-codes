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
map<ll,string> counter;
ll m= 514229;
std::vector<pii> v[514230];
std::map<string, ll> co;
// std::vector<pii> ans;
set<pii>ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll h1,h2,n,d,t,cur=0;
	 	cin>>n>>d;
	 	string s1,s2;
	 	// hash<string>hs;
	 	FOR(i,0,n)
	 	{
	 		cin>>s1>>s2>>t;
	 		if(co.find(s1)==co.end())
	 			co[s1]=cur++;
	 		if(co.find(s2)==co.end())
	 			co[s2]=cur++;
	 		// h1=hs(s1)%m;
	 		// h2=hs(s2)%m;
	 		h1=co[s1],h2=co[s2];
	 		v[h1].pb(mp(h2,t));
	 		counter[h1]=s1,counter[h2]=s2;
	 	}
	 	FOR(i,0,m)
	 	{
	 		if(sz(v[i])==0)continue;
	 		trace(v[i],x)
	 		{
	 			trace(v[x.F],y)
	 			{
	 				if(y.F==i)
	 				{
	 					if(x.S-y.S>0 && x.S-y.S<=d)
	 					{
	 						if(i<x.F)
	 						ans.insert( mp(i,x.F) );
	 						else
	 						ans.insert( mp(x.F,i) );
	 					}
	 				}
	 			}
	 		}
	 	}
	 	cout<<sz(ans)<<ln;
	 	trace(ans,x)
	 	cout<<counter[x.F]<<" "<<counter[x.S]<<ln;
		return 0;
}