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
bool mark[L];
int cap[L],parent[L],child[L],org[L],n,current[L];
std::vector<int> v[L];
int dfs(int i,int val)
{
	if(i>n)return n;
	if(val<=0)return i;
	if(i==n)
	{
		cap[i]=max(0,cap[i]-val);
		return i;
	}
	if(val<cap[i])
	{
		cap[i]-=val;
		return i;
	}
	int tmp=cap[i];
	cap[i]=0;
	child[parent[i]]=child[i];
	parent[child[i]]=parent[i];
	child[i]=dfs(child[i],val-tmp);
	return child[i];


}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int p,x,k,type,m;
	 	cin>>n;
	 	FOR(i,1,n+1){cin>>cap[i];org[i]=cap[i];}
		FOR(i,1,n)
		{
			child[i]=i+1;
			parent[i+1]=i;
		}
		cin>>m;
		while(m--)
		{
			cin>>type;
			if(type==1)
			{
				cin>>p>>x;
				// if(cap[p]==0)
				// 	dfs(child[p],x);
				// else
					dfs(p,x);
			}
			else
			{
				cin>>k;
				cout<<org[k]-cap[k]<<ln;
			}
			// FOR(i,1,n+1)debug3(i,parent[i],child[i]);
		}
		return 0;
}