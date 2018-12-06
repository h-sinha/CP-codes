#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=b;i>=a;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<bool> visit(100002);
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,k,a,mid,search;
		ll ans=0;
		std::vector<ll> arr;
	 	cin>>n>>k;
	 	FOR(i,0,n){cin>>a;arr.pb(a);}
	 	sort(arr.begin(), arr.end());
	 	FOR(i,0,n)
	 	{
	 		search=arr[i]+k;
	 		auto it=lower_bound(arr.begin(), arr.end(),search);
	 		if(*it==search)ans++;
	 	}
	 	cout<<ans<<ln;
		return 0;
}