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
int pre[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,ans,aux,tmp,x,y;
	 	cin>>n;
	 	FOR(i,1,n+1)
	 	{
	 		cin>>x>>y;
	 		tmp=sqrt(x);
	 		ans=0;
	 		FOR(j,1,tmp+1)
	 		{
	 			if(x%j)continue;
	 			if(pre[j] < i-y)ans++;
	 			if(x/j !=j)
	 			{
	 				if(pre[x/j] < i-y)ans++;
	 			}
	 			pre[j] = pre[x/j] = i;
	 		}
	 		cout<<ans<<ln;
	 	}
		return 0;
}