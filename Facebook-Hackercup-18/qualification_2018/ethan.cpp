#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=2e3+7;
ll power[L],m=1e9+7;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
void pre()
{
	power[0]=1;
	FOR(i,1,2001)power[i] =(power[i-1] * 26)%m;
	// FOR(i,1,2001)cout<<power[i]<<" ";
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t,len,f=1,leftis;
	 	string s;
	 	cin>>t;
	 	pre();
	 	while(t--)
	 	{
	 		cin>>s;
	 		int len=s.length();
	 		ll hash[L],flag=0,pos;
	 		hash[0]=s[0]-'A'+1;
	 		FOR(i,1,len)
	 		{
	 			hash[i] = (hash[i-1]%m + (power[i] * (s[i]-'A'+1))%m )%m;
	 			// cout<<i<<" "<<hash[i]<<ln;
	 		}
	 		FOR(i,1,len-1)
	 		{
	 			if(s[i]==s[0])
	 			{
	 				leftis=len-i-1;
	 				// cout<<i<<" "<<" "<<leftis-1<<" "<<hash[leftis]<<" "<<((hash[len-1] - hash[i-1] +m)%m *fastexpo(power[i],m-2,m)%m)%m<<ln;
	 				if(hash[leftis] != ((hash[len-1] - hash[i-1] +m)%m *fastexpo(power[i],m-2,m)%m)%m )
	 				{
	 					pos=i;
	 					flag=1;
	 					break;
	 				}
	 			}
	 		}
	 		// cout<<flag<<" "<<pos<<ln;
	 		if(flag==0)
	 		{
	 			cout<<"Case #"<<f<<": Impossible\n";
	 		}
	 		else 
	 		{
	 			cout<<"Case #"<<f<<": ";
	 			FOR(i,0,pos)cout<<s[i];
	 			FOR(i,0,len)cout<<s[i];
	 			cout<<ln;
	 		}
	 		f++;
	 	}
		return 0;
}