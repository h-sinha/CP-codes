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
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
map<ll,ll> counter;
ll a[1000002],x,y,mark1[1000002],mark2[1000002];
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
	 	string s;
	 	cin>>s;
	 	cin>>x>>y;
	 	int len=s.length();
	 	FOR(i,0,len)a[i]=s[i]-'0';
		ll cur=0;
		FOR(i,0,len)
		{
			cur=(cur*10+a[i])%x;
			if(cur==0)mark1[i]=1;
		}
		int co=0;
		cur=0;
		RFOR(i,len-1,0)
		{
			cur = (a[i]*fastexpo(10,co,y) +cur%y)%y;
			if(cur==0)mark2[i]=1;
			co++;
		}
		co=-1;
		FOR(i,0,len-1)
		{
			if(mark1[i] && mark2[i+1] && a[i+1]!=0)
			{
				co=i;break;
			}
		}
		if(co==-1)cout<<"NO";
		else
		{
			cout<<"YES\n";
			FOR(i,0,co+1)cout<<a[i];
			cout<<ln;
			FOR(i,co+1,len)cout<<a[i];
		}
		return 0;
}