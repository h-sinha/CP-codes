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
std::vector<ll> a,b;
std::map<ll, int> counter1;
std::map<ll, int> counter2;
ll cumsum1[L],cumsum2[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, m,cur;
	 	ll tt;
	 	cin >>n;
	 	set<ll>SET;
	 	FOR(i,0,n)
	 	{
	 		cin >> tt;
	 		counter1[tt]++;
	 		if(counter1[tt]==1)
	 		a.pb(tt);
	 		SET.insert(tt);
	 	}
	 	cin >> m;
	 	FOR(i,0,m)
	 	{
	 		cin >> tt;
	 		counter2[tt]++;
	 		SET.insert(tt);
	 		if(counter2[tt]==1)
	 		b.pb(tt);
	 	}
	 	sort(all(a));
	 	sort(all(b));
	 	FOR(i,0,sz(a))cumsum1[i]=counter1[a[i]];
	 	FOR(i,0,sz(b))cumsum2[i]=counter2[b[i]];
	 	FOR(i,1,sz(a))cumsum1[i]+=cumsum1[i-1];
	 	FOR(i,1,sz(b))cumsum2[i]+=cumsum2[i-1];
	 	ll ans = -LLONG_MAX,x,y,curx,cury;
	 	std::vector<ll> ::iterator it;
	 	int co1,co2;
	 	x=n*2LL,y=m*2LL;
	 	trace(SET,xx)
	 	{
	 		co1 =upper_bound(all(a),xx) - a.begin();
	 		co2 =upper_bound(all(b),xx) - b.begin();
	 		if(co1 > 0)
	 			curx = cumsum1[co1-1]*2LL + (n-cumsum1[co1-1])*3LL;
			else
	 			curx =  n*3LL;

	 		if(co2>0)
	 			cury = cumsum2[co2-1]*2LL + (m-cumsum2[co2-1])*3LL;
	 		else
	 			cury =  m*3LL;
	 		if(curx - cury > x - y)x=curx,y=cury;
	 		if(curx - cury >= x - y && curx>x)x=curx,y=cury;
	 		// debug3(xx,curx,cury);
	 		// cout<<co1<<" "<<co2<<" "<<cumsum2[co2-1]<<ln;
	 	}
	 	curx=n*3LL,cury=m*3LL;
	 	if(curx - cury > x - y)x=curx,y=cury;
	 		if(curx - cury >= x - y && curx>x)x=curx,y=cury;
	 	cout<<x<<":"<<y<<ln;
		return 0;
}