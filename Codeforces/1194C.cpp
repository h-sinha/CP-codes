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

const int L=1e6+7;
map<ll,ll> counter;
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
int co[L];
bool isSubSequence(string str1, string str2, int m, int n) 
{ 
    if (m == 0) return true; 
    if (n == 0) return false; 
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
    return isSubSequence(str1, str2, m, n-1); 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	string s, t, p;
	while(tt--)
	{
		FOR(i,0,30)co[i] = 0;
		cin >> s >> t >> p;
		int len1 = s.length();
		int len2 = t.length();
		int len3 = p.length();
		if(!isSubSequence(s,t,len1,len2))
		{
			cout<<"NO\n";
			continue;
		}
		FOR(i,0,len3)
		{
			co[p[i]-'a']++;
		}
		string tmp = "";
		int idx = 0;
		FOR(i,0,len1)
		{
			// debug(t[idx], s[i], idx, i);
			while(idx<len2 && t[idx] != s[i])
			{
				tmp += t[idx];
				idx++;
			}
			idx++;
		}
		while(idx<len2 )
			{
				tmp += t[idx];
				idx++;
			}
		int ss = tmp.length(), f = 0;
		// debug(tmp);
		FOR(i,0,ss)
		{
			// debug(co[0], tmp[i]);
			if(co[tmp[i] - 'a']==0)
			{
				f = 1;
				break;
			}
			co[tmp[i]-'a']--;
		}
		if(f)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}