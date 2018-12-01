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
	ll a,b,x,y,z,ans=0;
	cin>>a>>b;
	cin>>x>>y>>z;
	ll tempy=2*x;
	tempy+=y;
	ll tempb=y;
	tempb+=(3*z);
	if(tempb>=b)
		ans+=(tempb-b);
	if(tempy>=a)
		ans+=(tempy-a);
	cout<<ans;
	return 0;
}