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
const int L=2e5+7;
map<ll,ll> counter;
set<int>open;
set<int >close;
int mark[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		string s;
		int n,k;
		cin >> n >>k;
		cin >>s;
		FOR(i,0,n)
		{
			if(s[i]=='(')open.insert(i);
			else close.insert(i);
		}
		int co=(n-k)/2;
		FOR(i,0,co)
		{
			// cout<<i<<endl;
			mark[*open.begin()]=1;
			open.erase(open.begin());
			mark[*close.begin()]=1;
			close.erase(close.begin());
		}
		FOR(i,0,n)
		{
			if(!mark[i])cout<<s[i];
		}
		return 0;
}