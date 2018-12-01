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
int co1[2],co2[2];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string a,b;
	 	cin>>a>>b;
	 	string tt=a;
	 	int len1=a.length(),len2=b.length(),f=0;
	 	if(len1!=len2){cout<<"NO\n";return 0;}
	 	FOR(i,0,len1)
	 	{
	 		co1[a[i]-'0']++;
	 		co2[b[i]-'0']++;
	 	}
	 	if(co1[0]==len1)
	 	{
	 		if(co2[0]==len1)
	 			cout<<"YES";
	 		else cout<<"NO";
	 	}
	 	else if(co2[0]==len1)
	 	{
	 		if(co1[0]==len1)
	 			cout<<"YES";
	 		else cout<<"NO";
	 	}
	 	else cout<<"YES";
		return 0;
}