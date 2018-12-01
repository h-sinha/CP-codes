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
const int L=1e6+7;
map<ll,ll> counter;
set<int>SET;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
std::vector<int> lps;
int a[L];
void preprocess(string s)
{
	int len = s.length(), j = 0;
	lps.push_back(0);
	for (int i = 1; i < len; ++i)
	{
		if(s[i]==s[j])
		{
			j++;
			lps.push_back(j);
		}
		else
		{
			if(j == 0)
			{
				lps.push_back(0);
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
				lps.push_back(j);
			}
		}
	}
	return;
}
void pre(int len)
{
	int aa=lps[len-1];
	while(aa>0)
	{
		SET.insert(aa);
		aa=lps[aa-1];
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	ll co=0,diff;
	string pattern;
	
	cin>>n>>m;
	cin>>pattern;
	if(m==0){cout<<fastexpo(26,n);return 0;}
	preprocess(pattern);	
	
	FOR(i,0,m)cin>>a[i];
	FOR(i,0,m)a[i]--;
	
	sort(a,a+m);
	int cur=0,len=pattern.length();
	
	co+=a[0];
	cur=a[0]+len-1;
	pre(len);
	
	FOR(i,1,m)
	{
		if(a[i]>cur)
		{
			co+=a[i]-cur-1;
			cur=a[i]+len-1;
		}
		else
		{
			diff=cur-a[i];
			if(SET.empty() || SET.find(diff+1)==SET.end())
			{
				cout<<"0";
				return 0;
			}
			cur=a[i]+len-1;
		}
	}
	co+=(n-cur-1);
	cout<<fastexpo(26,co);
	return 0;
}