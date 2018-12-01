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
const int L=1e6+7;
int counter[L],n;
std::vector<int> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a;
	 		v.pb(a);
	 	}
	 	sort(all(v));
	 	int ans=0;
	 	std::vector<int> ::iterator it;
	 	FOR(i,0,n)
	 	{
	 		if(v[i]==1)continue;
	 		for (int j = v[i]*2; j <= v[n-1]+v[i]; j += v[i])
	 		{
	 			it = lower_bound(all(v),j);
	 			if(it == v.begin())break;
	 			it--;
	 			ans = max(ans , *it % v[i]);
	 		}
	 	}
	 	cout<<ans;
		return 0;
}