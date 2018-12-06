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
std::vector< pair<int,string> > ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t,f=1;;
	 	string s[100];
	 	ll n,k,v;
	 	cin>>t;
	 	while(t--)
	 	{
	 		cin>>n>>k>>v;
	 		FOR(i,0,n)cin>>s[i];
	 		ll tmp=k*(v-1);
	 		tmp%=n;
	 		int cur=tmp;
	 		ans.clear();
	 		while(k>0)
	 		{
	 			if(cur>=n)cur=0;
	 			ans.pb(mp(cur,s[cur]));
	 			cur++;
	 			k--;
	 		}
	 		sort(all(ans));
	 		cout<<"Case #"<<f<<": ";
	 		trace(ans,x)cout<<x.S<<" ";
	 		cout<<ln;
	 		f++;
	 	}
		return 0;
}