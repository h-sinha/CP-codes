#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define sz(a)	int(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define aint(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
// typedef long long int;
int x=1e7+10;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
int countnum[10000010],countdeno[10000010],smaint[10000010],a[100010],b[100010];
void pre()
{
	for(int i=2;i<x;++i)
	{
		if(smaint[i]==0)
		{
			for (int j = i; j < x; j+=i)
			{
				smaint[j]=i;
			}
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int ans,cur,t,tmp,n,m;
	 	cin>>n>>m;
	 	FOR(i,0,n)cin>>a[i];
	 	FOR(i,0,m)cin>>b[i];
	 	pre();
	 	FOR(i,0,n)
	 	{
	 		t=a[i];
	 		while(t>1)
	 		{
	 			cur=smaint[t];
	 			countnum[cur]++;
	 			t/=smaint[cur];
	 		}
	 	}
	 	FOR(i,0,m)
	 	{
	 		t=b[i];
	 		while(t>1)
	 		{
	 			cur=smaint[t];
	 			countdeno[cur]++;
	 			t/=cur;
	 		}
	 	}
	 	ans=1,cur=0;
	 	cout<<n<<" "<<m<<ln;
	 	FOR(i,0,n)
	 	{
	 		 ans=1;
	 		while(a[i]>1)
	 		{
	 			cur=smaint[a[i]];
	 			if(countdeno[cur])countdeno[cur]--;
	 			else ans*=cur;
	 			a[i]/=cur;
	 		}
	 		cout<<ans<<" ";
	 	}
	 	cout<<ln;
	 	FOR(i,0,m)
	 	{
	 		 ans=1;
	 		while(b[i]>1)
	 		{
	 			cur=smaint[b[i]];
	 			if(countnum[cur])countnum[cur]--;
	 			else ans*=cur;
	 			b[i]/=cur;
	 		}
	 		cout<<ans<<" ";
	 	}
	 	// FOR(i,0,10)cout<<i<<" - "<<smaint[i]<<" "<<ln;
	 	// cout<<ln;
		return 0;
}