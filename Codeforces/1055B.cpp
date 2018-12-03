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
const int L=1e5+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,l,ans = 0,p,d;
	 	int f=0,type;
	 	cin >> n >> m >> l;
	 	FOR(i,0,n)cin >> a[i];
		if(a[0] > l)f=1,ans++;
		FOR(i,1,n)
		{
			if(a[i]>l && f==0)f=1,ans++;
			else if(a[i]<=l)f=0;
		}
		while(m--)
		{
			cin >> type;
			if(!type)cout<<ans<<ln;
			else 
			{
				cin >> p >> d;
				if(n==1)
				{
					a[p-1]+=d;
					if(a[0]>l)ans=1;
					else ans=0;
					continue;
				}
				p--;
				if(p==0)
				{
					if(a[p]>l || (a[p]<=l && a[p]+d<=l) || (a[p+1]>l && a[p]+d>l))a[p]+=d;
					else if(a[p]<=l && a[p]+d >l && a[p+1]<=l)ans++,a[p]+=d;
				}
				else if (p==n-1)
				{
					if(a[p]>l || (a[p]<=l && a[p]+d<=l) || (a[p-1]>l && a[p]+d>l))a[p]+=d;
					else if(a[p]<=l && a[p]+d >l && a[p-1]<=l)ans++,a[p]+=d;
				}
				else
				{
					if(a[p-1]<=l && a[p+1]<=l)
					{
						if(a[p]+d>l && a[p]<=l)ans++;
						a[p]+=d;
					}
					else if((a[p-1]<=l && a[p+1]>l) || (a[p-1]>l && a[p+1]<=l))
					{
						a[p]+=d;
					}
					else if(a[p-1]>l && a[p+1]>l)
					{
						if(a[p]+d>l && a[p]<=l)ans--;
						a[p]+=d;
					}
				}
			}
		}
		return 0;
}