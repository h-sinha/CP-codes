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
		ll n,h,a,b,k,fa,fb,ta,tb;
		cin >> n >>h >> a >> b >>k;
		while(k--)
		{
			cin >> ta>>fa>>tb>>fb;
			if(ta == tb)
			{
				cout<<abs(fa-fb)<<ln;
			}
			else if(fa >=a && fa<=b)
			{
				cout<<(abs(ta-tb) + abs(fb - fa))<<ln;
			}
			else
			{
				cout<<min(abs(fa-a) + abs(fb-a) + abs(ta-tb)   ,abs(fa-b) + abs(fb-b) + abs(ta-tb) )<<ln;
			}
		}
		return 0;
}