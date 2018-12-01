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
	 	int n;
	 	cin>>n;
	 	string str;
	 	cin>>str;
		if(n==1 && str[0]=='0'){cout<<"No";return 0;}
	 	FOR(i,0,n)
	 	{
	 		if(str[i]=='1')
	 		{
	 			if(i>0 && i<n-1)
	 			{
	 				if(str[i-1]=='1' || str[i+1]=='1')
	 				{
	 					cout<<"No";
	 					return 0;
	 				}
	 			}
	 			else if(i==0)
	 			{
	 				if(str[i+1]=='1')
	 				{
	 					cout<<"No";
	 					return 0;
	 				}
	 			}
	 			else if (i==n-1)
	 			{
	 				if(str[i-1]=='1')
	 				{
	 					cout<<"No";
	 					return 0;
	 				}
	 			}
	 		}
	 	}
	 	FOR(i,0,n)
	 	{
	 		if(str[i]=='0')
	 		{
	 			if(i>0 && i<n-1)
	 			{
	 				if(str[i-1]=='0' && str[i+1]=='0')
	 				{
	 					cout<<"No";
	 					return 0;
	 				}
	 			}
	 			else if(i==0)
	 			{
	 				if(str[i+1]=='0')
	 				{
	 					cout<<"No";
	 					return 0;
	 				}
	 			}
	 			else if (i==n-1)
	 			{
	 				if(str[i-1]=='0')
	 				{
	 					cout<<"No";
	 					return 0;
	 				}
	 			}
	 		}
	 	}
	 	cout<<"Yes";
		return 0;
}