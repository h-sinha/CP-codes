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
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
std::vector<bool> visit(1002);
int co=0,edge=0,comp=0,mark[1002];
std::vector<int> v[1002];
void dfs(int vertex)
{
	if(visit[vertex])return;
	visit[vertex]=1;
	comp++;
	if(mark[vertex])co++;
	edge+=sz(v[vertex]);
	trace(v[vertex],x)
		dfs(x);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int a,n,m,k,ans=0,b,cur=1,cure=0;
		cin>>n>>m>>k;
		std::vector<pii> aux;
		FOR(i,0,k){cin>>a;mark[a]=1;}
		FOR(i,0,m)
		{
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		int f=0;
		FOR(i,1,n+1)
		{
			if(!visit[i])
			{
				co=0,comp=0,edge=0;
				dfs(i);
				// cout<<i<<"-"<<co<<ln;
				// cout<<i<<" comp "<<comp<<" co "<<co<<" edge"<<edge<<ln;
				if(co==0){aux.pb(mp(comp,edge/2));continue;}
				// if(co>1){cout<<"0";return 0;}
				edge>>=1;
				ans+=((comp*(comp-1))/2)-edge;
				if(co==1)
				{
					if(cur<=comp && co==1)
					{
						f=1;
						cur=comp;
						cure=edge;
					}
				}
			}
		}
		ans-=((cur*(cur-1))/2)-cure;
		// int f=0;
		trace(aux,x)
		{
			if(cur==1 && !f)cur=0,f=1;
			cur+=x.F,cure+=x.S;
		}
		ans+=((cur*(cur-1))/2)-cure;
		cout<<ans;
		return 0;
}