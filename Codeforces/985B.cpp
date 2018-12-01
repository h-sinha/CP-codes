#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int sumis[2005];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m;
	 	string arr[2002];
	 	cin>>n>>m;

	 	FOR(i,0,n)cin>>arr[i];
	 	FOR(i,0,n)
	 	{
	 		FOR(j,0,m)
	 		{
	 			sumis[j]+=(arr[i][j]-'0');
	 		}
	 	}
	 	int co=0;

	 	FOR(i,0,n)
	 	{
	 		co=0;
	 		FOR(j,0,m)
	 		{
	 			if(sumis[j]-(arr[i][j]-'0')>0)co++;
	 		}
	 		if(co==m)
	 		{
	 			cout<<"YES";
	 			return 0;
	 		}
	 	}
	 	cout<<"NO";

		return 0;
}