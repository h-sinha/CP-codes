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
int n,m,x,y,col[1002][2];
int dp[1002][1002][2];
ll solve(ll cur,ll sofar,ll zero,ll one,ll prev)
{
	if(dp[cur][sofar][prev]!=-1)return dp[cur][sofar][prev];
	if(cur>=m)
	{
		if(sofar==0)dp[cur][sofar][prev] = 0;
		else if(sofar>=x && sofar<=y)
		{
			if(prev==0)
				dp[cur][sofar][prev] = zero;
			else if(prev==1) 
				dp[cur][sofar][prev] = one;
		}
		else dp[cur][sofar][prev] = 1000000; 
	}
	else if(sofar+1<x)
	{
		dp[cur][sofar][prev] =solve(cur+1,sofar+1,zero+col[cur][0],one+col[cur][1],prev);
	}
	else if(sofar+1==y)
	{
		if(prev==0)
			dp[cur][sofar][prev] = zero+col[cur][0]+solve(cur+1,0,0,0,1);
		else if(prev==1) 
			dp[cur][sofar][prev]  =one+col[cur][1]+solve(cur+1,0,0,0,0);
	}
	else
	{
		if(prev==0)
			dp[cur][sofar][prev]  =min(zero+col[cur][0]+solve(cur+1,0,0,0,1), solve(cur+1,sofar+1,zero+col[cur][0],one+col[cur][1],prev));
		else if(prev==1) 
			dp[cur][sofar][prev]  =min(one+col[cur][1]+solve(cur+1,0,0,0,0), solve(cur+1,sofar+1,zero+col[cur][0],one+col[cur][1],prev));
	}
	return dp[cur][sofar][prev];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>m>>x>>y;
	 	char ch[1002][1002];
	 	FOR(i,0,n)FOR(j,0,m)cin>>ch[i][j];
	 	FOR(i,0,1001)FOR(j,0,1001)FOR(k,0,2)dp[i][j][k]=-1;
	 	FOR(i,0,m)
	 	{
	 		FOR(j,0,n)
	 		{
	 			if(ch[j][i]=='.')col[i][0]++;
	 			else col[i][1]++;
	 		}
	 	}
	 	cout<<min(solve(0,0,0,0,1),solve(0,0,0,0,0));
		return 0;
}