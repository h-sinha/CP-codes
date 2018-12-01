#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<__float128,int>
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
std::map<ll, ll> counter;
set<pii>SET;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		string s;
		cin>>s;
		int len=s.length();
		ll tmp,left=0,right=1e18;	
		FOR(i,0,len)
		{
			if(s[i]=='r')counter[i+1]=left++;
			else counter[i+1]=right--;			
		}
		trace(counter,x)SET.insert(mp(x.S,x.F));
		trace(SET,x)cout<<x.S<<ln;
		return 0;
}