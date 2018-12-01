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
char ch[L];
set<int>SET[26];
int mark[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int p,k,n,cur=0;
	 	char c;
	 	string s;
	 	cin>>k;
	 	cin>>s;
	 	int len=s.length();
	 	FOR(i,0,k)
	 	{
	 		FOR(j,0,len)
	 		{
		 		ch[cur++]=s[j];
	 			SET[s[j]-'a'].insert(cur-1);
	 		}
	 	}
	 	cin>>n;
	 	set<int>::iterator it;
	 	while(n--)
	 	{
	 		cin>>p>>c;
	 		tmp=*std::advance(it,p-1);
	 	}
		return 0;
}