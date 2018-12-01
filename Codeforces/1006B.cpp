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
int mark[L],counter[L];
std::vector<ll> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a[L],n,k,prev;
	 	cin>>n>>k;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		v.pb(a[i]);
	 	}
	 	sort(v.rbegin(), v.rend());
	 	ll aa=0;
	 	FOR(i,0,k){counter[v[i]]++;aa+=v[i];}
	 	FOR(i,0,n)
	 	{
	 		if(counter[a[i]])
	 		{
	 			counter[a[i]]--;
	 			mark[i]++;
	 		}
	 	}
	 	int co=k;
	 	prev=-1;
	 	cout<<aa<<ln;
	 	FOR(i,0,n)
	 	{
	 		if(!mark[i])continue;
	 		if(co>1)
	 		{
	 			cout<<i-prev<<" ";
	 			prev=i;
	 		}
	 		else
	 		{
	 			cout<<n-1-prev;
	 			return 0;
	 		}
	 		co--;
	 	}
		return 0;
}