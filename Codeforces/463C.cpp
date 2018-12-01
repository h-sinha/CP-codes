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
map<ll,ll> counter;
ll a[2002][2002],lefty[2002][2002],sumis;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,1,n+1)
	 	{
	 		FOR(j,1,n+1)
	 		{
	 			cin>>a[i][j];
	 			counter[i+j]+=a[i][j];
	 		}
	 	}
	  	priority_queue < pair < ll, pair<int,int> > > odd;
	  	priority_queue < pair<ll, pair<int,int> > > even;
	 	FOR(k,1,n+1)
	 	{
	 		sumis=0;
	 		int i=k,j=1;
	 		while(i<=n && j<=n)
	 		{
	 			sumis+=a[i][j];
	 			++i;
	 			++j;
	 		}
	 		i=k,j=1;
	 		while(i<=n && j<=n)
	 		{
	 			lefty[i][j]=sumis;
	 			++i;
	 			++j;
	 		}
	 	}
	 	FOR(k,2,n+1)
	 	{
	 		sumis=0;
	 		int i=1,j=k;
	 		while(i<=n && j<=n)
	 		{
	 			sumis+=a[i][j];
	 			++i;
	 			++j;
	 		}
	 		i=1,j=k;
	 		while(i<=n && j<=n)
	 		{
	 			lefty[i][j]=sumis;
	 			++i;
	 			++j;
	 		}
	 	}
	 	ll cur=0;
	 	FOR(i,1,n+1)
	 	{
	 		FOR(j,1,n+1)
	 		{
	 			cur=lefty[i][j]+counter[i+j]-a[i][j];
	 			if((i+j)&1)odd.push({ cur,{i,j} });
	 			else even.push({ cur,{i,j} });
	 		}
	 	}
	 	auto a1=odd.top();
	 	auto a2=even.top();
	 	cout<<a1.F+a2.F<<ln;
	 	cout<<a1.S.F<<" "<<a1.S.S<<" "<<a2.S.F<<" "<<a2.S.S<<ln;
		return 0;
}