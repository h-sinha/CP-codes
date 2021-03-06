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
const int L=1e5+7;
char mat[502][502];
int starti, startj ,endi, endj, n, m , flag = 0, dx[5]={1,-1,0,0},dy[5]={0,0,1,-1};
bool danger(int i, int j)
{
	if(i==endi && j==endj)return 1;
	if(i>n || j>m || i<1 || j<1 || mat[i][j]=='X')return 0;
	return 1;
}
void dfs(int i, int j)
{
	// cout<<i<<" - "<<j<<ln;
	if(i==endi && j==endj && mat[i][j]=='X')
	{
		flag=1;
		return;
	}
	mat[i][j] = 'X';
	FOR(idx,0,4)	
		if(danger(i+dx[idx] ,j+dy[idx]))
			dfs(i+dx[idx],j+dy[idx]);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>m;
	 	FOR(i,1,n+1)FOR(j,1,m+1)cin>>mat[i][j];
	 	cin >> starti >> startj;
	 	cin >> endi >> endj;
	 	if(starti == endi && startj == endj)
	 		mat[starti][startj] = '.';
	 	// if(mat[starti][startj]!='X')
	 	dfs(starti, startj);
		if(flag)cout<<"YES";
		else cout<<"NO";
		return 0;
}