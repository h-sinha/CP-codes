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
int n;
std::vector<int> ans[L];
string s;
void solve(int mid, int i)
{
	int cur;
	int r = n-1, l = mid - 1, carry = 0;
	while(r>=mid && l>=0)
	{
		cur = (s[r] - '0' + s[l] - '0' + carry);
		r--,l--;
		ans[i].pb(cur%10);
		carry = (cur/10);
	}
	while(r>=mid)
	{
		cur = s[r] - '0' + carry;
		ans[i].pb(cur % 10);
		carry = cur/10;
		r--;
	}
	while(l>=0)
	{
		cur = s[l] - '0' + carry;
		ans[i].pb(cur % 10);
		carry = cur/10;
		l--;
	}
	// debug(i,carry,sz(ans[i]));
	while(carry > 0)
	{
		ans[i].pb(carry % 10);
		carry /= 10;
	}
}
int check()
{
	int id1 = -1, id2 = -1;
	FOR(i,n/2+1,n)
	{
		if(s[i] != '0')
		{
			id1 = i;
			solve(id1, 0);
			break;
		}
	}
	RFOR(i,n/2-1,1)
	{
		if(s[i] != '0')
		{
			id2 = i;
			solve(id2, 1);
			break;
		}
	}
	if(id1 == -1)
	{
		return 1;
	}
	else if(id2 == -1)
	{
		return 0;
	}
	else
	{
		if(sz(ans[0]) < sz(ans[1]))return 0;
		else if(sz(ans[0]) > sz(ans[1]))return 1;
		else
		{
			RFOR(i,sz(ans[0]) - 1, 0)
			{
				if(ans[0][i] < ans[1][i])
				{
					return 0;
				}
				if(ans[0][i] > ans[1][i])
				{
					return 1;
				}
			}
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
		cin >> s;
		if(n==1)
		{
			cout<<s;
			return 0;
		}
		int mid, id = 0;
		if(n%2 == 0)
		{
			if(n==2)
			{
				id = 2;
				solve(n/2, 2);
			}
			else if(s[n/2] != '0')
			{
				solve(n/2, 2);
				id = check();
				if(sz(ans[id]) > sz(ans[2]))id = 2;
				else if(sz(ans[id]) == sz(ans[2]))
				{
					RFOR(i,sz(ans[id])-1,0)
					{
						if(ans[id][i] == ans[2][i])
							continue;
						else if(ans[id][i] > ans[2][i])
							id = 2;
						else break;
					}
				}
			}
			else
			{
				id = check();
			}
		}
		else
		{
			solve(n/2, 2);
			id = check();
			if(s[n/2]!='0' && sz(ans[id]) > sz(ans[2]))id = 2;
			else if(s[n/2] != '0' && sz(ans[id]) == sz(ans[2]))
			{
				RFOR(i,sz(ans[id])-1,0)
				{
					if(ans[id][i] == ans[2][i])
						continue;
					else if(ans[id][i] > ans[2][i])
						id = 2;
					else break;
				}
			}
		}
		RFOR(i,sz(ans[id])-1,0)cout<<ans[id][i];
		return 0;
}