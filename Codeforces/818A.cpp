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
ll ans=0;
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
ld n,k;
bool check(ld val)
{
	// cout<<val*(1+k)<<" "<<val<<ln;
	if(val*(1+k)<=n/2)return 1;
	return 0;
}
void ser()
{
	ld l=0,r=1e12,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
		// cout<<l<<" "<<r<<" "<<mid<<ln;
	}
	// cout<<l<<" "<<r<<" "<<mid;
	if(!check(r))r=l;
	if(!check(ceil(r)))r=floor(r);
	else r=ceil(r);
	printf("%.0Lf %.0Lf %.0Lf\n",r,k*r,n-r*(1+k) );
	// cout<<r<<" "<<k*r<<" "<<n-r*(1+k);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	// ll n,k;
	 	cin>>n>>k;
	 	ser();
		return 0;
}