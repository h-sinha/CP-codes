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
const int L=2e5+7;
map<ll,ll> counter;
ll s[L],text[L],len,bear[L],ele[L],lps[L];
void preprocess()
{
	int j = 0;
	lps[0]=0;
	for (int i = 1; i < len; ++i)
	{
		if(s[i]==s[j])
		{
			j++;
			lps[i]=j;
		}
		else
		{
			if(j == 0)
			{
				lps[i]=0;
			}
			else
			{
				while(j > 0 && s[i] != s[j])
				{
					j = lps[j-1];
				}
				if(s[i] == s[j])
				{
					j++;
				}
				lps[i]=j;
			}
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,w,ans=0;
	cin>>n>>w;
	FOR(i,0,n)cin>>bear[i];
	FOR(i,0,w)cin>>ele[i];
	bear[n]=ele[w]=0;
	FOR(i,0,n)text[i]=bear[i]-bear[i+1];
	FOR(i,0,w-1)s[i]=ele[i]-ele[i+1];
	len=w;
	int j=0;
	if(w==1){cout<<n;return 0;}
	preprocess();
	FOR(i,0,n)
	{
		if(text[i]==s[j])j++;
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
				i--;
			}
		}
		if(j==w-1)
		{
			ans++;
			j=lps[j-1];
		}
	}
	cout<<ans;
	return 0;
}