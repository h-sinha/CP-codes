#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
const ll L=1e5+7;
ll zc,oc,zero,ones;
ll counter[2];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n;
	 	string a,b;
	 	cin >> n;
	 	cin >> a;
	 	cin >> b;
	 	FOR(i,0,n)
	 	{
	 		counter[a[i]-'0']++;
	 	}
	 	FOR(i,0,n)
	 	{
	 		if(a[i] == '0' && b[i]=='0')
	 		{
	 			zc+=counter[1];
	 			zero++;
	 		}
	 		else if(a[i]=='1' && b[i] == '0')
	 		{
	 			oc += counter[0];
	 			ones++;
	 		}
	 	}
	 	// cout<<zc<<" "<<oc<<" "<<zero<<" "<<ones<<ln;
	 	cout<<zc+oc-(ones*zero);
		return 0;
}