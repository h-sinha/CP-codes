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
int ans[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m ,d, a;
	 	cin >> n >> m >> d;
	 	multiset<pii>MULT;
	 	FOR(i,0,n)
	 	{
	 		cin >> a;
	 		MULT.insert(mp(a,i));
	 	}
	 	int cur = 1;
	 	pii aux;
	 	multiset<pii>::iterator it;
	 	while(sz(MULT))
	 	{
	 		aux = *MULT.begin();
	 		MULT.erase(MULT.begin());
	 		ans[aux.S] = cur;
	 		// cout<<aux.F<<" ";
	 		while(1)
	 		{
	 			// cout<<"aux - "<<aux.F+d<<" - ";
	 			it = MULT.upper_bound(mp(aux.F+d,INT_MAX));
	 			if(it == MULT.end())break;
	 			ans[(*it).S] = cur;
	 			aux.F = (*it).F;
	 			aux.S = (*it).S;
	 			// cout<<(*it).S<<" ";
	 			MULT.erase(it);
	 		}
	 		// cout<<ln;
	 		cur++;
	 	}
	 	cout<<cur-1<<ln;
	 	FOR(i,0,n)cout<<ans[i]<<" ";
		return 0;
}