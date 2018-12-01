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
ll a[L],ans=INT_MIN;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n)cin>>a[i];
		ll tmp,l=0,r=1,f=0;
		while(r<n)
		{
			if(a[r]>a[r-1])r++;
			else if(f==0)
			{
				f=1;
				tmp=r;
				ans=max(ans,r-l);
				r++;
			}
			else
			{
				f=1;
				ans=max(ans,r-l);
				// cout<<tmp<<ln;
				l=tmp;
				tmp=r;
				r++;
			}
			// debug3(l,r,f);
		}
		// debug2(l,r);
		// if(f==0)
		ans=max(ans,r-l);
		cout<<ans;
		return 0;
}