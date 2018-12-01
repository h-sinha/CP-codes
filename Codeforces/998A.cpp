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
const int L=1e5+7;
map<ll,ll> counter;
ll a[L];
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	ll sumis=0;
	 	std::vector<ll> ans;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		counter[a[i]]++;
	 	}
	 	ll val=INT_MAX,f=0;
	 	// if(sz(counter)==1){cout<<"-1";return 0;}
	 	trace(counter,x)
	 	{
	 		val=min(x.F,val);

	 		// break;
	 	}
	 	// cout<<val<<ln;
	 	// cout<<n-1<<ln;
	 	FOR(i,0,n)
	 	{
	 		if(a[i]==val && f==0){f=1;continue;}
	 		// cout<<i+1<<" ";
	 		ans.pb(i+1);
	 		sumis+=a[i];
	 	}
	 	if(sumis==val||sz(ans)==0){cout<<"-1";return 0;}
	 	cout<<n-1<<ln;
	 	trace(ans,x)cout<<x<<" ";
		return 0;
}