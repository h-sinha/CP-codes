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
int l[L],r[L],done[L],ans[L],lll[L],rr[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> l[i];
	 	}
	 	int idx=-1;
	 	FOR(i,0,n)cin >> r[i];
		int co=0;
		int cur=n;
		FOR(i,0,n)
		{
			lll[i] = l[i];
			rr[i]=r[i];
		}
		while(co<n)
		{
			
			std::vector<int> v;
			FOR(i,0,n)
			{
				// cout<<l[i]<<" "<<r[i]<<" "<<n<<ln;
				if(l[i]==r[i] && r[i]==0 && !done[i]){v.pb(i);done[i]=1;}
			}
			trace(v,idx)
			{
					done[idx]=1;
					ans[idx]=cur;
					// cout<<cur<<ln;
					FOR(i,0,idx)
					{
						if(done[i])continue;
						r[i]-=1;
					}
					FOR(i,idx+1,n)
					{
						if(l[i]==0 && r[i]==0)continue;
						l[i]-=1;
					}
					co++;
			}
			if(co<n && sz(v)==0)
			{
				cout<<"NO";
				return 0;
			}
			cur--;
			v.clear();
		}
		int cc=0;
		// FOR(i,0,n)debug(i,ans[i]);
		FOR(i,0,n)
		{
			cc = 0;
			FOR(j,0,i)
			{
				if(ans[i] < ans[j])cc++;
			}
			if(cc != lll[i])
			{
				// debug(i,cc,lll[i]);
				cout<<"NO";
				return 0;
			}
			cc=0;
			FOR(j,i+1,n)
			{
				if(ans[i]<ans[j])cc++;
			}
			if(cc!=rr[i])
			{
				cout<<i<<cc<<" "<<r[i];
				cout<<"NO";
				return 0;
			}

		}
		cout<<"YES\n";
		FOR(i,0,n)cout<<ans[i]<<" ";
		return 0;
}