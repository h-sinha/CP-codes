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
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int first,ans=0,last,n,p;
	 	cin>>n>>p;
	 	string s;
	 	cin>>s;
	 	--p;
	 	int tmp=n/2;
	 	if(p>=tmp)p=n-p-1;
	 	FOR(i,0,tmp)
	 	{
	 		if(s[i]!=s[n-i-1])
	 		{
		 		if(!ans)first=i;
	 			ans+=min( abs(s[i]-s[n-i-1]) , 26-abs(s[i]-s[n-i-1]) );
	 			last=i;
	 		}
	 	}
	 	if(ans)
	 	{
	 		if(p==first || p==last)ans+=last-first;
	 		else if(p>last)ans+=p-first;
	 		else if(p<first)ans+=last-p;
	 		else ans+=last-first+min( abs(p-first), abs(p-last) );
	 	}
	 	cout<<ans<<ln;
		return 0;
}