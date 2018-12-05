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
const int L=5e7+7;
map<ll,ll> counter;
bool isprime[L];
std::vector<int> ans;
void sieve()
{
	isprime[1] = 1;
	isprime[0] = 1;
	for (int j = 4; j <= 10000000; j+=2)isprime[j] = 1;
	for (int i = 3; i <= 10000000; i+=2)
	{
		if(isprime[i])continue;
		for (int j = 2*i; j <= 10000000; j+=i)
		{
			isprime[j] = 1;
		}
	}
}
bool check(ll n)
{
	if(n<=10000000)return !isprime[n];
	ll tmp = sqrt(n);
	for(ll i=2;i<=tmp;++i)
	{
		if(n%i==0)return 0;
	}
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n;
	 	cin >> n;
	 	sieve();
	 	if(n==3)cout<<"1\n3";
	 	else if(n==4)cout<<"2\n2 2";
	 	else
	 	{
	 		if(check(n))
	 		{
	 			cout<<"1\n"<<n;
	 			return 0;
	 		}
	 		n-=3;
	 		ans.pb(3);
	 		for (int i = 3; i <n ; i+=2)
	 		{
	 			if(check(i) && check(n-i))
	 			{
	 				ans.pb(i);
	 				ans.pb(n-i);
	 				break;
	 			}
	 		}
	 		cout<<sz(ans)<<ln;
	 		trace(ans,x)cout<<x<<" ";
	 	}


		return 0;
}