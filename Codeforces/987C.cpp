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
map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll ans=INT_MAX,n,s[30002],c[30002];
	 	cin>>n;
	 	FOR(i,0,n)cin>>s[i];
	 	FOR(i,0,n)cin>>c[i];
	 	FOR(i,1,n-1)
	 	{
	 		ll l=i-1,r=i+1,bm=INT_MAX,am=INT_MAX;
	 		while(l>=0 || r<=n-1)
	 		{
	 			if(l>-1)
	 			{
	 				if(s[l]<s[i] && c[l]<bm)
	 				{
	 					bm=c[l];
	 				}
	 				l--;
	 			}
	 			if(r<n)
	 			{
	 				if(s[r]>s[i] && c[r]<am)
	 				{
	 					am=c[r];
	 				}
	 				r++;
	 			}
	 		}
	 		// cout<<i<<" "<<c[i]<<" "<<am<<" "<<bm<<endl;
	 		if(am==INT_MAX || bm==INT_MAX)continue;
	 		ans=min(ans,bm+am+c[i]);
	 	}
	 	if(ans==INT_MAX)cout<<"-1";
	 	else cout<<ans<<ln;
		return 0;
}