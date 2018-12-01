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
int a[100002],b[100002],ans=INT_MAX,cur=INT_MAX,n,diff;
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
void func()
{
	 	FOR(i,2,n)
	 	{
	 		if(a[i]-a[i-1]==diff)continue;
	 		if(a[i]+1-a[i-1]==diff){a[i]+=1;cur++;}
	 		else if(a[i]-1-a[i-1]==diff){a[i]-=1;cur++;}
	 		else{ cur=INT_MAX;break;}
	 	}
	 	ans=min(ans,cur);
	 	FOR(i,0,n)a[i]=b[i];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n;
	 	FOR(i,0,n){cin>>a[i];b[i]=a[i];}
	 	cur=0,diff=a[1]-a[0];
	 	func();
	 	a[0]+=1;diff=a[1]-a[0],cur=1;
	 	func();
	 	a[0]-=1;diff=a[1]-a[0],cur=1;
	 	func();
	 	a[1]+=1;diff=a[1]-a[0],cur=1;
	 	func();
	 	a[1]-=1;diff=a[1]-a[0],cur=1;
	 	func();
	 	a[0]+=1,a[1]-=1;diff=a[1]-a[0],cur=2;
	 	func();
	 	a[0]-=1,a[1]+=1;diff=a[1]-a[0],cur=2;
	 	func();
	 	a[0]+=1,a[1]+=1;diff=a[1]-a[0],cur=2;
	 	func();
	 	a[0]-=1,a[1]-=1;diff=a[1]-a[0],cur=2;
	 	func();
	 	if(ans==INT_MAX)cout<<"-1"<<ln;
	 	else cout<<ans<<ln;
		return 0;
}