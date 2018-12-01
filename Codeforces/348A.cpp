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
ll n,a[100002],mx=INT_MIN,sumis=0;
bool check(ll val)
{
	if(sumis<=(n-1)*val)return 1;
	return 0;
}
void ser()
{
	ll l=mx,r=1e13,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else l=mid;
	}
	// cout<<l<<" "<<r<<" "<<mid;
	if(!check(l))l=r;
	cout<<l;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		mx=max(a[i],mx);
	 		sumis+=a[i];
	 	}
	 	ser();
		return 0;
}