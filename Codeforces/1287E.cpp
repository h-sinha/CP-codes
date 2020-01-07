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
bool comp(string x, string y)
{
	return x.length() < y.length();
}
int main()
{
	multiset<string>SET;
	string s;
	int n, co;
	cin >> n;
	co = (n*(n+1))/2;
	cout<<"? "<<1<<" "<<n<<endl;
	fflush(stdout);
	FOR(i,0,co)
	{
		cin >> s;
		sort(all(s));
		SET.insert(s);
	}
	if(n == 1)
	{
		cout<<"! "<<*SET.begin()<<endl;
		return 0;
	}
	cout<<"? "<<2<<" "<<n<<endl;
	fflush(stdout);
	co = (n*(n-1))/2;
	std::vector<string> v;
	FOR(i,0,co)
	{
		cin >> s;
		sort(all(s));
		SET.erase(SET.find(s));
	}
	trace(SET,x)v.pb(x);
	sort(all(v), comp);
	string out = "";
	trace(v,x)
	{
		if(out.length() == 0)
		{
			out += x;
			continue;
		}
		map<char, int>co;
		n = out.length();
		FOR(i,0,n)
		{
			co[out[i]]++;
		}
		n = x.length();
		FOR(i,0,n)
		{
			if(co[x[i]] > 0)co[x[i]]--;
			else 
			{
				out += x[i];
				break;
			}
		}
	}
	cout<<"! "<<out<<endl;
	return 0;
}