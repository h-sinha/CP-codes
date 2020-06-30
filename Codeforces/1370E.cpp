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
map<ll,ll> counter;
int visit[L], co[2], co1[2];
void fff()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	s += s;
	t += t;
	n += n;
	trace(s,x)
	{
		co[x-'0']++;
	}
	trace(t,x)
	{
		co1[x-'0']++;
	}
	if((co[0] != co1[0]) || (co[1] != co1[1]))
	{
		cout<<"-1\n";
		return;
	}
	set<int>s1,s2;
	FOR(i,0,n)
	{
		if(s[i] == '0' && (s[i] != t[i]))s1.insert(i);
		else if(s[i] == '1' && (s[i] != t[i]))s2.insert(i);
	}
	int idx, f, pi;
	int ans = 0, an = n/2;
	set<int>::iterator it;
	FOR(i,0,n)
	{
		if(s[i] == t[i])continue;
		idx = i;
		if(s[i] == '0')f = 0, s1.erase(i);
		else f = 1, s2.erase(i);
		pi = idx;
		std::vector<int> v;
		v.pb(idx);	
		int ff = 0;
		// debug(s,t,i);
		int l = INT_MAX, r = INT_MIN;
		while(idx<n)
		{
			// debug(idx,f);
			if(f == 0)
			{
				it = s2.upper_bound(idx);
				if(it == s2.end())
				{
					break;
				}
				idx = *it;
				// debug(l,r,idx);
				if(idx%an>=l&&idx%an<=r)break;
				if(sz(v) && (idx)%an<=v[0])break;
				v.pb(*it);
				l = min(l,(idx)%an);
				r = max(r,idx%an);
				f = 1-f;
			}
			else
			{
				it = s1.upper_bound(idx);
				if(it == s1.end())
				{
					break;
				}
				idx = *it;
				// debug(l,r,idx);
				if(idx%an>=l&&idx%an<=r)break;
				if(sz(v) && (idx)%an<=v[0])break;
				v.pb(*it);
				l = min(l,(idx)%an);
				r = max(r,idx%an);
				f = 1-f;
			}
		}
		int xx = sz(v);
		if(sz(v)&1)xx--;
		FOR(j,0,xx)
		{
			s[v[j]] = t[v[j]];
			s[(v[j]+an)%n] = t[(v[j]+an)%n];
			if(s1.find(v[j]) != s1.end())s1.erase(v[j]);
			if(s2.find(v[j]) != s2.end())s2.erase(v[j]);
			if(s1.find((v[j]+an)%n) != s1.end())s1.erase((v[j]+an)%n);
			if(s2.find((v[j]+an)%n) != s2.end())s2.erase((v[j]+an)%n);
		}
		// trace(v,x)cout<<x<<" - ";
		// cout<<ln;
		ans++;
	}
	cout<<ans<<ln;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//int t;cin >> t;while(t--)
	fff();
	return 0;
}