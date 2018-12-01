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
bool mark[100002];
std::vector<int> ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,k;
		cin>>n>>k;
		int cur=1,l=2,r=n;
		if(k==1){FOR(i,1,n+1)cout<<i<<" ";return 0;}
		if(k==2){cout<<n<<" 1 ";FOR(i,2,n)cout<<i<<" ";return 0;}
		ans.pb(1);
		mark[1]=1;
		while(k>2)
		{
			if(cur&1)ans.pb(r),mark[r--]=1;
			else ans.pb(l),mark[l++]=1;
			cur++;
			k--;
		}
		trace(ans,x)cout<<x<<" ";
		// cout<<mark[2];
		if(cur&1){RFOR(i,n,1)if(!mark[i])cout<<i<<" ";}
		else {FOR(i,1,n+1)if(!mark[i])cout<<i<<" ";}
		return 0;
}