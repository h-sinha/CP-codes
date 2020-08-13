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
map<ll,ll> counter;
void fff()
{
	ll r, g, b, w;
	cin >> r >> g >> b >> w;
	ll n = (r+g+b+w);
	if(n&1)
	{
		if(w&1)
		{
				if((r&1)||(g&1)||(b&1))
				{
					if(min(r,min(g,b)) == 0)cout << "No\n";
					else
					{
						r--, g--, b--;
						w += 3;
						// debug(r,g,b,w);
						if((r%2==0)&&(g%2==0)&&(b%2==0))cout <<"No\n";
						else cout <<"Yes\n";
					}
				}
				else cout <<"Yes\n";
		}
		else
		{
			if((r&1)||(g&1)||(b&1))
			{
				int co = 0;
				if(r&1)co++;
				if(g&1)co++;
				if(b&1)co++;
				if(co  == 1)
				{
					cout <<"Yes\n";return;
				}
				if(min(r,min(g,b)) == 0)cout << "No\n";
				else
				{
					r--, g--, b--;
					w += 3;
					if((r&1)||(g&1)||(b&1))cout <<"No\n";
					else cout <<"Yes\n";
				}
			}
			else
			{
				cout <<"No\n";
			}

		}
	}
	else
	{
		if(w&1)
		{
			if(min(r,min(g,b)) == 0)cout << "No\n";
			else
			{
				r--;g--;b--;
				if((r&1)||(g&1)||(b&1))cout <<"No\n";
				else cout <<"Yes\n";
			}
		}
		else
		{
			if((r&1)||(g&1)||(b&1))cout <<"No\n";
			else cout <<"Yes\n";
		}
	}
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