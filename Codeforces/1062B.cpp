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
const int L=1e6+7;
int lps[L];
void pre()
{
	lps[0] = lps[1] = 1;
	FOR(i,2,1000001)
	{
		if(lps[i])continue;
		for (int j = i; j < 1000001; j+=i)
		{
			lps[j] = i;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,mul=0, sqt=0, tmp, tmp1, co, ans = 0;
	 	cin >> n;
	 	ans = n;
	 	pre();
	 	if(n==1)
	 	{
	 		cout<<"1 0";
	 		return 0;
	 	}
	 	while(1)
	 	{
	 		// debug(n);
	 		if(ceil(sqrt(n)) == floor(sqrt(n)))
	 		{
	 			n = sqrt(n);
	 			ans = min(ans,n);
	 			// if(ans != n)break;
	 			sqt++;
	 		}
	 		else
	 		{
	 			tmp = n;
	 			co = 0;
	 			int mul1 = 0;
	 			// while(tmp%2==0)tmp/=2,co++;
	 			// if(co&1)n*=2, mul1=1;
	 			// tmp1 = sqrt(tmp);
	 			// for (int i = 3; i <= tmp; i+=2)
	 			// {
	 			// 	co = 0;
	 			// 	while(tmp%i==0)tmp/=i,co++;
	 			// 	if(co&1)n*=i, mul1=1;
	 			// }
	 			int au ;
	 			while(tmp>1)
	 			{
	 				au = lps[tmp];
	 				co = 0;
	 				while(tmp%au==0)tmp/=au,co++;
	 				if(co&1)n*=au, mul1=1;
	 			}

	 			if(n==ans*ans)break;
	 			mul =mul1;
	 		}
	 	}
	 	cout<<ans<<" "<<mul+sqt;
		return 0;
}