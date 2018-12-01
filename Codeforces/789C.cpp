#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;
typedef long double ld;
int main()
{
	ll n;
	cin>>n;
	std::vector<ll> a(100002);
	std::vector<ll> s1(n-1);
	std::vector<ll> s2(n-1);
	FOR(i,0,n)cin>>a[i];
	s2[0]=abs(a[0]-a[1]);
	s1[0]=abs(a[0]-a[1])*(-1);
	FOR(i,1,n-1)s2[i]=s2[i-1]+(abs(a[i]-a[i+1])*pow(-1,i));
	FOR(i,1,n-1)s1[i]=s1[i-1]+(abs(a[i]-a[i+1])*pow(-1,i+1));
	sort(s2.begin(), s2.end());
	ll ans=max(s2[n-2],s2[n-2]-s2[0]);
	sort(s1.begin(), s1.end());
	ll temp=max(s1[n-2],s1[n-2]-s1[0]);
	cout<<max(ans,temp);
	return 0;
}