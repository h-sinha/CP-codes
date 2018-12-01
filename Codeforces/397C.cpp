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
ll r=0,a[502],m=1e9+7;
ll fact[1000001];
std::map<ll, ll> power;
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
ll calc(int n,int r)
{
	if(n<r)return 0;
	return (fact[n]%m*fastexpo( (fact[r]%m*fact[n-r]%m)%m,m-2,m))%m;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	ll ans=0;
	 	cin>>n;
	 	fact[0]=fact[1]=1;
	 	FOR(i,2,1000001)
	 		fact[i] = (fact[i-1]%m * i)%m;
	 	FOR(i,0,n)cin>>a[i];
		FOR(i,0,n)
		{
			for (int j = 2; j*j <=a[i] ; ++j)
			{
				while(a[i]%j==0)a[i]/=j,power[j]++;
				if(a[i]==1)break;
			}
			// cout<<i<<" "<<a[i]<<endl;
			if(a[i]>1)power[a[i]]++;
		}
		ans=1;
		trace(power,x)
		{
			r=x.S;
			ans= (ans%m * calc(r+n-1,n-1)%m)%m;

		}
		cout<<ans;
		return 0;
}