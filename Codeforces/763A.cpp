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
int col[L],current,color;
std::vector<int> v[L];
bool dfs(int vertex,int parent)
{
	if(col[vertex]!=color)return 0;
	bool ans=1;
	trace(v[vertex],x)
		if(x!=parent)
			ans=ans&dfs(x,vertex);
	return ans;
}
bool solve(int vertex)
{
	trace(v[vertex],x)
	{
		color=col[x];
		if(!dfs(x,vertex))return 0;
	}
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,a,b;
	 	cin>>n;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	FOR(i,1,n+1)
	 		cin>>col[i];
	 	int ff=-1,ss=-1;
	 	FOR(i,1,n+1)
	 	{	
	 		trace(v[i],x)
	 		{
	 			if(col[i]!=col[x])
	 			{
	 				ff=i,ss=x;
	 				break;
	 			}
	 		}
	 	}
	 	if(ff==-1)
	 	{
	 		cout<<"YES\n1";
	 		return 0;
	 	}
	 	if(solve(ff))
	 	{
	 		cout<<"YES\n"<<ff;
	 		return 0;
	 	}
	 	if(solve(ss))
	 	{
	 		cout<<"YES\n"<<ss;
	 		return 0;
	 	}
	 	cout<<"NO";
		return 0;
}