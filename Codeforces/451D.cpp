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
int evea,odda,eveb,oddb;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	ll ane=0,ano=0;
	 	cin>>s;
	 	int len=s.length();
	 	FOR(i,0,len)
	 	{
	 		if(i%2)
	 		{
	 			if(s[i]=='a')
	 			{
	 				odda++;
	 				ane+=evea;
	 				ano+=odda;
	 			}
	 			else
	 			{
					oddb++;
					ane+=eveb;
	 				ano+=oddb;
				}

	 		}
	 		else
	 		{
	 			if(s[i]=='a')
	 			{
	 				evea++;
	 				ano+=evea;
	 				ane+=odda;
	 			}
	 			else
	 			{
	 			 	eveb++;
	 			 	ano+=eveb;
	 			 	ane+=oddb;
	 			}
	 		}
	 		// debug3(i,ane,ano);
	 	}
	 	cout<<ane<<" "<<ano<<ln;
		return 0;
}