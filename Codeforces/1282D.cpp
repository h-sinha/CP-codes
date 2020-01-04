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
	int na, nb,n, a, a1;
	string s1 = "";
	string s2 = "";
	FOR(i,0,300)s1 += "a";
	FOR(i,0,300)s2 += "b";
	cout<<s1<<endl;
	fflush(stdout);
	cin >> na;
	if(na == 0)exit(0);
	na = 300 - na;
	cout<<s2<<endl;
	fflush(stdout);
	cin >> nb;
	if(nb == 0)exit(0);
	nb = 300 - nb;
	n = na + nb;
	string s = "";
	FOR(i,0,n)s += "a";
	a = nb;
	FOR(i,0,n-1)
	{
		s[i] = 'b';
		cout<<s<<endl;
		fflush(stdout);
		cin >> a1;
		if(a1 == 0)exit(0);
		if(a1 < a)s[i] = 'b', a = a1, nb--;
		else s[i] = 'a', na--;
	}
	if(nb)s[n-1] = 'b';
	cout<<s<<endl;
	cin >> a;
	return 0;
}