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
#define eb emplace_back
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
typedef	priority_queue<int,std::vector<int>,greater<int> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=2e5+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m=1e9+7)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll a[L], m = 1e9 + 7;
set<pii> SET[L];
map<int, int> co[L];
ll spf[L];
void pre() 
{ 
    spf[1] = 1; 
    for (int i=2; i<200001; i++) 
        spf[i] = i; 
    for (int i=4; i<200001; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<200001; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<200001; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
ll g=0;
int n;
void prime(int i, ll x)
{
	vector<int> ret;
	int y = 0, c = 0, tmp, aux;
    while (x != 1) 
    { 
    	y = spf[x];
    	c = 0;
    	while(x!= 1 && spf[x] == y)x/=y, c++;
    	if(co[i].find(y) == co[i].end())
    	{
    		co[i][y] += c;
    		SET[y].insert({c,i});
    		if(sz(SET[y]) == n)
    		{
    			g = (g * fastexpo(y, (*SET[y].begin()).F))%m;
    		}
    	}
    	else
    	{
    		tmp = co[i][y];
    		if(!SET[y].empty())aux = (*SET[y].begin()).F;
    		else aux = -1;
    		SET[y].erase({tmp, i});
    		co[i][y] += c;
    		tmp += c;
    		SET[y].insert({tmp, i});
    		if(aux == -1)
    		{
    			if(sz(SET[y]) == n)
	    		{
	    			g = (g * fastexpo(y, c))%m;
	    		}
    		}
    		else if((*SET[y].begin()).F > aux && sz(SET[y]) == n)
    		{
    			c = (*SET[y].begin()).F - aux;
    			g = (g * fastexpo(y, c))%m;
    		}
    	}
    } 
    return; 
}
void fff()
{
	int q, x, idx;
	cin >> n >> q;
	g = 1;
	FOR(i,0,200001)
	{
		SET[i].clear();
		co[i].clear();
	}
	FOR(i,1,n+1)
	{
		cin >> a[i];
		prime(i, a[i]);
	}
	while(q--)
	{
		cin >> idx >> x;
		prime(idx, x);
		cout << g << ln;
	}	
}
int main()
{
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	pre();
	//int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}