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
bool check(string s, string c,string ns)
{
	int n=s.length();
	int m=c.length();
	int co = 0;
	FOR(i,0,n)
	{
		if(s[i] != ns[i])co++;
	}
	if(co > 2)return 0;
	FOR(i,0,min(n,m))
	{
		if(s[i] < c[i])return 1;
		if(s[i] == c[i])continue;
		else return 0;
	}
	if(n < m)return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string s, c;
	int n, m;
	int tt = t, cc = 0;
	while(t--)
	{
		cin >> s >> c;
		n=s.length();
		m=c.length();
		std::vector<int> co(30), co1(30);
		FOR(i,0,n)co[s[i]-'A']++;
		int nn = min(n, m);
		int f = 0;
		cc++;
		string ns = s;
		if(n<m)
		{
			if(s == c.substr(0,n))
			{
				cout<<s<<ln;
				continue;
			}
		}
		FOR(i,0,nn)
		{
			if(f)break;
			co[s[i]-'A']--;
			if(s[i] < c[i])
			{
				f = 1;
				break;
			}
			else if(s[i] == c[i])
			{
				int idx = -1;
				FOR(j,0,s[i]-'A')
				{
					if(co[j] > 0)
					{
						idx = j;
						break;
					}
				}
				if(idx == -1)continue;
				RFOR(j,n-1,i+1)
				{
					if(s[j]-'A' == idx)
					{
						swap(s[i],s[j]);
						f = 1;
						break;
					}
				}
			}
			else
			{
				int idx = -1;
				FOR(j,0,(c[i]-'A')+1)
				{
					if(co[j] > 0)
					{
						idx = j;
						break;
					}
				}
				if(idx == -1)break;
				RFOR(j,n-1,i+1)
				{
					if(s[j]-'A' == idx)
					{
						swap(s[i],s[j]);
						f = 1;
						break;
					}
				}
				// if(idx == c[i]-'A')f = 0;
			}
		// debug(i,s,c);
		}
		if(check(s,c,ns))cout<<s<<ln;
		else cout<<"---\n";
	}
	return 0;
}