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
int co[L], a[L];
void fff()
{
	int n;
	cin >> n;
	multiset<int>SET;
	set<int>aux;
	FOR(i,0,n)
	{
		cin >> a[i];
		co[a[i]]++;
		aux.insert(a[i]);
	}
	trace(aux,x)SET.insert(-co[x]);
	int q, x,c, f, s;
	char type;
	cin >> q;
	while(q--)
	{
		cin >> type;
		cin >> x;
		if(type == '+')
		{
			if(co[x])SET.erase(SET.find(-co[x]));
			co[x]++;
			SET.insert(-co[x]);
		}
		else
		{
			SET.erase(SET.find(-co[x]));
			co[x]--;
			if(co[x])SET.insert(-co[x]);
		}
		if(sz(SET)<2)
		{
			if(sz(SET)==1)
			{
				if(-*SET.begin()>=8)cout <<"YES\n";
				else cout <<"NO\n";
			}
			else cout <<"NO\n";
		}
		else
		{
			f = *SET.begin();
			SET.erase(SET.begin());
			s = *SET.begin();
			f = -f;
			s=-s;
			SET.erase(SET.begin());
			if(f >= 4 && f-4 >= 2 && s>=2)cout <<"YES\n";
			else if(f>=8|| (f>=4 && s>=4))cout <<"YES\n";
			else 
			{
				if(sz(SET))
				{
					c = *SET.begin();
					SET.erase(SET.begin());
					c = -c;
					if(f>=4 && (c>=4||(c>=2 && s>=2)))cout <<"YES\n";
					else cout <<"NO\n";
					SET.insert(-c);
				}
				else cout <<"NO\n";
			}
			SET.insert(-f);
			SET.insert(-s);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}