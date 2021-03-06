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
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)
const int L=1e2+7;
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
int h, m;
int reflection[10];
int get(int x)
{
	int rev = 0;
	int y;
	int f = 0;
	if(x < 10)f = 1;
	while(x > 0)
	{
		y = x%10;
		if(reflection[y] == -1)return INT_MAX;
		rev *= 10;
		rev += reflection[y];
		x /= 10;
	}
	if(f)return rev * 10;
	return rev;
}
void pre(int hh, int mm)
{
	int x, y;
	FOR(j,mm,m)
	{
			x = get(hh);
			if(x > m)continue;
			y = get(j);
			if(x < m && y < h)
			{
				if(hh<10)cout << 0;
				cout << hh<<":";
				if(j<10)cout << 0;
				cout << j<<"\n";
				return;
			}
	}
	FOR(i,hh+1,h)
	{
		FOR(j,0,m)
		{
			x = get(i);
			if(x > m)continue;
			y = get(j);
			if(x < m && y < h)
			{
				if(i<10)cout << 0;
				cout << i<<":";
				if(j<10)cout << 0;
				cout << j<<"\n";
				return;
			}
		}
	}
	FOR(i,0,hh)
	{
		FOR(j,0,m)
		{
			x = get(i);
			if(x > m)continue;
			y = get(j);
			if(x < m && y < h)
			{
				if(i<10)cout << 0;
				cout << i<<":";
				if(j<10)cout << 0;
				cout << j<<"\n";
				return;
			}
		}

	}
	FOR(j,0,mm)
	{
			x = get(hh);
			if(x > m)continue;
			y = get(j);
			if(x < m && y < h)
			{
				if(hh<10)cout << 0;
				cout << hh<<":";
				if(j<10)cout << 0;
				cout << j<<"\n";
				return;
			}
	}
}
void fff()
{
	cin >> h >> m;
	string s;
	cin >> s;
	int hh = stoi(s.substr(0,2));
	int mm = stoi(s.substr(3,2));
	pre(hh, mm);
}
int main()
{
	reflection[0] = 0;
	reflection[1] = 1;
	reflection[2] = 5;
	reflection[3] = -1;
	reflection[4] = -1;
	reflection[5] = 2;
	reflection[6] = -1;
	reflection[7] = -1;
	reflection[8] = 8;
	reflection[9] = -1;
	#ifdef LOCAL_EXEC
		freopen("in.txt", "r", stdin);
	 	freopen("out.txt", "w", stdout);
	#else	
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	int t;cin >> t;while(t--)
	fff();
	#endif
	return 0;
}