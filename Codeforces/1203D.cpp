#include<bits/stdc++.h>
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
const int L=2e5+7;
string s, t;
int rdp[L], ldp[L];
int n, m;
bool check(ll val)
{
	if(rdp[val]>=m)return 1;
	FOR(i,1,n-val)
	{
		if(ldp[i-1] + rdp[i+val] >= m)return 1;
	}
	if(n-1-val>=0 && ldp[n-1-val]>=m)return 1;
	return 0;

}
void ser()
{
	int l=0,r=s.length(),mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	cout<<r;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin >> s >> t;
	 	n = s.length();
	 	int cur = t.length()-1;
	 	RFOR(i,n-1,0)
	 	{
	 		if(cur == -1)
	 		{
	 			rdp[i] = rdp[i+1];
	 			continue;
	 		}
	 		if(s[i] == t[cur])
	 		{
	 			rdp[i] = 1 + rdp[i+1];
	 			cur--;
	 		}
	 		else rdp[i] = rdp[i+1];
	 	}
	 	cur = 0;
	 	m = t.length();
	 	if(s[0] == t[0])
	 	{
	 		ldp[0] = 1;
	 		cur = 1;
	 	}
	 	FOR(i,1,n)
	 	{
	 		if(cur == m)
	 		{
	 			ldp[i] = ldp[i-1];
	 			continue;
	 		}
	 		if(s[i] == t[cur])
	 		{
	 			ldp[i] = 1 + ldp[i-1];
	 			cur++;
	 		}
	 		else ldp[i] = ldp[i-1];
	 	}
	 	ser();
		return 0;
}