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
ll x1[L],x2[L];
std::vector<pii> v;
ll totsum[L],h;
bool check(ll val, int i)
{
	ll sumis = 0,idx;
	std::vector<pii> ::iterator it;
	it = upper_bound(all(v),mp(val,LLONG_MAX));
	idx = it-v.begin();
	if(idx != 0)
	{
		sumis = totsum[idx-1];
	}
	if((*it).S >= val)sumis+=(val - (*it).F);
	else sumis = totsum[idx];
	sumis -= val+1;
	sumis += x1[i];
	sumis -=h;
	if(sumis == 0)return 0;
	if(sumis < 0)return -1;
	if(sumis > 0)return 1;
}
ll ser(int i)
{
	ll l=x1[i],r=1e9,aux,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		aux = check(mid,i);
		if(aux == 0)return mid - x1[i]+1;
		else if(aux==-1)l=mid;
		else r = mid;
	}
	// if(!check(r))r=l;
	return r-x1[i]+1;
}

int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,ans = 0;
	 	cin >> n >> h;
	 	FOR(i,0,n)
	 	{
	 		cin >> x1[i]>>x2[i];
	 		v.pb(mp(x1[i],x2[i]));
	 	}
	 	sort(all(v));
	 	totsum[0]=v[0].S-v[0].F+1;
	 	FOR(i,1,sz(v))
	 	{
	 		totsum[i]=v[i].S-v[i].F+1;
	 		totsum[i] += totsum[i-1];
	 		totsum[i] -= 1;
	 	}
		FOR(i,0,n)
		{
			ans = max(ans,ser(i));
			debug2(i,ser(i));
		}
		cout<<ans;
		return 0;
}