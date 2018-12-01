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
std::vector<pii> v[2];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a,n;
	 	cin>>n;
	 	pii tmp;
	 	priority_queue<pii>q;
	 	FOR(i,0,n){cin>>a;q.push(mp(a,i));}
		int cur=0;
		while(sz(q))
		{
			tmp=q.top();
			q.pop();
			v[cur].pb(mp(tmp.F,tmp.S));
			cur=1-cur;
		}
		cout<<sz(v[0])<<ln;
		trace(v[0],x)cout<<x.S+1<<" ";
		cout<<ln;
		cout<<sz(v[1])<<ln;
		trace(v[1],x)cout<<x.S+1<<" ";
		cout<<ln;
		return 0;
}