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
int main()
{
		// ios_base::sync_with_stdio(false);
	 	// cin.tie(NULL);
		int ans=0;
		int k=0;
		string s;
		int co=0;
		while(cin>>s)
		{	
			co=0;
			int len=s.length();
			FOR(i,0,len)
			{
				if(s[i]>=65 && s[i]<=90)co++;
			}
				ans=max(ans,co);

		}
		cout<<ans;
		return 0;
}