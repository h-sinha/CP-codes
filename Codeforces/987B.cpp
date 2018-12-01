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
	 	ll x,y;
	 	cin>>x>>y;
	 	if(x==y)
	 		{cout<<"=";
	 	return 0;}
	 	if(x<y)
	 	{
	 		if(x>=3)cout<<">"<<ln;
	 		else if(x==2)
	 		{
	 			if(y==3)
	 			{
	 				cout<<"<"<<ln;
	 			}
	 			else if(y==4)
	 			{
	 				cout<<"=";
	 			}
	 			else cout<<">";
	 		}
	 		if(x==1)
	 		{
	 			if(y==1)cout<<"=";
	 			else cout<<"<";
	 		}
	 	}
	 	else 
	 	{
	 		if(y>=3)cout<<"<"<<ln;
	 		else if(y==2)
	 		{
	 			if(x==3)
	 			{
	 				cout<<">"<<ln;
	 			}
	 			else if(x==4)
	 			{
	 				cout<<"=";
	 			}
	 			else cout<<"<";
	 		}
	 		if(y==1)
	 		{
	 			if(x==1)cout<<"=";
	 			else cout<<">";
	 		}
	 	}
		return 0;
}