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
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int co[2];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int len,ans=INT_MIN,tmp;
	 	string s;
	 	cin>>len;
	 	cin>>s;
	 	counter[0]=-1;
	 	FOR(i,0,len)
	 	{
	 		if(s[i]=='0')co[0]++;
	 		else co[1]++;
	 		tmp=co[0]-co[1];
	 		if(counter.find(tmp)==counter.end())counter[tmp]=i;
	 		else ans=max(ans,i-counter[tmp]);
	 		// debug2(i,tmp);
	 	}
	 	if(ans!=INT_MIN)
	 		cout<<ans;
		else cout<<"0";
		return 0;
}