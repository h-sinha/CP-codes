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
const int L=1e5+7;
map<ll,ll> counter;
std::vector<int> lps;
std::vector<char> text;
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
int dp[102][102],mark[102],mark1[102];
void lis(string s1,string s2)
{
	int len1=s1.length(),len2=s2.length();
	FOR(i,0,len1+1)
	{
		FOR(j,0,len2+1)
		{
			if(i==0||j==0)dp[i][j]=0;
			else if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int i=len1,j=len2;
	while(i>0 && j>0)
	{
		if(s1[i-1]==s2[j-1]){text.pb(s1[i-1]);i--;j--;}
		else if(dp[i-1][j]>dp[i][j-1])i--;
		else j--;
	}
	reverse(all(text));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1,s2, pattern;
	cin >> s1>>s2;
	cin >> pattern;
	lis(s1,s2);

	preprocess(pattern);
	int text_length = sz(text), pattern_length = pattern.length();
	int cur = 0,co=0;
	for (int i = 0; i < text_length; ++i)
	{
		if(text[i] == pattern[cur])
		{
			cur++;
		}
		else 
		{
			if(cur != 0)
			{
				cur = lps[cur - 1];
				i--;
			}
		}
		if(cur == pattern_length)
		{
			mark[i]=1;
			// cout<<cur<<ln;
			FOR(j,i+1,sz(text))
			{
				if(text[cur]==text[j])
				{
					// cout<<j<<ln;
					mark[j]=1;co++;
				}
				else break;
			}
			co++;
			cur = lps[cur - 1];
		}
	}
	int a1=sz(text)-co;
	int co1=0;cur=0;
	// cout<<co<<ln;
	for (int i = 0; i < text_length; ++i)
	{
		if(text[i] == pattern[cur])
		{
			cur++;
		}
		else 
		{
			if(cur != 0)
			{
				cur = lps[cur - 1];
				i--;
			}
		}
		if(cur == pattern_length)
		{
			// cout<<"sa";
			mark1[i-cur+1]=1;
			RFOR(j,i-cur,0)
			{
				if(text[i-cur+1]==text[j])
				{
					mark1[j]=1;co++;
				}
				else break;
			}
			co1++;
			cur = lps[cur - 1];
		}
	}
	// cout<<co1<<ln;
	int a2=sz(text)-co1;
	if(a2>a1)
	{
		co=co1;
		for (auto it = text.begin(); it !=text.end(); ++it)
		{
			if(mark1[it-text.begin()])continue;
			cout<<*it;
		}
	}
	// cout<<ln;
	else
	{
		for (auto it = text.begin(); it !=text.end(); ++it)
		{
			if(mark[it-text.begin()])continue;
			cout<<*it;
		}
	}
	// cout<<a1<<" "<<a2<<ln;
	if(sz(text)==0 || co==sz(text))cout<<"0";
	return 0;
}
