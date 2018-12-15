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
const int L=3e3+7;
int n, m, x, t, a[L], b[L], done[L], p[L], idx, op;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n >> m;
	 	FOR(i,1,2*n+1)
	 		cin >> p[i];
	 	FOR(i,0,m)
	 		cin >> a[i] >> b[i];
	 	cin >> t;
	 	FOR(j,0,n)
	 	{
	 		idx = -1;
	 		if(t == 1)
	 		{
		 		FOR(i,0,m)
		 		{
		 			if(done[a[i]] || done[b[i]])continue;
		 			if(p[a[i]] > p[b[i]])idx = a[i];
		 			else idx = b[i];
		 			break;
		 		}
		 		if(idx == -1)
		 		{
		 			FOR(i,1,2*n+1)
		 			{
		 				if(!done[i])
		 				{
		 					idx = i;
		 					break;
		 				}
		 			}
		 			FOR(i,1,2*n+1)
		 			{
		 				if(done[i])continue;
		 				if(p[i] > p[idx])idx = i;
		 			}
		 		}
		 		cout << idx << endl;
		 		fflush(stdout);
		 		cin >> op;
		 		done[idx] = done[op] = 1;
		 	}
		 	else
		 	{
		 		cin >> op;
		 		done[op] = 1;
		 		FOR(i,0,m)
		 		{
		 			// if(done[a[i]] || done[b[i]])continue;
		 			if(a[i] == op && !done[b[i]])
		 			{
		 				idx = b[i];
		 				break;
		 			}
		 			else if(b[i] == op && !done[a[i]])
		 			{
		 				idx = a[i];
		 				break;
		 			}
		 		}
		 		if(idx == -1)
		 		{
		 			FOR(i,0,m)
			 		{
			 			if(done[a[i]] || done[b[i]])continue;
			 			if(p[a[i]] > p[b[i]])idx = a[i];
			 			else idx = b[i];
			 			done[a[i]] = done[b[i]] =1;
			 			break;
			 		}
		 		}
		 		if(idx == -1)
		 		{
		 			FOR(i,1,2*n+1)
		 			{
		 				if(!done[i])
		 				{
		 					idx = i;
		 					break;
		 				}
		 			}
		 			FOR(i,1,2*n+1)
		 			{
		 				if(done[i])continue;
		 				if(p[i] > p[idx])idx = i;
		 			}
		 		}
		 		cout << idx << endl;
		 		fflush(stdout);
		 		done[idx] = 1;done[op] = 1;
		 	}
		 }
		return 0;
}