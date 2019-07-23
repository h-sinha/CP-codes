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
	string s1, s2, s3;
	cin >> s1 >> s2 >>s3;
	int f =0;
	if(s1[1] == s2[1] && s2[1] == s3[1])
	{
		if(s1[0] == s2[0] && s2[0] == s3[0])f = 1;
		std::vector<int> v;
		v.pb(s1[0] - '0');
		v.pb(s2[0] - '0');
		v.pb(s3[0] - '0');
		sort(all(v));
		if(v[0] == v[1]-1 && v[1] == v[2]-1)f=1;
	}
	if(f)cout<<0;
	else
	{
		int ans = 2;

		if(s1[1] == s2[1])
		{
			if(s1[0] == s2[0])ans = 1;
			if(s1[0] == s2[0] - 1 || s1[0] == s2[0] + 1)ans = 1;
			if(s1[0] == s2[0] - 2 || s1[0] == s2[0] + 2)ans = 1;
		}
		if(s1[1] == s3[1])
		{
			if(s1[0] == s3[0])ans = 1;
			if(s1[0] == s3[0] - 1 || s1[0] == s3[0] + 1)ans = 1;
			if(s1[0] == s3[0] - 2 || s1[0] == s3[0] + 2)ans = 1;
		}
		if(s3[1] == s2[1])
		{
			if(s3[0] == s2[0])ans = 1;
			if(s3[0] == s2[0] - 1 || s3[0] == s2[0] + 1)ans = 1;
			if(s3[0] == s2[0] - 2 || s3[0] == s2[0] + 2)ans = 1;
		}
		cout<<ans;
	}
	return 0;
}