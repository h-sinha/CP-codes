//better solution
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
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int n,m,k;
std::vector<int> v;
void dfs(int i,int j,int prevj)
{
	if(i>n||i<1||j>m||j<0)return;
	v.pb(i),v.pb(j);
	if(prevj<j)
	{
		if(j==m)dfs(i+1,j,INT_MAX);
		else dfs(i,j+1,j);
	}
	else
	{
		if(j==1)dfs(i+1,j,INT_MIN);
		else dfs(i,j-1,j);	
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>m>>k;
		dfs(1,1,-1);
		int cur=0;
		while(k>1)
		{
			cout<<"2 "<<v[cur]<<" "<<v[cur+1]<<" "<<v[cur+2]<<" "<<v[cur+3]<<ln;
			cur+=4;
			--k;
		}
		cout<<((sz(v)-cur)>>1)<<" ";
		while(cur<sz(v))cout<<v[cur++]<<" ";
		return 0;
}