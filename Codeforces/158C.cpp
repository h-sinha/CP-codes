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
map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	std::vector< string > v;
	 	int n, len, prev;
	 	string cur, com;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> com;
	 		if(com[0] == 'p')
	 		{
	 			cout<<"/";
	 			trace(v,x)
	 				cout<<x<<"/";
	 			cout<<ln;
	 		}
	 		else
	 		{
	 			cin >> cur;
	 			if(cur[0] == '/')
	 			{
	 				v.clear();
	 				prev = 0;
	 				len = cur.length();
	 				FOR(j,1,len)
	 				{
	 					if(cur[j] == '/')
	 					{
	 						if(cur[j-1] == '.')
	 						{
	 							v.pop_back();
	 							prev = j;
	 						}
	 						else
	 						{
	 							v.pb(cur.substr(prev+1,j-prev-1));
	 							prev = j;
	 						}
	 					}
	 					else if (j == len-1)
	 					{
	 						if(cur[j] == '.')
	 							v.pop_back();
	 						else
	 						{
	 							v.pb(cur.substr(prev+1,j-prev));
	 							prev = j;
	 						}
	 					}	
	 				}
	 			}
	 			else
	 			{
	 				prev = -1;
	 				len = cur.length();
	 				FOR(j,0,len)
	 				{
	 					if(cur[j] == '/')
	 					{
	 						if(cur[j-1] == '.')
	 						{
	 							v.pop_back();
	 							prev = j;
	 						}
	 						else 
	 						{
	 							v.pb(cur.substr(prev+1,j-prev-1));
	 							prev = j;
	 						}
	 					}
	 					else if(j == len-1)
	 					{
	 						if(cur[j] == '.')v.pop_back();
	 						else 
	 						{
	 							v.pb(cur.substr(prev+1,j-prev));
	 							prev = j;
	 						}
	 					}
	 				}
	 			}
	 		}
	 	}
		return 0;
}