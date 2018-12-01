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
const int L=1e6+7;
map<ll,int> leftis,rightis;
ll a[L];
int before[L],after[L],size_of_base;
std::vector<int>seg[4*L];
void update(int x,int value)
{
	while(x<=2*n)
	{
		aux[x]+=value;
		x=x+least(x);
	}
	return;
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=aux[x];
		x-=least(x);
	}
	return ret;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,1,n+1)cin>>a[i];
		FOR(i,1,n+1)
		{
			leftis[a[i]]++;
			before[i]=leftis[a[i]];
		}
		RFOR(i,n,1)
		{
			rightis[a[i]]++;
			after[i]=rightis[a[i]];
		}
		size_of_base=n;
		build();
		ll ans=0;
		FOR(i,1,n+1)
		{
			ans+=query(i+1,n,before[i]);
		}
		cout<<ans;
		return 0;
}