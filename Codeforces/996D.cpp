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
std::vector<int> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,a,ans=0;
		cin>>n;
		FOR(i,0,2*n){cin>>a;v.pb(a);}
		for (int i = 1; i < sz(v); i+=2)
		{
			if(v[i]!=v[i-1])
			{
				// cout<<i;
				FOR(j,i+1,sz(v))
				{
					if(v[j]==v[i-1])
					{
						ans+=j-i;
						v.erase(v.begin()+j);
						v.insert(v.begin()+i,v[i-1]);
						break;
					}
				}
			}
		}
		// trace(v,x)cout<<x<<" ";
		cout<<ans;
		return 0;
}