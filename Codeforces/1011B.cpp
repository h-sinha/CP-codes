#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
int n,m;
int counter[100002],a[10002];
set<int>SET;
bool check(int val)
{	
	// set<pii>aux;
	// revpr aux;
	priority_queue<pii>aux;
	pii tmp;
	// cout<<val<<" -> ";
	for(auto&x:SET)aux.push( mp(counter[x],x));
	FOR(i,0,n)
	{
		tmp = aux.top();
		// cout<<tmp.first<<ln;
		if(tmp.first <val)return 0;
		// aux.erase(aux.begin());
		aux.pop();
		aux.push( mp(tmp.first-val,tmp.second));
	}
	return 1;
}
void ser()
{
	int l=0,r=1e6,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	cout<<r;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin >> n>> m;
	 	FOR(i,0,m){cin>>a[i];counter[a[i]]++;SET.insert(a[i]);}
	 	ser();
		return 0;
}