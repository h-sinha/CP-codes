#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
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
std::vector<pii> v;
std::vector<pii> v1;
set<int> ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,m,a,b;
		cin>>n>>m;
		FOR(i,0,n)
		{
			cin>>a>>b;
			v.pb(mp(min(a,b),max(a,b)));
		}
		FOR(i,0,m)
		{
			cin>>a>>b;
			v1.pb(mp(min(a,b),max(a,b)));
		}
		int co=0;
		trace(v,x)
		{
			co=0;
			trace(v1,y)
			{
				if(x.F==y.F && x.S==y.S)continue;
				if(x.F==y.F && x.S!=y.S)ans.insert(x.F);
				else if(x.F==y.S && x.S!=y.F)ans.insert(x.F);
				else if(x.S==y.F && x.F!=y.S)ans.insert(x.S);
				else if(x.S==y.S && x.F!=y.F)ans.insert(x.S);
				else continue;
			}
		}	
		if(sz(ans)==1){cout<<*ans.begin();return 0;}
		ans.clear();
		trace(v1,x)
		{
			// co=0;
			trace(v,y)
			{
				// cout<<x.F<<" "<<y.F<<" "<<x.S<<" "<<y.S<<ln;
				if(x.F==y.F && x.S==y.S)continue;
				if(x.F==y.F && x.S!=y.S)ans.insert(x.F);
				else if(x.F==y.S && x.S!=y.F)ans.insert(x.F);
				else if(x.S==y.F && x.F!=y.S)ans.insert(x.S);
				else if(x.S==y.S && x.F!=y.F)ans.insert(x.S);
				else continue;
			}
		}	
		if(sz(ans)==1){cout<<*ans.begin();return 0;}
		int t1,t2,co1,co2;
		trace(v,x)
		{
			t1=x.F,t2=x.S,co1=0,co2=0;
			trace(v1,y)
			{
				if(y.F==t1 && y.S!=t2)co1++;
				if(y.S==t1 && y.F!=t2)co1++;
				if(y.F==t2 && y.S!=t1)co2++;
				if(y.S==t2 && y.F!=t1)co2++;
			}
			if(co1 && co2){cout<<"-1";return 0;}
		}
		trace(v1,x)
		{
			t1=x.F,t2=x.S,co1=0,co2=0;
			trace(v,y)
			{
				if(y.F==t1 && y.S!=t2)co1++;
				if(y.S==t1 && y.F!=t2)co1++;
				if(y.F==t2 && y.S!=t1)co2++;
				if(y.S==t2 && y.F!=t1)co2++;
			}
			if(co1 && co2){cout<<"-1";return 0;}
		}
		cout<<"0";
		return 0;
}