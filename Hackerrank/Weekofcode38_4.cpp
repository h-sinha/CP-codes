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
set<pii>SET[100002];
ll parent[100002],curi[100002],cur=0,w[100002];
std::vector<int> v[1000002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll par,dist,n,tot=0,weight,type,x,m;
	 	cin>>n;
	 	pii tmp;
	 	FOR(i,1,n+1){cin>>w[i];tot+=w[i];}
	 	cin>>m;
	 	cur=n+1;
	 	FOR(i,2,n+1)
	 	{
	 		parent[i]=i-1;
	 		SET[i].insert(mp(-tot+w[i-1],i-1));
	 	}
	 	parent[1]=n;
	 	SET[1].insert(mp(-tot+w[n],n));
	 	while(m--)
	 	{
	 		cin>>type;
	 		if(type==1)
	 		{
	 			cin>>x>>weight;
	 			tmp=*SET[x].begin();
	 			parent[cur]=tmp.S;
	 			int par=tmp.S;
	 			// tmp=*SET[tmp.S].begin();
	 			SET[par].insert(mp(-weight,cur));
	 			dist=tot-w[par]+weight;
	 			// cout<<dist<<" "<<tot<<" "<<ln;
	 			FOR(i,par+1,n+1)
	 			{
	 				SET[i].insert(mp(-dist,cur));
	 				v[cur].pb(i);
	 				dist-=w[i];
	 				if((*SET[i].begin()).S!=cur)break;
	 			}
	 			FOR(i,1,par)
	 			{
	 				SET[i].insert(mp(-dist,cur));
	 				v[cur].pb(i);
	 				dist-=w[i];
	 				if((*SET[i].begin()).S!=cur)break;
	 			}
	 			cur++;

	 		}
	 		else if(type==2)
	 		{
	 			cin>>x>>weight;
	 			tmp=*SET[x].begin();
	 			parent[cur]=x;
	 			par=x;
	 			// tmp=*SET[x].begin();
	 			SET[par].insert(mp(-weight,cur));
	 			dist=tot-w[par]+weight;
	 			// cout<<dist<<" "<<tot<<" "<<ln;
	 			FOR(i,par+1,n+1)
	 			{
	 				SET[i].insert(mp(-dist,cur));
	 				v[cur].pb(i);
	 				dist-=w[i];
	 				if((*SET[i].begin()).S!=cur)break;
	 			}
	 			FOR(i,1,par)
	 			{
	 				SET[i].insert(mp(-dist,cur));
	 				v[cur].pb(i);
	 				dist-=w[i];
	 				if((*SET[i].begin()).S!=cur)break;
	 			}
	 			cur++;
	 		}
	 		else if(type==3)
	 		{
	 			cin>>x;
	 			tmp=*SET[x].begin();
	 			par=tmp.S;
	 			// FOR(i,1,n+1)
	 			trace(v[par],i)
	 			{
	 				set<pii> ::iterator it;
	 				it=SET[i].begin();
	 				while(it!=SET[i].end())
	 				{
	 					if((*it).S==par)
	 					{
	 						SET[i].erase(it);
	 						break;
	 					}
	 				}
	 			}
	 			// FOR(i,1,n+1)
	 			// {
	 			// 	cout<<i<<"----";
	 			// 	trace(SET[i],x)
	 			// 		cout<<x.F<<" - "<<x.S<<" ";
	 			// 	cout<<ln;
	 			// }
	 		}
	 		else if(type==4)
	 		{
	 			cin>>x;
	 			cout<<-((*SET[x].begin()).F)<<ln;
	 		}
	 	}
		return 0;
}