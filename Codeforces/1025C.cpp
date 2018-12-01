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
	 	string s;
	 	cin >> s;
	 	s += s;
	 	int len=s.length(), ans=INT_MIN, sofar=1;
	 	sofar = 1;
	 	FOR(i,1,len)
	 	{
	 		if(s[i] != s[i-1])sofar++;
	 		else
	 		{
	 			ans=max(ans,sofar);
	 			sofar=1;
	 		}
	 	}
	 	cout<<min(len/2,max(ans,sofar));
		return 0;
}