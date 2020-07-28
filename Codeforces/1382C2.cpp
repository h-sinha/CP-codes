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
int a[L], b[L];
void fff()
{
	int n;
	string s1,s2,tmp;	
	cin >> n;
	cin >> s1 >> s2;
	FOR(i,0,n)a[i]  =(s1[i]-'0');
	FOR(i,0,n)b[i]  =(s2[i]-'0');
	std::vector<int> v;
	int l=0,f = 0,r = n-1, idx = n-1;
	while(l!=r)
	{
		if((f&&1-a[r]==b[idx])||((!f)&&a[r]==b[idx]))
		{
			if(r<l)r++;
			else r--;
			idx--;
			continue;
		}
		// if(f)a[r] = 1-a[r];
		// debug(l,r,f,idx,a[l],a[r],b[idx]);
		if(a[l] == a[r])
		{
			v.pb(idx+1);
		}	
		else
		{
			v.pb(1);
			v.pb(idx+1);
			// if(f)a[l] = 1-a[l];
			a[l] = 1-a[l];
		}
		swap(l,r);
		// debug(a[0]);
		if(r<l)r++;
		else r--;
		f = 1-f;
		idx--;
	}
	if(f)a[r] = 1-a[r];
	if(a[r] != b[0])v.pb(1);
	cout << sz(v) <<" ";
	trace(v,x)cout << x<<" ";
	cout << ln;
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