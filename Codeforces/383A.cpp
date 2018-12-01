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
const ll L=2e5+7;
bool a[L];
ll co[2],sofar[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, ans=0;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
			co[a[i]]++;
		}
		// cout<<co[0]<<" "<<co[1]<<ln;
		if(co[0]<=co[1])
		{
			if(a[0])sofar[0]=1;
			FOR(i,1,n)
			{
				if(a[i])sofar[i]++;
				sofar[i] += sofar[i-1];
			}
			FOR(i,0,n)
				if(!a[i])
					ans += sofar[i];
		}
		else
		{
			if(!a[n-1])sofar[n-1]=1;
			RFOR(i,n-2,0)
			{
				if(!a[i])sofar[i]++;
				sofar[i] += sofar[i+1];
			}
			// cout<<sofar[n-1]<<" "<<sofar[n-2]<<ln;
			FOR(i,0,n)
				if(a[i])
					ans += sofar[i];
		}
		cout << ans;
		return 0;
}