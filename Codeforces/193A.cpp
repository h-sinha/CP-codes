#include <bits/stdc++.h>
using namespace std;
const int L = 50;
int visit[L][L], lowlink[L][L], ans[L][L], id[L][L], outEdge, ri, rj, start;
int n, m, co;
char ch[L][L];
int dx[5] = {0,0,1,-1}, dy[5] = {1, -1,0,0};
bool check(int i, int j)
{
	if(i >= n || j >= m || i < 0 || j < 0 || ch[i][j] == '.')return 0;
	return 1;
}
void dfs(int i, int j, int pi, int pj)
{
	lowlink[i][j] = id[i][j] = ++start;
	visit[i][j] = 1;
	int cur = 0, ni, nj;
	for (int ii = 0; ii < 4; ++ii)
	{
		ni = i + dx[ii], nj = j + dy[ii];
		if(!check(ni, nj))continue;
		if(ni == pi && nj == pj)continue;
		if(visit[ni][nj])
		{
			lowlink[i][j] = min(lowlink[i][j], id[ni][nj]);
			continue;
		}
		cur++;
		dfs(ni, nj, i, j);
		lowlink[i][j] = min(lowlink[i][j], lowlink[ni][nj]);
		if((i != ri || j != rj) && id[i][j] <= lowlink[ni][nj])co =1;
	}
	if(cur >= 2 && i == ri && j == rj)co = 1;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int hs = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> ch[i][j];
			if(ch[i][j] == '#')
			{
				ri = i, rj = j;
				hs++;
			}
		}
	}
	if(hs < 3)
	{
		cout<<"-1";
		return 0;
	}
	dfs(ri, rj, -1, -1);
	if(co)cout<<"1";
	else cout<<"2";
}