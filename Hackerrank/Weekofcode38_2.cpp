#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
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
int n,k;
int a[100002],b[100002],mark[100002],ans=INT_MIN;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>k;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		b[i]=a[i];
	 	}
	 	FOR(i,0,n)
	 	{
	 		if(mark[i])continue;
	 		int cur=0,co=0;
	 		FOR(j,i,n)
	 		{
	 			if(a[j]==a[i]+cur*k)co++,mark[j]=1;
	 			cur++;
	 		}
	 		ans=max(ans,co);
	 		if(co>n/10)break;
	 	}
	 	cout<<n-ans<<ln;
		return 0;
}