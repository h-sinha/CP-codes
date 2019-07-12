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
const int M=27;
int co[L][M], cur_co[M];
bool check(int val)
{
	FOR(i,0,26)
		if(co[val][i] < cur_co[i])
			return 0;
	return 1;
}
void ser(int n)
{
	int l=0,r=n-1,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else l=mid;
	}
	while(check(r))r--;
	cout<<r+2<<ln;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	int n, m, len;
	 	cin >> n;
	 	cin >> s;
	 	FOR(i,0,n)co[i][s[i]-'a']++;
	 	FOR(i,1,n+1)FOR(j,0,26)co[i][j] += co[i-1][j];
	 	cin >> m;
	 	while(m--)
	 	{
			cin >> s;
			len = s.length();
			FOR(i,0,26)cur_co[i] = 0;
			FOR(i,0,len)cur_co[s[i]-'a']++;
			ser(n);	 		
	 	}
		return 0;
}