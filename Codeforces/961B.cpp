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
int a[L],t[L],cum[L],sumis[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,k,tm=0,tmp,au=0,aux;
	 	ll ans=0;
	 	cin >> n>>k;
	 	FOR(i,0,n)cin>>a[i];
	 	FOR(i,0,n)cin >> t[i];
	 	sumis[0]=a[0];
	 	if(t[0]){cum[0]=a[0];ans+=a[0];}
	 	FOR(i,1,n)
	 	{
	 		cum[i]+=cum[i-1];
	 		if(t[i])
	 		{
	 			cum[i]+=a[i];
	 			ans+=a[i];
	 		}
	 		sumis[i]+=a[i];
	 		sumis[i]+=sumis[i-1];
	 	}
	 	FOR(i,0,n)
	 	{
	 		if(i+k-1>=n)break;
	 		if(i>0)
	 		{
	 			tmp = sumis[i+k-1]-sumis[i-1];
	 			aux = cum[i+k-1]-cum[i-1];
	 		}
	 		else
	 		{
	 			tmp = sumis[i+k-1];
	 			aux = cum[i+k-1];
	 		}
	 		// debug3(i,aux,tmp);
	 		if(ans - aux+tmp > ans-au+tm)
	 		{
	 			au=aux,tm=tmp;
	 		}
	 	}
	 	// cout<<ans<<ln;
	 	// cout<<au<<" "<<tmp<<ln;
	 	cout<<ans-au+tm;
		return 0;
}