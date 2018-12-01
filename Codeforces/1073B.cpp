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
const int L=2e5+7;
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
int b[L],done[L],a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,tmp;
	 	cin >> n;
	 	stack <int> s;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 	}
	 	RFOR(i,n-1,0)s.push(a[i]);
	 	FOR(i,0,n)
	 	{
	 		cin >> b[i];
	 	}
	 	FOR(i,0,n)
	 	{
	 		if(done[b[i]])
	 		{
	 			cout<<"0 ";
	 			continue;
	 		}
	 		int co=0;
	 		while(1)
	 		{
	 			tmp = s.top();
	 			s.pop();
	 			co++;
	 			done[tmp] = 1;
	 			if(tmp == b[i])break;
	 		}
	 		cout<<co<<" ";
	 	}
		return 0;
}