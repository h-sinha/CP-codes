#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<bool> visit(100002);
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,a,ans=0;
	 	cin>>n;
	 	std::vector<int> arr;
	 	std::vector<int>::iterator it;
	 	FOR(i,0,n){cin>>a;arr.pb(a);}
	 	left[0]=arr[0];
	 	FOR(i,1,n)left[i]=max(left[i-1],arr[i]);
	 	right[n-1]=arr[n-1];
	 	RFOR(i,n-2,0)right[i]=max(right[i+1],arr[i]);
	 	FOR(i,0,n)
	 	{
	 		it=upper_bound(arr.begin(), arr.end(),arr[n-1]/arr[i]);
	 		int temp=it-arr.begin();
	 		// cout<<arr[i]<<"-->"<<temp-i-1<<endl;
	 		if(temp>i)ans+=(temp-i-1);
	 	}
	 	cout<<ans;
		return 0;
}