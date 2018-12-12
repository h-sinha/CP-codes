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
map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, x, cur=1, ans = 0;
	 	cin >> n;
	 	set<int>SET;
	 	stack<int>s;
	 	string str;
	 	FOR(i,0,2*n)
	 	{
	 		cin >> str;
	 		if(str.compare("add") == 0)
	 		{
	 			cin >> x;
	 			s.push(x);
	 		}
	 		else
	 		{
	 			if(!s.empty() && s.top() == cur){s.pop();cur++;continue;}
	 			if(!s.empty())ans++;
	 			while(!s.empty())
	 			{
	 				SET.insert(s.top());
	 				s.pop();
	 			}
	 			SET.erase(cur++);
	 		}
	 	}
	 	cout<<ans;
		return 0;
}