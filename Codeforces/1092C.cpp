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

const int L=1000;
string s[L];
int n;
std::vector<bool> pre(L), suf(L), done(L);
bool check(string x)
{
	int len;
	fill(all(pre), 0);
	fill(all(suf), 0);
	fill(all(done), -1);
	FOR(i,0,2*n-2)
	{
		len = s[i].length();
		if(!pre[len] && x.substr(0, len) == s[i])
		{
			pre[len] = 1;
			done[i] = 0;
		}
		else if(!suf[len] && x.substr(n-len, len) == s[i])
		{
			suf[len] = 1;
			done[i] = 1;
		}
		else return 0;
	}
	FOR(i,0,2*n-2)
		if(done[i])cout<<"S";
		else cout<<"P";
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int len;
	 	cin >> n;
	 	FOR(i,0,2*n-2)cin >> s[i];
	 	FOR(i,0,2*n-2)
	 	{
	 		len = s[i].length();
	 		if(len == 1)
	 		{
	 			FOR(j,0,2*n-2)
	 			{
	 				len = s[j].length();
	 				if(len == n-1)
	 				{
	 					if(check(s[i] + s[j]))return 0;
	 				}
	 			}
	 		}
	 	}
		return 0;
}