#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
const int L = 1e5+7;
ll a[L], n, m, w, au[L];
bool check(ll val)
{
	FOR(i,0,n)au[i] = 0;
	FOR(i,0,n)au[i] = max(0LL, val - a[i]);
	ll prev = -1, sumis =0, aux = -1;
	FOR(i,0,n)cout<<au[i]<<" - ";
	cout<<ln;

	FOR(i,0,n)
	{
		
	}


	if(sumis <= m)return 1;
	return 0;
}
void ser()
{
	ll l=1,r=1e9,mid;
	while(l<r-1)
	{
		mid=l+(r-l)/2;
		cout<<l <<" "<<r<<" "<<mid<<ln;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	cout << r;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m >> w;
	 	FOR(i,0,n)cin>>a[i]; 
	 	// ser();
	 	check(500);
		return 0;
}