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
std::vector<pii> v;
bool comp(pii x,pii y)
{
	if ((x.S-x.F)==(y.S-y.F))return x.F<y.F;
	return (x.S-x.F)>(y.S-y.F);
}
std::vector<int> s(L);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,l,r;
	 	cin>>n>>m;
	 	FOR(i,0,m)
	 	{
	 		cin>>l>>r;
	 	}

	 	FOR(i,1,n+1)s[i]=1-s[i-1];
		FOR(i,1,n+1)cout<<s[i];
		return 0;
}