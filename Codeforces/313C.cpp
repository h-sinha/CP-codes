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
const int L=2e6+7;
std::vector<ll> a;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,ans=0,t;
	 	cin>>n;
	 	FOR(i,0,n){cin>>t;a.pb(t);}
	 	sort(a.rbegin(),a.rend());
	 	ll cur=n,co=0;
	 	while(cur>1)co++,cur/=4;
	 	cur=1;
	 	co++;
	 	int idx=0;
	 	while(co)
	 	{
	 		// cout<<co<<" "<<idx<<" "<<cur<<ln;
	 		FOR(i,idx,cur)
	 		{
	 			// cout<<i<<" "<<co<<ln;
	 			ans+=a[i]*co;
	 		}
	 		co--;
	 		idx=cur;
	 		cur*=4;
	 	}
		cout<<ans;
		return 0;
}