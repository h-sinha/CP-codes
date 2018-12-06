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
	 	string s;
	 	int t;
	 	cin>>t;
	 	while(t--)
	 	{
	 		cin>>s;
	 		int len=s.length();
	 		int aux=(len)/2,f=0,no=0;
	 		FOR(i,0,len)if(s[i]!='9')no=1;
	 		if(!no)
	 		{
	 			cout<<"1";
	 			FOR(i,0,len-1)cout<<"0";
	 			cout<<"1"<<ln;
	 			continue;
	 		
	 		}
	 		if(len%2==0)aux--;
	 		RFOR(i,aux,0)
	 		{
	 			if(s[i]!='9')
	 			{
	 				s[i]+=1;
	 				if(len-i-1!=i)
	 				s[len-i-1]+=1;
	 				break;
	 			}
	 			else
	 			{
	 				s[i]='0';
	 				s[len-i-1]='0';
	 			}
	 		}
	 		FOR(i,0,len)cout<<s[i];
	 		cout<<ln;
	 	}
		return 0;
}