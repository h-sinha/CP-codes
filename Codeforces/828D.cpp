#include<bits/stdc++.h>
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
const ll L=1e5+7;
int n, kval;
void printans(ll val)
{
	FOR(i,1,val+1)cout<<i<<" "<<i+1<<ln;
	int cur = val+2;
	// if(cur>=n)return;
	int nodes = val-1;
	int mx = (nodes+1)/2;
	int mid = mx + 1;
	int internal = n - val + 1 - kval;
	while(internal > 0)
	{
		int co = 0, prev = mid;
		while(internal > 0 && co < mx)
		{
			cout<<prev<<" "<<cur<<ln;
			prev = cur;
			cur++;
			co++;
			if(co!=mx)internal--;
			if(internal == 0)
			{
				cout<<prev<<" "<<cur<<ln;
				cur++;
			}
		}
	}
	while(cur<=n)
	{
		cout<<2<<" "<<cur<<ln;
		cur++;
	}
}
bool check(ll val)
{
	ll k = kval - 2;
	int internal = n - val + 1  - kval;
	if(internal <= 0)return 1;
	int nodes = val-1;
	ll mx;
	mx = (nodes+1)/2;
	if(k*(mx-1)>=internal)return 1;
	return 0;
}
void ser()
{
	ll l=1,r=n-1,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else l=mid;
	}
	if(!check(r))r=l;
	cout<<r<<ln;
	printans(r);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>kval;
	 	ser();
		return 0;
}