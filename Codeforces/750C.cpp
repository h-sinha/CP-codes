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
const int L=2e5+7;
map<ll,ll> counter;
ll c[L],d[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,0,n)cin >> c[i] >> d[i];
	 	ll l = LLONG_MIN, r= LLONG_MAX,cur = 0;
	 	RFOR(i,n-1,0)
	 	{
	 		cur += c[i];
	 		if(d[i] == 1)
	 		{
	 			if(1900+cur > l)l = 1900+cur;
	 		}
	 		else
	 		{
	 			if(1899+cur < r)r = 1899+cur;
	 		}
	 	}
	 	if(l>r)cout<<"Impossible";
	 	else if (r == LLONG_MAX)cout<<"Infinity";
	 	else cout<<r;
		return 0;
}