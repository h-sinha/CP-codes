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
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int m=1e6+1,ans=-1;
std::vector<int> v[1000006];
void dfs(int vertex,int parent,int sofar)
{
	for(auto &x:v[vertex])
		if(x!=parent)
			dfs(x,vertex,sofar+1);
	ans=max(ans,sofar);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int root,n,a,b;
		string s1,s2,s3;
		cin>>n;
		hash <string> info;
		FOR(i,0,n)
		{
			cin>>s1>>s2>>s3;
			int len=s1.length();
			FOR(i,0,len)s1[i]=tolower(s1[i]);
			len=s3.length();
			FOR(i,0,len)s3[i]=tolower(s3[i]);
			a=info(s1)%m;
			b=info(s3)%m;
			if(s3=="polycarp")root=b;
			v[a].pb(b);
			v[b].pb(a);
		}
		dfs(root,-1,1);
		cout<<ans;
		return 0;
}