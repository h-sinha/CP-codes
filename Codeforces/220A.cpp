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
std::vector<ll> a;
std::vector<ll> b;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll co=0,n,q;
		cin>>n;
		FOR(i,0,n)
		{
			cin>>q;
			a.pb(q);
			b.pb(q);
		}
		sort(all(b));
		std::vector<ll>::iterator it;
		FOR(i,0,sz(a))
		{
			// trace(a,x)cout<<x<<" ";
			// cout<<ln;
			if(a[i]==b[i])continue;
			if(co==1){cout<<"NO";return 0;}
				int f=0;
			FOR(j,i+1,sz(a))
			{
				if(a[j]==b[i] && a[i]==b[j])
				{
					swap(a[i],a[j]);
					co++;
					f=1;
					break;
				}
			}
			if(co>1 || f==0){cout<<"NO";return 0;}
		}
		cout<<"YES\n";
		return 0;
}