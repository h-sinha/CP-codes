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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t, y;
	cin >> s;
	int n = s.length();
	int l = 0, r = n-1, f = 0;
	while(l <= r)
	{
		if(s[l] == s[r])
		{
			t += s[l];
			if(l == r)f = 1;
			l++, r--;
		}
		else if(l+1<=r && s[l+1] == s[r])
		{
			t += s[l+1];
			if(l+1 == r)f = 1;
			l += 2, r--;
		}
		else if(l<=r-1 && s[l] == s[r-1])
		{
			t += s[l];
			if(l == r-1)f = 1;
			l++, r-=2;
		}
		else if(l+1<=r-1 && s[l+1] == s[r-1])
		{
			t += s[l+1];
			if(l+1 == r-1)f = 1;
			l+=2, r-=2;
		}
		else
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	if(f)
		y = t.substr(0, t.length() - 1);
	else
		y = t;
	reverse(all(y));
	cout << t + y;
	return 0;
}