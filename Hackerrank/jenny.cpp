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
int n,r,a,b,cur,mark[5002];
vector< vector< vector<int> > > ans;
std::vector<int> v[5002];
std::vector<int> adj[5002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
void dfs(int vertex,int parent,int sofar)
{
	if(sofar==r){adj[vertex].pb(parent);return;}
	else{ 
        for(auto &x:v[vertex])
        	adj[vertex].pb(x);
	}
	for(auto &x:v[vertex])
	{
		if(x==parent)continue;
		dfs(x,vertex,sofar+1);
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>r;
	 	int f=0,f1,answer=0;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}

	 	FOR(i,1,n+1)
    	{
    		FOR(j,1,n+1)adj[j].clear();
    		dfs(i,0,0);
        	vector< vector<int> > h;
        	FOR(j,1,n+1)
        	{
            	if(!adj[j].size()) continue;
            	vector<int> g;
            	for(auto &x:adj[j])g.pb( adj[x].size() );
            	h.pb( g );
        	}
        	sort(h.begin(), h.end() );
        	ans.pb( h );
    	}
    sort(ans.begin(), ans.end());
    ans.erase( unique(ans.begin(), ans.end()), ans.end() );
    cout << ans.size() << endl;
		return 0;
}