#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <sstream>
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
char news[1002][1002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s = "", m;
	 	int co =0;
	 	std::string line;
  		std::getline(cin, line);
	 	std::istringstream iss(line);
	 	while(iss >> m)
	 	{
	 		s += m;
	 	}
	 	int len = s.length();
	 	int tmp = sqrt(len), f = 0;
		int l = tmp, r = tmp;
		debug(tmp);
	 	if(tmp * tmp < len)r++;
	 	FOR(i,0,l)
	 	{
	 		FOR(j,0,r)
	 		{
	 			if(i*r + j >= len)break;
	 			news[i][j] = s[i*r + j];
	 		}
	 	}
		FOR(j,0,r)
	 	{
	 		FOR(i,0,l)
	 		{
	 			if(i*r + j >= len)break;
	 			cout<<news[i][j];
	 		}
	 		cout<<" ";
	 	}
		return 0;
}