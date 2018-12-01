#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::vector<int> ans(1000000);
	int n;
	cin>>n;
	ans[1]=1;
	int prev=1,cur=1;
	while(prev+cur<=1000000)
	{
		ans[prev+cur]=1;
		int temp=prev+cur;
		prev=cur;
		cur=temp;
	}
	FOR(i,1,n+1)
	{
		if(ans[i])
			cout<<"O";
		else cout<<"o";
	}
	return 0;
}