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
std::map<char, int> hsh;
multiset<string> v[L][5];
std::vector<pair<string, string> > samelength, same;
void process(string t)
{
	char ch;
	int len = t.length(), co = 0;
	FOR(i,0,len)
	{
		if(t[i] == 'a' || t[i] == 'e'|| t[i] == 'i'|| t[i] == 'o'|| t[i] == 'u')
		{
			co++;
			ch = t[i];
		}
	}
	v[co][hsh[ch]].insert(t);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	string s;
	 	hsh['a'] = 0;
	 	hsh['e'] = 1;
	 	hsh['i'] = 2;
	 	hsh['o'] = 3;
	 	hsh['u'] = 4;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> s;
	 		process(s);
	 	}
	 	string s1, s2;
	 	multiset<string>left;
	 	FOR(i,0,100001)
	 	{
	 		left.clear();
	 		FOR(j,0,5)
	 		{
	 			while(sz(v[i][j])>=2)
	 			{
	 				s1 = *v[i][j].begin();
	 				v[i][j].erase(v[i][j].begin());
	 				s2 = *v[i][j].begin();
	 				v[i][j].erase(v[i][j].begin());
	 				same.pb(mp(s1, s2));
	 			}
	 			trace(v[i][j], x)
	 			{
	 				left.insert(x);
	 			}
	 		}
	 		while(sz(left) >= 2)
	 		{
	 			s1 = *left.begin();
	 			left.erase(left.begin());
	 			s2 = *left.begin();
	 			left.erase(left.begin());
	 			samelength.pb(mp(s1,s2));
	 		}
	 	}
	 	if(sz(same)<sz(samelength))
	 	{
	 		cout<<sz(same)<<ln;
	 		int i = 0;
	 		while(i<sz(same))
	 		{
	 			cout<<samelength[i].F<<" "<<same[i].F<<ln;
	 			cout<<samelength[i].S<<" "<<same[i].S<<ln;
	 			i++;
	 		}
	 	}
	 	else
	 	{
	 		int ans = sz(samelength) + (sz(same) - sz(samelength))/2;
	 		int i = 0;
	 		cout<<ans<<ln;
	 		while(i<sz(samelength))
	 		{
	 			cout<<samelength[i].F<<" "<<same[i].F<<ln;
	 			cout<<samelength[i].S<<" "<<same[i].S<<ln;
	 			i++;
	 		}
	 		while(i+1 < sz(same))
	 		{
	 			cout<<same[i].F<<" "<<same[i+1].F<<ln;
	 			cout<<same[i].S<<" "<<same[i+1].S<<ln;
	 			i+=2;
	 		}
	 	}
		return 0;
}