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
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
const int L=2e5+7;
ld arr[L],lazy[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll a,type,q;
		cin>>q;
		int cur=1;
		ld x,sumis=0,k;
		while(q--)
		{
			cin>>type;
			if(type==1)
			{
				cin>>a>>x;
				lazy[a]+=x;
				sumis+=(a*x);
			}
			else if(type==2)
			{
				cin>>k;
				arr[++cur]=k;
				sumis+=k;
			}
			else
			{
				lazy[cur-1]+=lazy[cur];
				sumis-=(arr[cur]+lazy[cur]);
				lazy[cur]=0;
				--cur;
			}
			printf("%.10Lf\n",sumis/(cur));
		}
		return 0;
}