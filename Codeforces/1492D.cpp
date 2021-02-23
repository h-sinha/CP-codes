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
#define eb emplace_back
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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
string ss;
ll a, b, k;
bool get(string s1, string s2)
{
	ss = "";
    int s = 0;         
    int i = s1.size() - 1, j = s2.size() - 1; 
    while (i >= 0 || j >= 0 || s == 1) 
    { 
        s += ((i >= 0)? s1[i] - '0': 0); 
        s += ((j >= 0)? s2[j] - '0': 0); 
        ss += char(s % 2 + '0'); 
        s /= 2; 
        i--; j--; 
    } 
    reverse(all(ss));
    int co1 = 0, co2 = 0;
    trace(ss, x)
    {
    	if(x == '0')co2++;
    	else co1++;
    }
    return (co1 == b && co2 == a);
}
bool comp(string s1, string s2)
{
	int n = sz(s1);
	if(sz(s2) != n)
	{
		cout << "No\n";
		exit(0);
	}
	FOR(i,0,n)
	{
		if(s1[i] < s2[i])return 1;
	}
	return 0;
}
void fff()
{
	cin >> a >> b >> k;
	ll n = a + b;
	string s1 = "1", s2 = "1";
	if(k == 0)
	{
		cout << "Yes\n";
		FOR(i,0,b)cout << "1";
		FOR(i,0,a)cout << "0";
		cout << ln;
		FOR(i,0,b)cout << "1";
		FOR(i,0,a)cout << "0";
		cout << ln;
		return;
	}
	FOR(i,0,a)s1 += "0";
	FOR(i,0,b-1)s1 += "1";
	string s3(k,'1');
	FOR(i,0,b-1-k)s3 += "0";
	// debug(s1,s3);
	if(get(s1, s3))
	{
		cout << "Yes\n";
		if(comp(s1, ss))swap(s1, ss);
		cout << s1 << ln;
		cout << ss << ln;
	}
	else cout << "No\n";

}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	// int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}