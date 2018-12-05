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
std::vector<int> a,b;
ll power[L];
void pre()
{
	power[0] = 1;
	FOR(i,1,31)power[i] = power[i-1]*2;
}
int main()
{
		ll val1=0,val2=0,o1,o2,cur;
		pre();
		cout<<"? 0 0\n";
		fflush(stdout);
		cin >> cur;
		RFOR(i,29,0)
		{
			cout<<"? "<<(val1|power[i])<<" "<<val2<<endl;
			fflush(stdout);
			cin >> o1;
			cout<<"? "<<val1<<" "<<(val2|power[i])<<endl;
			fflush(stdout);
			cin >> o2;
			if(o1 == o2)
			{
				if(cur == 1)
					val1 = val1 | power[i];
				else
					val2 = val2 | power[i];

				cur = o1;

			}
			else if(o1 == -1) 
			{
				val1 = val1 | power[i];
				val2 = val2 | power[i];
			}
			
		}
		cout<<"! "<<val1<<" "<<val2;
		fflush(stdout);
		return 0;
}