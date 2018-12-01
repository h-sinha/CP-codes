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
	 	int n,m;
	 	cin>>n>>m;
	 	if(n-m>1 || ((m+1)/2)>n+1){cout<<"-1";return 0;}
	 	while(m>0 && m-1>n)
	 	{
	 		if(n>0)
	 		cout<<"110";
	 		else cout<<"11";
	 		n--;m-=2;
	 	}
	 	int cur;
	 	if(n>m)cur=0;
	 	else  cur=1;
	 	while(n>0 || m>0)
	 	{
	 		if(cur&1){cout<<"1";m--;}
	 		else if (n>0) {cout<<"0";n--;}
	 		cur++;
	 	}
		return 0;
}