#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	cin>>n>>k;
	if(k==1)
	{
		cout<<n;
		return 0;
	}
	ll m=0;
	while(pow(2,m)<=n)
		m++;
	ld temp=pow(2,m)-1;
	if(m<=k)
	printf("%.0Lf\n",temp );
	else
	{
		ld temp1=ll(temp)^ll(temp+1);
		printf("%.0Lf\n",temp);
	}
	return 0;
}