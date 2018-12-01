#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
map<ll,ll> counter;
struct node{
	int size,amount,idx;
};
bool comp(node &x,node &y)
{
	if(x.amount==y.amount)return x.size<y.size;
	return x.amount>y.amount;
}
std::vector<node> v;
std::vector<int> table;
std::vector<int> pos[1002];
int assign[1002],last[1002];
std::vector<pii> ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,c,p,cur,r,k,aux;
	 	cin>>n;
	 	node tmp;
	 	FOR(i,0,n)
	 	{
	 		cin>>c>>p;
	 		tmp.size=c;
	 		tmp.amount=p;
	 		tmp.idx=i;
	 		v.pb(tmp);
	 	}
	 	sort(all(v),comp);
	 	cin>>k;
	 	FOR(i,0,k)
	 	{
	 		cin>>r;
	 		pos[r].pb(i);
	 		table.pb(r);
	 	}
	 	sort(all(table));
	 	int tot=0;
	 	trace(v,x)
	 	{
	 		cur=x.size;
	 		auto it=lower_bound(all(table),cur);
	 		if(it==table.end())continue;
	 		assign[x.idx]=*it;
	 		tot+=x.amount;
	 		table.erase(it);
	 	}
	 	cout<<k-sz(table)<<" "<<tot<<ln;
	 	FOR(i,0,n)
	 	{
	 		aux=assign[i];
	 		if(assign[i])
	 			ans.pb(mp(i+1,pos[aux][last[aux]++]));
	 	}
	 	trace(ans,x)cout<<x.F<<" "<<x.S+1<<ln;
		return 0;
}