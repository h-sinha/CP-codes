#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=b;i>=a;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> mark;
std::vector<bool> visit(100002);
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int co=0,n,k;
	 	char ans[101][101];
	 	cin>>n>>k;
	 	FOR(i,1,5)FOR(j,1,n+1)ans[i][j]='.';
	 	int curx=2,cury=2,check=(n+1)>>1;
	 	while(k)
	 	{
	 		if(k-2>=0)
	 		{
	 			ans[2][cury]='#';
	 			ans[3][cury]='#';
	 			cury++;
	 			if(cury>=check){cury=2;curx++;}
	 			k-=2;
	 		}
	 		else break;
	 	}
	 	if(k==1)
	 	{
	 		if(ans[2][check])
	 		{
	 			ans[2][check]='#';
	 			k--;
	 		}
	 	}
	 	if(k)cout<<"NO"<<ln;
	 	else
	 	{
	 		cout<<"YES"<<ln;
	 		FOR(i,1,5)
	 		{
	 			FOR(j,1,n+1)
	 			cout<<ans[i][j];
	 			cout<<ln;
	 		}
	 	}
		return 0;
}