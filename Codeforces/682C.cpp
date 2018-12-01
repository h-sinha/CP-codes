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
ll a[L], siz[L], ans=0;
std::vector<pii> v[L];
void dfs(int vertex, int parent, int mxsofar)
{
	ll tmp;	
	// debug2(vertex,mxsofar);
	trace(v[vertex],x)
	{
		if(x.F!=parent)
		{
			tmp = max(mxsofar+x.S,x.S);
			if(tmp > a[x.F])
			{
				// cout<<x.F<<ln;
				ans += siz[x.F];
			}
			else dfs(x.F,vertex,tmp);

		}
	}
	return;
}
ll fix(int vertex,int parent)
{
	siz[vertex] = 1;
	trace(v[vertex],x)
		if(x.F!=parent)
			siz[vertex] += fix(x.F,vertex);
	return siz[vertex];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll aa,bb,n;
	 	cin >> n;
	 	FOR(i,1,n+1)cin >>a[i];
		FOR(i,2,n+1)
		{
			cin >> aa >> bb;
			v[aa].pb(mp(i,bb));
			v[i].pb(mp(aa,bb));
		}
		// trace(v[1],x)cout<<x.F<<" - ";
		// cout<<ln;
		fix(1,-1);
		dfs(1,-1,0);
		cout<<ans;
		return 0;
}