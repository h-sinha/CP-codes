#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counterer;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
int modu=1000000007;
std::vector<bool> visit(102);
int start[100],aux[100],end[100];
ll counter=0,flag=0;
std::vector<int> ans;
void dfs(int vertex);
std::vector<int> v[27];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;string str[102];
	cin>>n;
	FOR(i,0,n)
		cin>>str[i];
	FOR(i,0,n-1)
	{
			int len1=str[i].length();
			int len2=str[i+1].length();
			int  temp=min(len1,len2);
		// cout<<i<<" "<<len1<<" "<<len2 <<endl;
			FOR(k,0,temp)
			{
				if(str[i][k]!=str[i+1][k])
				{
					// cout<<i<<" "<<str[i][k]<<endl;
					v[str[i][k]-'a'].pb(str[i+1][k]-'a');
					break;
				}
				 if(k==temp-1 && len2<len1)
				 {
				 	cout<<"Impossible";
				 	return 0;
				 }
			}
	}
	FOR(i,0,26)
	{
		if(sz(v[i]))
			dfs(i);
	}
	if(flag){cout<<"Impossible";return 0;}
	int size=sz(ans);
	RFOR(i,size-1,0)
	cout<<char(ans[i]+97);
	FOR(i,0,26)
	{
		if(!visit[i])
		cout<<char(i+97);			
	}
	return 0;
}
void dfs(int vertex)
{
	if(visit[vertex]){if(aux[vertex]==1)flag=1;return;}
	visit[vertex]=true;
	aux[vertex]=1;
	FOR(i,0,sz(v[vertex]))
		dfs(v[vertex][i]);
	aux[vertex]=0;
		ans.pb(vertex);
}