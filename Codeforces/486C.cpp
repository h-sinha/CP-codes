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
int mark[100002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,p;
	 	string s;
	 	cin>>n>>p;
	 	cin>>s;
	 	--p,--n;
	 	int tmp=n/2,first=-1,last=-1,co=0;
	 	int ans=0;
	 	FOR(i,0,tmp+1)
	 	{
	 		if(s[i]!=s[n-i])
	 		{
	 			if(ans==0)first=i;
	 			last=i;
	 			ans+=min(abs(s[i]-s[n-i]),26-abs(s[i]-s[n-i]));
	 		}
	 	}
	 	p=min(p,n-p);
	 	if(ans!=0)
	 	ans+=last-first+min(abs(p-first),abs(p-last));
	 	cout<<ans;
		return 0;
}out<<ans<<ln;
		return 0;
}