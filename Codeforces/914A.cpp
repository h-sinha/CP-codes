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
	int n;
	cin>>n;
	std::vector<int> v(n);
	FOR(i,0,n)cin>>v[i];
	sort(v.begin(), v.end());
	RFOR(i,n-1,0)
	{
		int temp1=sqrt(v[i]);
		int temp2=temp1-1;
		int temp3=temp1+1;
		if(temp1*temp1!=v[i] &&temp2*temp2!=v[i]&&temp3*temp3!=v[i])
		{
			cout<<v[i];
			return 0;
		}
	}
	return 0;
}