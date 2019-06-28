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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int ctr[L][3];
string compress(string s, int f)
{
	string o = "";
	o += s[0];
	int len = s.length(), co = 1;
	FOR(i,0,len)ctr[i][f] = 0;
	int cur = 0;
	FOR(i,1,len)
	{
		if(s[i] != s[i-1])
		{
			ctr[cur][f] = co;
			o += s[i];
			co = 0;
			cur++;
		}
		co++;
	}
	ctr[cur][f] = co;
	return o;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	string s,t;
	 	while(n--)
	 	{
	 		cin >> s;
	 		cin >> t;
	 		string c1 = compress(s,0);
	 		string c2 = compress(t,1);
	 		int no = 0;
	 		if(c1 == c2)
	 		{
	 			int len = c1.length();
	 			FOR(i,0,len)
	 			{
	 				if(ctr[i][1]<ctr[i][0])no = 1;
	 			}
	 			if(no)cout<<"NO\n";
	 			else cout<<"YES\n";
	 		}
	 		else
	 		{
	 			cout<<"NO\n";
	 		}
	 	}
		return 0;
}