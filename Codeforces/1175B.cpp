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
set<int>SET;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	int t;
	 	ll n, ans= 0, tmp;
	 	cin >> t;
	 	stack<ll>st;
	 	stack<ll>pos;
	 	stack<ll>rem;
	 	int f = 0, f1 = 0;
	 	ll cur = 1, t1;
	 	ll mx = ll(pow(2,32)) - 1;
	 	FOR(i,0,t)
	 	{
	 		cin >> s;
	 		if(f)continue;
	 		if(s=="end")
	 		{
	 			tmp = st.top();
	 			t1 = pos.top();
	 			if(!f1)
	 			cur/=tmp;
	 			if(f1 && pos.top() == rem.top()) 
	 			{
	 				rem.pop();
	 				if(rem.empty())f1 = 0;
	 			}
	 			st.pop();
	 			pos.pop();

	 		}
	 		else if(s=="add")
	 		{
	 			if(f1 || ans > mx-cur)
	 			{
	 				f = 1;
	 				continue;
	 			}
	 			ans += cur;
	 		}
	 		else
	 		{
	 			cin >> n;
	 			if(f1)
	 			{
	 				st.push(n);
	 				pos.push(i);
	 				continue;
	 			}
	 			if(cur*n > mx)
	 			{
	 				f1 = 1;
	 				rem.push(i);
	 				st.push(n);
	 				pos.push(i);
	 				continue;

	 			}
	 			st.push(n);
	 			pos.push(i);
	 			cur*=n;
	 		} 
	 		if(ans > mx)
	 		{
	 			f=1;
	 		}
	 	}
	 	if(f)
	 	{
	 		cout<<"OVERFLOW!!!";
	 		return 0;
	 	}
	 	cout<<ans;
		return 0;
}