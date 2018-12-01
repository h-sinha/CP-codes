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
int co[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string a,b;
	 	int n;
	 	cin>>n;
	 	cin>>a>>b;
	 	ll ans=0;
	 	set<char>SET;
	 	FOR(i,0,n/2)
	 	{
	 		SET.clear();
	 		SET.insert(a[i]);
	 		SET.insert(b[i]);
	 		SET.insert(a[n-i-1]);
	 		SET.insert(b[n-i-1]);
	 		// cout<<i<<" - "<<sz(SET)<<ln;
	 		if(sz(SET)==1)
	 			continue;
	 		else if(sz(SET)==2)
	 		{
	 			co[a[i]]++;
	 			co[b[i]]++;
	 			co[a[n-i-1]]++;
	 			co[b[n-i-1]]++;
	 			if(co[a[i]]==3 || co[a[n-i-1]]==3 ||co[b[i]]==3 ||co[b[n-i-1]]==3)ans++;
	 			co[a[i]]=0;
	 			co[b[i]]=0;
	 			co[a[n-i-1]]=0;
	 			co[b[n-i-1]]=0;
	 		}
	 		else if(sz(SET)==4)
	 		{
	 			ans+=2;
	 		}
	 		else if(sz(SET)==3)
	 		{
	 			if(a[i]==a[n-i-1])ans+=2;
	 			else ans+=1;
	 		}
	 		// cout<<i<<" "<<ans<<ln;
	 	}
	 	if(n%2)
	 	{
	 		if(a[n/2]!=b[n/2])ans++;
	 	}
	 	cout<<ans;
		return 0;
}