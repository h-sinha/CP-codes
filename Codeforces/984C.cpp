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
	 	ll temp,n,f=0,co=0,temp1;
	 	cin>>n;
	 	ll p,q,b;
	 	while(n--)
	 	{
	 		cin>>p>>q>>b;
	 		temp=__gcd(p,q);
	 		p/=temp;
	 		q/=temp;
	 		temp=0;
	 		while(q>1)
	 		{
	 			temp1=__gcd(q,b);
	 			if(temp==temp1)
	 			{
	 				q/=temp1;
	 				temp=temp1;
	 				continue;
	 			}
	 			temp=temp1;
	 			q/=temp;
	 			b=temp;
	 			if(temp==1)break;
	 		}
	 		if(q>1)cout<<"Infinite"<<ln;
	 		else cout<<"Finite"<<ln;

	 	}
		return 0;
}