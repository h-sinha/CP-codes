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
std::vector<ll> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,d,ans=0,tmp,a;
	 	cin>>n>>d;
	 	std::vector<ll> ::iterator it;
	 	FOR(i,0,n){cin>>a;v.pb(a);}
		FOR(i,0,n)
		{
			it=lower_bound(all(v),v[i]+d);
			if(*it>v[i]+d)it--;
			if(it!=v.end())
			{
				tmp=it-v.begin()-i;
				ans+=(tmp*(tmp-1))/2;
				// debug2(i,tmp);
			}
			else
			{
				it--;
				tmp=it-v.begin()-i;
				if(tmp>1)
				{
					ans+=(tmp*(tmp-1))/2;
				}
				// debug2(i,tmp);
			}
		}
		cout<<ans;
		return 0;
}