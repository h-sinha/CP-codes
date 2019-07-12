#include <bits/stdc++.h>
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
int a[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	FOR(i,0,n)cin >> a[i];
	int l = 0, r = n -1, prv = -1;
	std::vector<int> ans;
	std::vector<char> out;
	int f = 0;
	if(a[0] < a[n-1])
	{
		ans.pb(a[l]);
		prv = a[l];
		out.pb('L');
		l++;
	}
	else
	{
		ans.pb(a[r]);
		out.pb('R');
		prv = a[r];
		r--;
		if(a[0] == a[n-1])f = 1;
	}
	while(l<=r)
	{
		if(a[l] > prv && a[r] > prv)
		{
			if(a[l] < a[r])
			{
				out.pb('L');
				ans.pb(a[l]);
				prv = a[l];
				l++;
			}
			else
			{
				out.pb('R');
				ans.pb(a[r]);
				prv = a[r];
				if(a[l] == a[r])f = 1;
				r--;
			}
		}
		else if(a[l]>prv)
		{
			out.pb('L');
			ans.pb(a[l]);
			prv = a[l];
			l++;
		}
		else if(a[r] > prv)
		{
			out.pb('R');
			ans.pb(a[r]);
			prv = a[r];
			r--;
		}
		else
		{
			break;
		}
	}
	std::vector<char> out1;
	std::vector<int> ans1;
	if(f)
	{
		int l = 0, r = n-1, prv = -1;
		while(l<=r)
		{
			if(a[l] > prv && a[r] > prv)
			{
				if(a[l] < a[r])
				{
					out1.pb('L');
					ans1.pb(a[l]);
					prv = a[l];
					l++;
				}
				else if(a[l] > a[r])
				{
					out1.pb('R');
					ans1.pb(a[r]);
					prv = a[r];
					r--;
				}
				else
				{
					out1.pb('L');
					ans1.pb(a[l]);
					prv = a[l];
					l++;
				}
			}
			else if(a[l]>prv)
			{
				out1.pb('L');
				ans1.pb(a[l]);
				prv = a[l];
				l++;
			}
			else if(a[r] > prv)
			{
				out1.pb('R');
				ans1.pb(a[r]);
				prv = a[r];
				r--;
			}
			else
			{
				break;
			}
		}
	}
	if(sz(ans) > sz(ans1))
	{
		cout<<sz(ans)<<ln;
		trace(out,x)cout<<x;
	}
	else
	{
		cout<<sz(ans1)<<ln;
		trace(out1,x)cout<<x;	
	}
	return 0;
}