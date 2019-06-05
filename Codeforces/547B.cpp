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

const int L=2e5+7;
std::vector<int> v[L];
int a[L], nxt[L], prv[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,0,n)cin >> a[i];
	 	stack<int>num;
	 	stack<int>pos;
	 	multiset<int>SET;
		RFOR(i,n-1,0)
		{
			SET.insert(a[i]);
			if(num.empty())
			{
				num.push(a[i]);
				pos.push(i);
				nxt[i] = n;
				continue;
			}
			while(!num.empty() && num.top() >= a[i])
			{
				num.pop();
				pos.pop();
			}
			if(num.empty())
			{
				num.push(a[i]);
				pos.push(i);
				nxt[i] = n;
			}
			else
			{
				nxt[i] = pos.top();
				num.push(a[i]);
				pos.push(i);
			}
		}
		while(!num.empty())
		{
			num.pop();
			pos.pop();
		}
		FOR(i,0,n)
		{
			if(num.empty())
			{
				num.push(a[i]);
				pos.push(i);
				prv[i] = -1;
				continue;
			}
			while(!num.empty() && num.top() >= a[i])
			{
				num.pop();
				pos.pop();
			}
			if(num.empty())
			{
				num.push(a[i]);
				pos.push(i);
				prv[i] = -1;
			}
			else
			{
				prv[i] = pos.top();
				num.push(a[i]);
				pos.push(i);
			}
		}
		FOR(i,0,n)v[nxt[i] - prv[i] - 1].pb(a[i]);
		FOR(i,1,n+1)
		{
			cout<<*SET.rbegin()<<" ";
			trace(v[i],x)SET.erase(SET.find(x));
		}
		return 0;
}
