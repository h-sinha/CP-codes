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
bool prime[1000002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a,n;
	 	cin>>n;	
	 	prime[0]=1,prime[1]=1;
	 	for (int i = 2; i <= 1000; ++i)
	 	{
	 		if(prime[i])continue;
	 		for (int j = i*2; j <= 1000000; j+=i)
	 			prime[j]=1;
	 	}
		FOR(i,0,n)
		{
			cin>>a;
			ld tmp=sqrt(a);
			if(floor(tmp)==ceil(tmp) && !prime[ll(tmp)])cout<<"YES\n";
			else cout<<"NO\n";
		}
		return 0;
}