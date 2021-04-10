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
const int L=1e6+7;
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
int xyx = 0;
ld a[L];
string s[L];
int len[L];
string get(string s, int r)
{
	int n = s.length();
	string ret;
	ll c = 1;
	RFOR(i,n-1,r)
	{
		c += (s[i] - '0');
		ret += to_string(c%10);
		c/=10;
	}
	while(c>0)
	{
		ret += to_string(c%10);
		c/=10;
	}
	reverse(all(ret));
	return ret;
}
void fff()
{
	xyx++;
	int n;
	cin >> n;
	ll num;
	FOR(i,0,n)
	{
		cin >> num;
		s[i] = to_string(num);
		len[i] = s[i].length();
		a[i] = num;
	}
	ll ans = 0,idx, xx, f = 0;
	string g;
	FOR(i,1,n)
	{
		if(a[i] <= a[i-1])
		{
			if(len[i] == len[i-1])
			{
				s[i] += "0";
				a[i] *= 10;
				len[i]++;
				ans++;
				continue;
			}
			xx= len[i];
			idx = -1, f = 0;
			FOR(j,0,xx)
			{
				if(s[i][j] > s[i-1][j])
				{
					idx = j;
					break;
				}
				else if(s[i][j] < s[i-1][j])
				{
					f = 1;
					break;
				}
			}
			if(idx == -1 && f == 0)
			{
				g = get(s[i-1], xx);
				if(g.length() > len[i-1]-len[i])
				{
					FOR(j,0,len[i-1]-xx+1)
					{
						a[i] *= 10;
						s[i] += "0";
						len[i]++;
						ans++;
					}
				}
				else
				{
					int co = 0;
					string ss = "";
					while(g.length()+co<len[i-1]-len[i])
					{
						co++;
						ss+="0";
					}
					// debug(ss,len[i-1],len[i],g);
					g = ss + g;
					ans+=g.length();
					s[i] += g;
					trace(g,x)
					{
						a[i] *= 10;
						a[i] += (x-'0');
						len[i]++;
					}
				}
			}
			else if(idx != -1)
			{
				FOR(j,0,len[i-1]-xx)
				{
					a[i] *= 10;
					s[i] += "0";
						len[i]++;
					ans++;
				}
			}
			else if(f)
			{
				FOR(j,0,len[i-1]-xx+1)
				{
					a[i] *= 10;
					s[i] += "0";
					len[i]++;
					ans++;
				}
			}
		}
	}
	cout << "Case #"<<xyx<<": "<<ans<<ln;
}
int main()
{
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
