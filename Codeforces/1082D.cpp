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
int done[502], deg[502],a[502];
std::vector<int> v[502];
std::vector<int> alt;
int edges, diameter, n;
void addtoend(int vertex)
{
	FOR(i,1,n+1)
	{
	 	if(!done[i])
	 	{	
	 	 	deg[vertex]++, deg[i]++;
	 		done[i] = done[vertex] =  1;
	 		v[i].pb(vertex);
	 		edges++;
	 		diameter++;
	 		return;
	 	}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n;
	 	int cur = 0;
	 	FOR(i,1,n+1)
	 	{
	 		cin >> a[i];
	 		if(a[i] > 1)cur = i;
	 	}
	 	if(cur == 0)
	 	{
	 		cout<<"NO";
	 		return 0;
	 	}
	 	int tmp = cur, end1 = cur;
	 	alt.pb(cur);
	 	RFOR(i,cur-1,1)
	 	{
	 		if(a[i]>1)
	 		{
	 			alt.pb(i);
	 			v[cur].pb(i);
	 			deg[i]++, deg[cur]++;
	 			done[i] = done[cur] = 1;
	 			cur = i;
	 			edges++;
	 			diameter++;
	 		}
	 	}
	 	int end2 = cur;
	 	cur = sz(alt) - 1;
	 	
	 	if(deg[end1] < a[end1])
	 		addtoend(end1);
	 	if(deg[end2] < a[end2])
	 		addtoend(end2);
	 	FOR(i,1,n+1)
	 	{
	 		if(!done[i])
	 		{
	 			if(deg[alt[cur]] < a[alt[cur]])
	 			{
	 				v[alt[cur]].pb(i);
	 				done[alt[cur]] = done[i] = 1;
	 				deg[alt[cur]]++, deg[i]++;
	 				edges++;
	 			}
	 			else
	 			{	
	 				while(cur >= 0 && deg[alt[cur]] >= a[alt[cur]])cur--;
	 				if(cur<0)
	 				{
	 					cout<<"NO";
	 					return 0;
	 				}
	 				v[alt[cur]].pb(i);
	 				done[alt[cur]] = done[i] = 1;
	 				deg[alt[cur]]++, deg[i]++;
	 				edges++;
	 			}
	 		}
	 	}
	 	cout<<"YES "<<diameter<<ln;
	 	cout<<edges<<ln;
	 	FOR(i,1,n+1)trace(v[i], x)cout<<i<<" "<<x<<ln;
		return 0;
}