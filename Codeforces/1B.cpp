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
#define rall(c) c.rbegin(), c.rend()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
#define init(a, x) memset(a,x,sizeof(a))
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
bool check(string s)
{
	int f = 0;
	trace(s, x)
	{
		if(x >= '0' && x <= '9')f = 1;
		if(x >= 'A' && x <= 'Z')
		{
			if(f)return 1;
		}
	}
	return 0;
}
// 2->1
string s1(string s)
{
	string ans = "";
    string row = "";
    trace(s, x)
    {
    	if(x == 'C')break;
    	if(x == 'R')continue;
    	row += x;
    }
    int col=0, f = 0;
    trace(s, x)
    {
    	if(x == 'C')f = 1;
    	else if(f == 1) 
    	{
    		col *= 10;
    		col += (x- '0');
    	}
    }
    int tmp;
    string aux = "";
    while(col > 0)
    {     
        tmp = col%26;
       	tmp--;
       	if(tmp == -1)tmp += 26;
        aux += char(tmp + 'A');
        col=(col-1)/26;  
    }
    reverse(all(aux));
    ans += aux;
    ans += row;
    return ans;
}
// 1->2
string s2(string s)
{
	string ans = "R";
	ll c = 0, r = 0;
	int co = 0;
	trace(s, x)
	{
		if(x >= '0'&&x<='9')break;
		c*=26;
		c += (x-'A'+1);
		co++;
	}
	ans += s.substr(co);
	ans += "C";
	ans += to_string(c);
    return ans;
}
void fff()
{
	string s;
	cin >> s;
	if(check(s))cout << s1(s) << ln;
	else cout<<s2(s) << ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	return 0;
}