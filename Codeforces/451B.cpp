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
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,a;
	 	cin>>n;
	 	std::vector<ll> v;
	 	std::vector<ll> u;
	 	FOR(i,0,n)
	 	{
	 		cin>>a;
	 		v.pb(a);
	 		u.pb(a);
	 	}
	 	sort(v.begin(), v.end());
	 	int co=0;
	 	FOR(i,0,n)
	 	{
	 		if(v[i]!=u[i])break;
	 		co++;
	 	}
	 	if(co==n){cout<<"yes\n1 1";return 0;}
	 	int fin=-1,init,f=0;
	 	FOR(i,0,n)
	 	{
	 		if(v[i]==u[i])continue;
	 		if(f==1){cout<<"no";return 0;}
	 		int l=i+1;
	 		init=i;
	 		while(l<n)
	 		{
	 			if(u[l]>u[l-1])
	 			{
	 				if(u[l]!=v[i])
	 				{
	 					cout<<"no";
	 					return 0;
	 				}
	 				else
	 				{
	 					f=1;
	 					fin=l-1;
	 					i=l;
	 					break;
	 				}
	 			}
	 			l++;
	 			i=l;
	 		}
	 	}
	 	cout<<"yes"<<ln;
	 	if(fin==-1)fin=n-1;
	 	cout<<init+1<<" "<<fin+1<<ln;
		return 0;
}