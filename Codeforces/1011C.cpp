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
const int L=1e3+7;
ld a[L],b[L],n,m,tot;
bool check(ld val)
{
	 tot = m+val;
	tot -=(tot/a[0]);
	FOR(i,1,n)
	{
		if(tot <=m)return 0;
		tot -=(tot/b[i]);
		tot -=(tot/a[i]);
	}
	// cout<<tot<<ln;
	tot-=(tot/b[0]);
	if(tot>=m)return 1;
	return 0;
}
void ser()
{
	ld l=0,r=1e9+1,mid;
	while(abs(l-r)>1e-6)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else l=mid;
	// printf("%.6Lf--> %.6Lf\n",mid,tot );

	}
	if(!check(l))l=r;
	if(abs(l-1000000001)<=1e-6)
	{
		cout<<"-1";
		return;
	}
	printf("%.10Lf\n",l );
	// cout<<l<<" "<<r<<" "<<mid<<ln;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>m;
	 	FOR(i,0,n)cin>>a[i];
	 	FOR(i,0,n)cin>>b[i];
	 	ser();
		return 0;
}