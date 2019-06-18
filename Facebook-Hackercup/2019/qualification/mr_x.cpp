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
//*X.f_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
string s;
int n;
std::map<char, int> hsh;
int f(int a, char type, int b)
{
	if(type == '|')return (a|b);
	if(type == '&')return (a&b);
	if(type == '^')return (a^b);
}
int calc(int x, int X)
{
	stack<char> operand;
	stack<int> val;
	int cur1, cur2;
	char  exp;
	FOR(i,0,n)
	{
		if(s[i] == ')')
		{
			while(operand.top() != '(')
			{
				cur1 = val.top();
				val.pop();
				cur2 = val.top();
				val.pop();
				exp = operand.top();
				operand.pop();
				val.push(f(cur1, exp, cur2));
			}
			operand.pop();
		}
		else
		{
			if(hsh[s[i]] == 1)
			{
				operand.push(s[i]);
			}
			else
			{
				if(s[i] == 'x')val.push(x);
				else if(s[i] == 'X')val.push(X);
				else if(s[i] == '1')val.push(1);
				else if(s[i] == '0')val.push(0);
			}
		}
	}
	return val.top();
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, c1, c2, ans;
	 	cin >> t;
	 	hsh['('] = 1;
	 	hsh[')'] = 1;
	 	hsh['|'] = 1;
	 	hsh['&'] = 1;
	 	hsh['^'] = 1;
	 	hsh['x'] = 2;
	 	hsh['X'] = 2;
	 	hsh['1'] = 2;
	 	hsh['0'] = 2;
	 	FOR(z,1,t+1)
	 	{	
	 		cin >> s;
	 		n = s.length();
	 		c1 = calc(1,0);
	 		c2 = calc(0,1);
	 		if(c1 == c2)
	 		{
	 			cout<<"Case #"<<z<<": "<<0<<ln;
	 		}
	 		else
	 		{
	 			cout<<"Case #"<<z<<": "<<1<<ln;
	 		}
	 	}
		return 0;
}