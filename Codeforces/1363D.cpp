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
#define pii pair<int,int>
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
set<int> v[L];
int c[L];
map<pii,int>co;
int get(int l, int r)
{
	if(l>r)return -1;
	int x;
	cout<<"? "<<r-l+1<<" ";
	FOR(i,l,r+1)cout<<i<<" ";
	cout<<endl;
	fflush(stdout);
	cin >> x;
	co[{l,r}] = x;
	fflush(stdout);	
	return x;
}
void fff()
{
	co.clear();
	int n, k,x;
	cin >> n >> k;
	FOR(i,0,k)v[i].clear();
	FOR(i,0,k)
	{
		cin >> c[i];
		FOR(j,0,c[i])
		{
			cin >> x;
			v[i].insert(x);
		}
	}
	int xx = get(1,n), x1, x2;
	co[{1,n}] = xx;
	int l = 1, r = n,mid;
	while(l<r)
	{
		mid = (l+r)/2;
		if(co.find({l,mid}) != co.end())x1 = co[{l,mid}];
		else x1 = get(l,mid);
		if(x1 == xx)r = mid;
		else l = mid+1;
	}
	FOR(i,0,k)
	{
		if(v[i].find(r) != v[i].end())
		{
			cout<<"? "<<n-sz(v[i])<<" ";
			FOR(j,1,n+1)if(v[i].find(j)==v[i].end())cout<<j<<" ";
			cout<<endl;
			fflush(stdout);
			cin >> x1;
			cout<<"! ";
			FOR(j,0,k)
			{
				if(j == i)cout<<x1<<" ";
				else cout<<xx<<" ";
			}
			cout<<endl;
			fflush(stdout);
			string s;
			cin >> s;
			fflush(stdout);
			return;
		}
	}
	cout<<"! ";
	FOR(i,0,k)cout<<xx<<" ";
	cout<<endl;
	fflush(stdout);
	string s;
	cin >> s;
	fflush(stdout);
	return;
}
int main()
{
	int t;cin >> t;while(t--)
	fff();
	return 0;
}