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
ll baseArray[L],size_of_base, counter[L],aa[L], arr[L], cost[L],done[L],sofar[L][202],co[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int operations, idx, value, l, r;
	cin>>size_of_base;
	for (int i = 1; i <= size_of_base; ++i)
		cin >> arr[i];
	FOR(i,1,size_of_base+1)cin>>cost[i];
	FOR(i,1,size_of_base+1)
	{
		counter[arr[i]]++;
		baseArray[arr[i]] += cost[i];
	}
	FOR(i,1,100001)baseArray[i]+=baseArray[i-1];
	ll ans=INT_MAX;
	std::vector<pii> v;
	ll tmp;
	FOR(i,1,size_of_base+1)v.pb( mp(arr[i],cost[i]));
	sort(all(v));
	FOR(i,0,sz(v))
	{
		if(done[v[i].F])
		{
			co[i]=INT_MAX;
			continue;
		}
		done[v[i].F]=1;
		co[i]=max(0LL,i-counter[v[i].F]+1);
	}
	FOR(i,0,sz(v))sofar[i][v[i].S]++;
	FOR(i,1,sz(v))
	{
		FOR(j,1,201)
			sofar[i][j]+=sofar[i-1][j];
	}
	FOR(i,0,sz(v))sofar[i][v[i].S]--;
	FOR(i,1,201)
	{
		FOR(j,0,sz(v))
		{
			tmp=min(co[j],sofar[j][i]);
			co[j]-=tmp;
			sofar[j][i]-=tmp;
			aa[j]+=i*tmp;
		}
	}
	FOR(i,0,sz(v))
	{
		if(co[i]>0)continue;
		aa[i]+=baseArray[100000]-baseArray[v[i].F];
		ans=min(aa[i],ans);		
	}
	cout<<ans<<ln;
	return 0;
}