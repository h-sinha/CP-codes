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
#define debugfor(a) 	for(auto &x:a)cout<<x<<" "
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
ll suma=0,sumbneg[100002],sumbpos[100002],aux=0;
std::vector<ll> v;
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,q,a[100002],b[100002];
	 	cin>>n>>m>>q;
	 	FOR(i,1,n+1)cin>>a[i];
	 	FOR(i,1,m+1)cin>>b[i];
	 	FOR(i,1,n+1)
	 	{
	 		if(i&1)suma+=a[i];
	 		else suma-=a[i];
	 	}
	 	ll sign=-1;
	 	FOR(i,1,n+1){aux+=(sign*b[i]);sign*=-1;}
	 	v.pb(aux);
	 	if(n&1)sign=-1;else sign=1;
	 	FOR(i,1,m-n+1)
	 	{
	 		aux+=b[i];
	 		aux=-aux;
	 		aux+=(sign*b[i+n]);
	 		v.pb(aux);
	 	}
	 	// debugfor(v);
	 	// cout<<ln;
	 	ll len,it1,it2,l,r,x;
	 	sort(v.begin(), v.end());
	 	std::vector<ll>::iterator it;
	 	ll au=-suma;
	 	it=lower_bound(v.begin(), v.end(),au);
	 	if(it==v.end())it--;
	 	cout<<min(abs(suma+*it),abs(suma+*(it-1)))<<ln;
	 	while(q--)
	 	{
	 		cin>>l>>r>>x;
	 		len=(r-l+1);
	 		if(len&1)
	 		{
	 			if(l&1 && r&1)suma+=x;
	 			else suma-=x;
	 		}
	 		au=-suma;
	 		it=lower_bound(v.begin(), v.end(),au);
	 		if(it==v.end())it--;
	 		cout<<min(abs(suma+*it),abs(suma+*(it-1)))<<ln;
	 	}
		return 0;
}