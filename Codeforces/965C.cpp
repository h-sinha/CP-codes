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
typedef long long ll;
typedef long double ld;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ld ans=-1,n,k,m,d,tmp,rem;
	 	cin>>n>>k>>m>>d;
	 	FOR(i,0,d)
	 	{
	 		tmp=min(ll(m),ll(n/ll((k*i+1))));
	 		ans=max(ans,(i+1)*tmp);
	 		// cout<<(i+1)*tmp<<" ";
	 	}
	 	// cout<<ans;
	 	printf("%.0Lf\n",ans );
		return 0;
}