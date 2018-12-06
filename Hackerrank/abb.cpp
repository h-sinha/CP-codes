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
const int L=1e3+7;
int len1, len2, f;
string a,b;
bool done[1002][1002];
void solve(int cur, int sofar)
{
	if(f)return;
	if(done[cur][sofar])return;
	if(sofar == -1)
	{
		RFOR(i,cur,0)
		{
			if(a[i]>=65 && a[i]<=90)return;
		}
		cout<<"YES\n";
		f=1;
		done[cur][sofar] = 1;
		return;
	}
	if(cur<0)return;
	done[cur][sofar] = 1;
	if(a[cur] == b[sofar])solve(cur-1, sofar-1);
	else
	{
		if(a[cur] >= 65 && a[cur]<=90 && a[cur]!=b[sofar])
		{
			return;
		}
		else if(a[cur]>=97 && a[cur]<=122 && char(a[cur]-32) == b[sofar])
		{
			solve(cur-1, sofar-1);
		}
		solve(cur-1, sofar);
	}
	return;
}	
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	cin >> t;
	 	while(t--)
	 	{
	 		f=0;
			FOR(i,0,len1)FOR(j,0,len2)done[i][j]=0;
	 		cin >> a;
	 		cin >> b;
	 		len1 = a.length();
	 		len2 = b.length();
	 		solve(len1-1,len2-1);
	 		if(!f)cout<<"NO\n";
	 	}
		return 0;
}