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
map<ll,ll> mark;
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n)cin>>a[i];
	 	ll sofar=0;
	 	FOR(i,0,n)
	 	{
	 		sofar+=a[i];
	 		counter[sofar]++;
	 		if(mark[sofar]==0)mark[sofar]=INT_MAX;
	 		mark[sofar]=min(mark[sofar],ll(i));
	 	}
	 	mark[a[0]]=0;
	 	sofar=0;
	 	ll ans=0;
	 	RFOR(i,n-1,0)
	 	{
	 		sofar+=a[i];
	 		if(counter.find(sofar)!=counter.end())
	 		{
	 			// if(mark.find(sofar)==mark.end())
	 			// cout<<i<<" "<<sofar<<" "<<mark[sofar]<<ln;
	 			if(mark[sofar]<i && sofar>ans)
	 				ans=sofar;

	 		}
	 	}
	 	cout<<ans;
		return 0;
}