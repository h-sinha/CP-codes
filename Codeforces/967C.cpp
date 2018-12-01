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
ll stair[L],elevator[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,cs,ce,v,st,et,cur,x1,x2,y1,y2,q;
	 	cin>>n>>m>>cs>>ce>>v;
	 	FOR(i,0,cs)cin>>stair[i];
	 	FOR(i,0,ce)cin>>elevator[i];
		cin>>q;
		while(q--)
		{
			ll ans=LLONG_MAX;
			cin>>x1>>y1>>x2>>y2;
			if(x1==x2)
				ans=abs(y1-y2);
			cur = lower_bound(stair,stair+cs,y1)-stair;
			if(cur<cs && cs!=0)
				ans = min(ans, abs(y1-stair[cur])+abs(y2-stair[cur])+abs(x1-x2) );
			if(cur>0 && cs!=0)
				ans = min(ans, abs(y1-stair[cur-1])+abs(y2-stair[cur-1])+abs(x1-x2) );
			cur = lower_bound(elevator,elevator+ce,y1)-elevator;
			if(cur<ce && ce!=0)
				ans = min(ans, abs(y1-elevator[cur])+abs(y2-elevator[cur])+(abs(x1-x2)+v-1)/v );
			if(cur>0 && ce!=0)
				ans = min(ans, abs(y1-elevator[cur-1])+abs(y2-elevator[cur-1])+(abs(x1-x2)+v-1)/v );
			cout<<ans<<ln;
		}
		return 0;
}