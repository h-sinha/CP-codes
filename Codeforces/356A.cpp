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
const int L=3e5+7;
map<ll,ll> counter;
int ans[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,l,r,x;
	 	set<int>SET;
	 	cin>>n>>m;
	 	FOR(i,1,n+1)SET.insert(i);
	 	set<int>::iterator it;
	 	std::vector<int> er;
	 	while(m--)
	 	{
	 		cin>>l>>r>>x;
	 		it =SET.lower_bound(l);
	 		while(it!=SET.end())
	 		{
	 			if(*it>r)break;
	 			if(*it !=x)
	 			{
	 				ans[*it]=x;
	 				er.pb(*it);
	 			}
	 			it++;
	 		}
	 		trace(er,x)SET.erase(x);
	 		er.clear();
	 	}
	 	FOR(i,1,n+1)cout<<ans[i]<<" ";
		return 0;
}