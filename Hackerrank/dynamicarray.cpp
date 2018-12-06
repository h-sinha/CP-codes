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
std::vector<ll> v[100002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll x,y,last=0,n,q,temp,size,type;
	 	cin>>n>>q;
	 	while(q--)
	 	{
	 		cin>>type>>x>>y;
	 		switch(type)
	 		{
	 			case 1:
	 				temp=(x^last)%n;
	 				v[temp].pb(y);
	 				break;
	 			case 2:
	 				temp=(x^last)%n;
	 				size=sz(v[temp]);
	 				last=v[temp][y%size];
	 				cout<<last<<ln;
	 				break;
	 		}
	 	}
		return 0;
}