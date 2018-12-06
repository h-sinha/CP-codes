#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
std::vector<pii> v[10002];
ll timeis[10002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll t,a,b,c,n,k,m;
	 	cin>>n>>k>>m;
	 	FOR(i,0,m)
	 	{
	 		cin>>a>>b>>t;
	 		v[a].pb(mp(b,t));
	 		v[b].pb(mp(a,t));
	 	}
	 	FOR(i,0,n+1)timeis[i]=LLONG_MAX;
	 	revpr q;
	 	// queue<pii>q;
	 	ll curtime;
	 	timeis[1]=0;
	 	q.push({0,1});
	 	pii head;
	 	while(sz(q))
	 	{
	 		head=q.front();
	 		q.pop();
	 		if( (timeis[head.S]/k)&1 )
	 		{
	 			curtime=((timeis[head.S]/k)+1)*k;
	 			// cout<<head.S;
	 			// curtime=((timeis[head.S]+2*k-1)/k)*k;
	 			// cout<<curtime<<ln;
	 		}
	 		else curtime=timeis[head.S];
	 		trace(v[head.S],x)
	 		{
	 			if(curtime+x.S<timeis[x.F])
	 			{
	 				timeis[x.F]=curtime+x.S;
	 				q.push({timeis[x.F],x.F});
	 			}
	 		}
	 		// if(timeis[n]!=LLONG_MAX)break;
	 	}
	 	// FOR(i,0,n+1)debug2(i,timeis[i]);
	 	cout<<timeis[n]<<ln;
		return 0;
}