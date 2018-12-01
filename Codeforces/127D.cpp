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
std::vector<int> lps;string s;
int len,co[L];
void preprocess()
{
	int j = 0;
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
					// i--;
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	len=s.length();
	preprocess();
	FOR(i,0,len)co[lps[i]]++;
	int cur=lps[len-1],j=0;
	// cout<<cur<<ln;
	if(co[cur]>1 && cur!=0)
	{
		FOR(i,0,cur)cout<<s[i];
		return 0;
	}
	// FOR(i,0,len)cout<<s[i]<<" "<<lps[i]<<ln;
	if(cur!=0)
	cur=lps[cur-1];
	if(cur!=0)
	{
		FOR(i,0,cur)cout<<s[i];
		return 0;
	}
	cout<<"Just a legend";
	return 0;
}