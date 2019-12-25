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
std::map<char, int> hs;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q, n;
	cin >> q;
	string s;
	hs['L'] = 0;
	hs['R'] = 1;
	hs['U'] = 2;
	hs['D'] = 3;
	while(q--)
	{
		cin >> s;
		std::vector<int> co(5);
		n = s.length();
		FOR(i,0,n)co[hs[s[i]]]++;
		int ans = min(co[0], co[1]);
		int ans1 = min(co[2], co[3]);
		if(ans == 0)
		{
			if(ans1 != 0)cout<<"2\nUD\n";
			else cout<<"0\n\n";
			continue;
		}
		if(ans1 == 0)
		{
			if(ans != 0)cout<<"2\nLR\n";
			else cout<<"0\n\n";
			continue;
		}
		cout<<ans*2 + 2*ans1<<ln;
		FOR(i,0,ans)cout<<"L";
		FOR(i,0,ans1)cout<<"U";
		FOR(i,0,ans)cout<<"R";
		FOR(i,0,ans1)cout<<"D";
		cout<<ln;
	}
	return 0;
}