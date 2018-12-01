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
	int n,t,c;
	cin>>n>>t>>c;
	std::vector<int> v(n);
	std::vector<int> aux(n);
	FOR(i,0,n)cin>>v[i];
	int flag=INT_MAX;
	FOR(i,0,n)
	{
		if(v[i]>t)flag=i;
		aux[i]=flag;
	}
	int ans=0;
	FOR(i,0,n-c+1)
		if(aux[i+c-1]<i || aux[i+c-1]==INT_MAX)ans++;
	cout<<ans;
	return 0;
}