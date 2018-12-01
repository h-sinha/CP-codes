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
#define first F
#define second S
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll x,d;
		cin>>x>>d;
		ll cur=1,temp=1,co=0;
		std::vector<ll> ans;
		while(x>0)
		{
			co=0,temp=1;
			while(temp<<1 < x){temp<<=1;co++;}
			if(x<=2)
				while(x--){ans.pb(cur+d+1);cur+=d+1;}
			FOR(i,0,co)ans.pb(cur);
			x-=(temp-1);
			cur+=d+1;
		}
		cout<<sz(ans)<<ln;
		for(auto &x:ans)cout<<x<<" ";
		return 0;
}