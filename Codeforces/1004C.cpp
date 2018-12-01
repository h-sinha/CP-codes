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
std::map<ll, ll> mark;
ll ans=0;
ll a[L];
set<ll>SET;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n){cin>>a[i];SET.insert(a[i]);counter[a[i]]++;}
		FOR(i,0,n)
		{
			if(mark[a[i]])
			{
				counter[a[i]]--;
				if(counter[a[i]]==0)SET.erase(a[i]);
				continue;
			}
			counter[a[i]]--;
			if(counter[a[i]]==0)SET.erase(a[i]);
			// debug2(i,sz(SET));
			ans+=sz(SET);
			mark[a[i]]=1;
		}
		cout<<ans;
		return 0;
}