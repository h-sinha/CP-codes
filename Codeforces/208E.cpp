#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<"-->"<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int parent[100002][22];
std::vector<int> ans;
std::vector<int> aux;
std::vector<int> v[100002];
std::vector<int> child[100002][22];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int m,a,b,n,r;
	 	cin>>n;
	 	FOR(i,0,n+1)FOR(j,0,19)parent[i][j]=-1;
	 	FOR(i,1,n+1)
	 	{
	 		cin>>r;
	 		parent[i][0]=r;
	 		if(r==0){parent[i][0]=-1;continue;}
	 		child[r][0].pb(i);
	 	}
	 	FOR(j,1,19)
	 	{
	 		FOR(i,1,n+1)
	 		{
	 			if(parent[i][j-1]!=-1)
	 			{
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
	 				// debug3(i,j,parent[i][j]);
	 				if(parent[i][j]!=-1)
	 				{
	 					child[parent[i][j]][j].pb(i);
	 					// debug3(parent[i][j],j,i);
	 				}
	 			}
	 		}
	 	}
	 	int temp;
	 	cin>>m;
	 	while(m--)
	 	{
	 		cin>>a>>b;
	 		temp=b;
	 		FOR(i,0,19)
	 		{
	 			if(temp&1)a=parent[a][i];
	 			if(a==-1)break;
	 			temp>>=1;
	 		}
	 		if(a==-1){cout<<"0 ";continue;}
	 		ans.pb(a);
	 		FOR(i,0,19)
	 		{
	 			if(b&1)
	 			{
	 				for(auto &x:ans)
	 				{
	 					if(x==-1)continue;
	 					for(auto &y:child[x][i])
	 					{	
	 						if(y==x)continue;
	 						aux.pb(y);
	 					}

	 				}
	 				ans.clear();
	 					for(auto &x:aux)ans.pb(x);
	 						aux.clear();
	 			}
	 			b>>=1;
	 		}
	 		cout<<max(ll(0),sz(ans)-1)<<" ";
	 		ans.clear();
	 	}

		return 0;

}