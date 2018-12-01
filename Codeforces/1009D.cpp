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
std::vector<int> v[L];
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
	 	int n,m;
	 	cin>>n>>m;
	 	FOR(i,1,n)v[i].pb(i+1);
	 	// v[n].pb(1);
	 	m-=(n-1);
	 	if(m<0){cout<<"Impossible";return 0;}
	 	if(m==0)
	 	{
	 		cout<<"Possible\n";
	 		FOR(i,1,n+1)
	 		{
	 			trace(v[i],x)
	 			{
	 				cout<<i<<" "<<x<<ln;
	 			}
	 		}
	 		return 0;
	 	}
	 	// cout<<m<<ln;
	 	FOR(i,3,n+1)
	 	{
	 		if(m==0)break;
	 		v[1].pb(i);
	 		// cout<<i<<" - "<<m<<ln;
	 		m--;
	 	}
	 	// cout<<m<<ln;
	 	FOR(i,2,n+1)
	 	{
	 		if(!m)break;
	 		FOR(j,i+2,n+1)
	 		{
	 			if(!m)break;
	 			if(__gcd(i,j)==1)
	 			{
	 				v[i].pb(j);
	 				m--;
	 			}
	 		}
	 	}
	 	if(m>0){cout<<"Impossible";}
	 	else
	 	{
	 		cout<<"Possible\n";
	 		FOR(i,1,n+1)
	 		{
	 			trace(v[i],x)cout<<i<<" "<<x<<ln;
	 		}
	 	}
		return 0;
}