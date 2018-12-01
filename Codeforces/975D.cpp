#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::map<pii, ll> vel;
std::vector<bool> visit(100002);
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll ans=0,n,a,b,x[200002],vy[200002],vx[200002];
	 	cin>>n>>a>>b;
	 	std::vector<pii> aux;
	 	FOR(i,0,n)
	 	{
	 		cin>>x[i]>>vx[i]>>vy[i];
	 		ans+=(counter[vy[i]-a*vx[i]]-vel[{vx[i],vy[i]}]);
	 		counter[vy[i]-a*vx[i]]++;
	 		vel[mp(vx[i],vy[i])]++;
	 	}
	 	cout<<2*ans<<ln;
		return 0;
}