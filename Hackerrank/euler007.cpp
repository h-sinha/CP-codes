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
std::vector<int> ans;
bool prime[1500000];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t,n;
	 	prime[0] = prime[1] =1;
	 	FOR(i,2,120000)
	 	{
	 		if(prime[i])continue;
	 		ans.pb(i);
	 		for (int j = i*2; j<=1100000 ; j+=i)
	 			prime[j] = 1;
	 	}
	 	cin>>t;
	 	while(t--)
	 	{
	 		cin>>n;
	 		cout<<ans[n-1]<<ln;
	 	}
		return 0;
}