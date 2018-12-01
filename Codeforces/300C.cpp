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
const int L=1e6+7;
ll m=1e9+7;
map<ll,ll> counter;
ll fact[L];
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
void pre()
{
	fact[0]=fact[1]=1;
	FOR(i,2,1000001)fact[i]=(fact[i-1]*i)%m;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,a,b,cursum,tmp,ans=0;
	 	cin>>a>>b>>n;
	 	pre();
	 	int f=0;
	 	FOR(i,0,n+1)
	 	{
	 		cursum=a*i+b*(n-i);
	 		f=0;
	 		while(cursum>0)
	 		{
	 			if(cursum%10==a || cursum%10==b)cursum/=10;
	 			else {f=1;break;}
	 		}
	 		if(f)continue;
	 		tmp = (fact[i]*fact[n-i])%m;
	 		ans = (ans%m + (fact[n]*fastexpo(tmp,m-2,m))%m )%m;
	 	}
	 	cout<<ans;
		return 0;
}