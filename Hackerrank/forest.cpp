#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
ll cost[50002],parent[50002],answer=INT_MAX,pre[50002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
std::vector<int> v[50002];
std::vector<ll> ans[50002];
ll dfs(int pr,int vertex)
{
	ll query=0,q1=0;
	parent[vertex]=pr;
	for(auto &x:v[vertex])
	{
		if(x==pr)continue;
		q1=dfs(vertex,x);
		query+=q1;
		ans[vertex].pb(q1);
	}
	pre[vertex]=cost[vertex]+query;
	return pre[vertex];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll q,n;
	 	int a,b;
	 	cin>>q;
	 	while(q--)
	 	{
	 		answer=INT_MAX;
	 		cin>>n;
	 		FOR(i,1,n+1)cin>>cost[i];
	 		FOR(i,0,n-1)
	 		{
	 			cin>>a>>b;
	 			v[a].pb(b);
	 			v[b].pb(a);
	 		}
	 		dfs(-1,1);
	 		FOR(i,2,n+1)ans[i].pb(pre[parent[i]]-pre[i]);
	 		// FOR(i,1,n+1)
	 		// {
	 			// cout<<i<<"--->";
	 			// FOR(j,0,sz(ans[i]))
	 			// cout<<ans[i][j]<<" ";
	 			// cout<<endl;
	 		// }
	 		FOR(i,1,n+1)
	 		{
	 			// cout<<i<<"--->"<<sz(ans[i])<<endl;
	 			if(sz(ans[i])==3)
	 			{
	 				// cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
	 				if(ans[i][0]+cost[i]==ans[i][1] && ans[i][2]<=ans[i][1])answer=min(answer,ans[i][1]-ans[i][2]);
	 				if(ans[i][0]+cost[i]==ans[i][2] && ans[i][1]<=ans[i][2])answer=min(answer,ans[i][2]-ans[i][1]);
	 				if(ans[i][0]==ans[i][2]+cost[i] && ans[i][1]<=ans[i][0])answer=min(answer,ans[i][0]-ans[i][1]);
	 				if(ans[i][1]==ans[i][2]+cost[i] && ans[i][0]<=ans[i][1])answer=min(answer,ans[i][1]-ans[i][0]);
	 				if(ans[i][2]==ans[i][1]+cost[i] && ans[i][0]<=ans[i][1])answer=min(answer,ans[i][2]-ans[i][0]);
	 				if(ans[i][0]==ans[i][1]+cost[i] && ans[i][2]<=ans[i][0])answer=min(answer,ans[i][0]-ans[i][2]);
	 			}
	 		}
	 		if(answer==INT_MAX)cout<<"-1"<<ln;
	 		else cout<<answer<<ln;
	 		FOR(i,0,n+1)
	 		{
	 			v[i].clear();
	 			ans[i].clear();
	 		}
	 	}
		return 0;
}