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
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,x,y,cnt=0,flag=1;
	 	string s;
	 	cin>>n>>x>>y;
	 	cin>>s;
		FOR(i,0,n)
		{
			if(s[i]=='0')
			{
				if(flag)cnt++;
				flag=0;
			}
			else flag=1;
		}	 	
		if(cnt==0)cout<<"0";
		else cout<<min((cnt-1)*x+y,cnt*y);
		return 0;
}