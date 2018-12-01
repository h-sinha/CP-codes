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
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
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
		ll n,m,k;
		cin>>n>>m>>k;
		if(k<=n-1)
		{
			cout<<k+1<<" 1"<<ln;
			return 0;
		}
		k-=(n);
		ll temp=(m-1)*2;
		ll rem=k%temp;
		ll div=k/temp;
		if(div==0)
		{
			if(rem<m-1)
			{
			cout<<n<<" ";
			cout<<rem+2<<ln;
			return 0;
			}
			else
			{
				cout<<n-1<<" ";
				cout<<m-(rem%(m-1))<<ln;
				return 0;
			}
		}
		if(rem<m-1)
		{
			cout<<n-(2*div)<<" ";
			cout<<rem+2<<ln;
			return 0;
		}
		else
		{
			cout<<n-(2*div)-1<<" ";
			cout<<m-(rem%(m-1))<<ln;
			return 0;
		}
		return 0;
}