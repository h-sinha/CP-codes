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
int calc1[100002],ans=0;
std::vector<int> v[100002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int dfs(int vertex,int parent)
{
	calc1[vertex]=1;
	int temp;
	for(auto &x:v[vertex])
	{
		if(x!=parent)
		{
			temp=dfs(x,vertex);
			calc1[vertex]+=temp;
		}
	}
	if(calc1[vertex]%2==0)ans++;
	return calc1[vertex];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		ll n,a,b;
	 	cin>>n;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	if(n&1){cout<<"-1";return 0;}
	 	dfs(1,-1);
	 	cout<<ans-1;
}