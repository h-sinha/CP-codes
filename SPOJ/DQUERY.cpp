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
const int L=1e6+7;
int out[L],counter[L],ans=0,a[L];
struct node
{
	int l, r, q;
};
bool comp(node x, node y)
{
	if(x.l/900 == y.l/900)return x.r<y.r;
	return x.l/900 < y.l/900;
}
void add(int idx)
{
	counter[a[idx]]++;
	if(counter[a[idx]]==1)ans++;
}
void remove(int idx)
{
	counter[a[idx]]--;
	if(counter[a[idx]]==0)ans--;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,q;
		cin>>n;
		FOR(i,0,n)cin>>a[i];
		cin>>q;
		std::vector<node> v(q);
		FOR(i,0,q)
		{
			cin>>v[i].l>>v[i].r;
			v[i].l--,v[i].r--;
			v[i].q=i;
		}
		sort(all(v),comp);
		int l=0,r=-1;
		trace(v,x)
		{
			while(r<x.r)add(++r);
			while(r>x.r)remove(r--);
			while(l<x.l)remove(l++);
			while(l>x.l)add(--l);
			out[x.q]=ans;
		}
		FOR(i,0,q)cout<<out[i]<<ln;
		return 0;
}