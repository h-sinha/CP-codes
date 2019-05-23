#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=55;
int dp[1002][L][L], lps[L][2];
string s, a, b;
int length[2], slength;
void preprocess(string s, int flag)
{
	int len = length[flag], j = 0;
	lps[0][flag] = 0;
	for (int i = 1; i < len; ++i)
	{
		if(s[i]==s[j])
		{
			j++;
			lps[i][flag] = j;
		}
		else
		{
			if(j == 0)
			{
				lps[i][flag] = 0;
			}
			else
			{
				while(j > 0 && s[i] != s[j])
				{
					j = lps[j-1][flag];
				}
				if(s[i] == s[j])
				{
					j++;
				}
				lps[i][flag] = j;
			}
		}
	}
	return;
}
int solve(int i, int j, int k)
{
	if(i == slength)return 0;
	int start = 0, term = 26;
	if(dp[i][j][k] != INT_MIN)
	{
		return dp[i][j][k];
	}
	if(s[i] != '*')start = s[i] - 'a', term = start + 1;
	int c1 = 0, c2 = 0, c = 0, cur;
	FOR(ch,start,term)
	{
		c1 = 0, c2 = 0, c = 0;
		cur = j;
		while(cur != 0)
		{
			if(a[cur] == char('a' + ch))
			{
				c1 = cur + 1;
				break;
			}
			cur = lps[cur - 1][0];
		}
		if(!c1 && a[0] == char('a' + ch))c1++;
		cur = k;
		while(cur != 0)
		{
			if(b[cur] == char('a' + ch))
			{
				c2 = cur + 1;
				break;
			}
			cur = lps[cur - 1][1];
		}
		if(!c2 && b[0] == char('a' + ch))c2++;
		if(c1 == length[0])
		{
			c++;
			c1 = lps[c1 - 1][0];
		}
		if(c2 == length[1])
		{
			c--;
			c2 = lps[c2 - 1][1];
		}
		dp[i][j][k] = max(dp[i][j][k], c + solve(i + 1, c1, c2));
	}
	return dp[i][j][k];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> s;
	 	cin >> a >> b;
	 	FOR(i,0,1001)FOR(j,0,52)FOR(k,0,52)dp[i][j][k] = INT_MIN;
	 	length[0] = a.length();
	 	length[1] = b.length();
	 	slength = s.length();
	 	preprocess(a, 0);
	 	preprocess(b, 1);
	 	cout << solve(0, 0, 0);
		return 0;
}