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
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
typedef long int ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const ll L=1e6+7;
map<pii,ll> counter;
struct node
{
	ll a, b, c;
};
struct comp
{
	bool operator ()(node x, node y)
	{
		if(x.a != y.a)
		return x.a < y.a;
		if(x.b != y.b)
		return x.b < y.b;
		return x.c < y.c;
	}
};
set<node, comp>SET;
void insertset(ll x1,ll y1, ll x2, ll y2)
{

	node temp;
	temp.a = y2 - y1; 
	temp.b = x1 - x2; 
	temp.c  = temp.a*(-x1) + temp.b*(-y1);
	ll gc = __gcd(__gcd(abs(temp.a), abs(temp.b)), temp.c);
	temp.a/=gc;
	temp.b/=gc;
	temp.c/=gc;
	if(temp.a < 0)
	{
		temp.a = -temp.a;
		temp.b = -temp.b;
		temp.c = -temp.c;
	}
	if(temp.a == 0)
	{
		if(temp.b <0)
		{
			temp.b = -temp.b;
			temp.c = -temp.c;
		}
	}
	SET.insert(temp);
	return;
}
ll x[L], y[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n, determinant;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> x[i]>>y[i];
	 	}
	 	FOR(i,0,n)
	 	{
	 		FOR(j,0,n)
	 		{
	 			if(i == j)continue;
	 			insertset(x[i] ,y[i], x[j], y[j]);
	 		}
	 	}
	 	set<node>::iterator it, it1;
	 	std::vector<node> v;
	 	ll tot = sz(SET);
	 	trace(SET,x)
	 	{
	 		counter[mp(x.a, x.b)]++;
	 	}
	 	ll co = 0;
	 	trace(counter,x)
	 	{
	 		co += ((tot - x.S) * x.S); 
	 	}
	 	cout<<co/2;
		return 0;
}