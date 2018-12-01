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
	 	ll l,r,num,a,b,n,temp=1;
	 	std::vector<ll> inp;
	 	cin>>a>>b;
	 	cin>>n;
	 	num=__gcd(a,b);
	 	ll aux=sqrt(num)+1;
	 	FOR(i,1,aux)
	 	{
	 		if(num%i==0)
	 		{
	 			inp.pb(i);
	 			if(num/i!=i)
	 			inp.pb(num/i);
	 		}
	 	}
	 	sort(inp.begin(), inp.end());
	 	std::vector<ll> ::iterator it;
	 	while(n--)
	 	{
	 		cin>>l>>r;
	 		it=lower_bound(inp.begin(), inp.end(),r);
	 		if(*it>=l && *it<=r)cout<<*it<<ln;
	 		else if(*(it-1)>=l && *(it-1)<=r)cout<<*(it-1)<<ln;
	 		else cout<<"-1"<<ln;
	 	}
		return 0;
}