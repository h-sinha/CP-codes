#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
std::vector<bool> visit(100002);
int arr[100002];
int n,m,ans=0;
int modu=1000000007;
std::vector<int> v[100002];
void dfs(int vertex,int countsofar);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>n>>m;
	FOR(i,1,n+1)cin>>arr[i];
	FOR(i,0,n-1)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
//	if(arr[1])
//	dfs(1,0,1);
//	else 
	dfs(1,0);
	FOR(i,2,n+1)
		if(v[i].size()==1 && visit[i])ans++;
	cout<<ans<<endl;
	return 0;
}
void dfs(int vertex,int countsofar)
{
	if(visit[vertex])return;
	int temp=0;
	if(countsofar+arr[vertex]>m)return;
	visit[vertex]=1;
	FOR(i,0,v[vertex].size())
	{
		if(arr[vertex])
			dfs(v[vertex][i],countsofar+1);
		else
			dfs(v[vertex][i],0);
	}

}