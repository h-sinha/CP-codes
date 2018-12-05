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
const int L=3e5+7;
int nxt[L], prv[L], a[L];
set<int> v[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, tmp;
	 	cin >> n;
	 	FOR(i,0,n)cin >> a[i];
	 	stack<int>s;
	 	FOR(i,0,n)
	 	{
	 		while(!s.empty())
	 		{
	 			tmp = s.top();
	 			if(a[i] % a[tmp] == 0)break;
	 			nxt[tmp] = i-1;
	 			s.pop();
	 		}
	 		s.push(i);
	 	}
	 	while(!s.empty())
	 	{
	 		tmp = s.top();
	 		nxt[tmp] = n-1;
	 		s.pop();
	 	}

	 	RFOR(i,n-1,0)
	 	{
	 		while(!s.empty())
	 		{
	 			tmp = s.top();
	 			if(a[i] % a[tmp] == 0)break;
	 			prv[tmp] = i+1;
	 			s.pop();
	 		}
	 		s.push(i);
	 	}
	 	while(!s.empty())
	 	{
	 		tmp = s.top();
	 		prv[tmp] = 0;
	 		s.pop();
	 	}
	 	int mx = 0;
	 	FOR(i,0,n)
	 	{
	 		// debug(i,nxt[i],prv[i]);
	 		v[nxt[i] - prv[i]].insert(prv[i]+1);
	 		mx = max(mx, nxt[i] - prv[i]);
	 	}
	 	cout<<sz(v[mx])<<" "<<mx<<ln;
	 	trace(v[mx], x)cout<<x<<" ";
		return 0;
}