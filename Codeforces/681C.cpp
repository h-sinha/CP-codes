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
map<char,string> counter;
std::vector< pair <char,int> > v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		counter['i'] = "insert";
		counter['g'] = "getMin";
		counter['r'] = "removeMin";
		int n, m;
		string type;
		cin >> n;
		multiset<int>SET;
		FOR(i,0,n)
		{
			cin >> type;
			if(type[0] != 'r')cin>>m;
			if(type[0] == 'i')
			{
				v.pb(mp('i',m));
				SET.insert(m);
			}
			else if(type[0] == 'g')
			{
				if(SET.empty())
				{
					SET.insert(m);
					v.pb(mp('i',m));
					v.pb(mp('g',m));
				}
				else if(*SET.begin() != m)
				{
					while(sz(SET) && *SET.begin()<m)
					{
						v.pb(mp('r',0));
						SET.erase(SET.begin());
					}
					if(SET.empty() || *SET.begin() != m)
					{
						SET.insert(m);
						v.pb(mp('i',m));
					}
					v.pb(mp('g',m));
				}
				else v.pb(mp('g',m));
			}
			else
			{
				if(SET.empty())
					v.pb(mp('i',1));
				else 
					SET.erase(SET.begin());
			 	v.pb(mp('r',0));
			}

		}
		cout<<sz(v)<<ln;
		trace(v,x)
		{
			if(x.F != 'r')cout<<counter[x.F]<<" "<<x.S<<ln;
			else cout<<counter[x.F]<<ln;
		}
		return 0;
}	}
		return 0;
}