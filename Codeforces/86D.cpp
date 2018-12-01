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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=2e5+7;
ll out[L],a[L],counter[1000001],szs=900;
struct node
{
	ll l,r,q;
};
bool comp(node x, node y)
{
	ll xx=x.l/szs,yy=y.l/szs;
	if(xx==yy)return x.r<y.r;
	return x.l<y.l;
}
ll ans=0;
void add(int idx) 
{
	counter[a[idx]]++;
	ans += ((counter[a[idx]])*(counter[a[idx]])*a[idx] - (counter[a[idx]] - 1)*(counter[a[idx]] - 1)*a[idx]);
}

void remove(int idx) 
{
	counter[a[idx]]-- ;
	ans += ((counter[a[idx]])*(counter[a[idx]])*a[idx] - (counter[a[idx]] + 1)*(counter[a[idx]] + 1)*a[idx]);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int curl,curr,n,m,cur=0,l,r,b,k;
	 	cin>>n>>m;
	 	FOR(i,0,n)
	 		cin>>a[i];
	 	std::vector<node> v(m);
	 	node temp;
	 	FOR(i,0,m)
		{
			cin>>l>>r;
			l--,r--;
			v[i].l=l,v[i].r=r,v[i].q=i;
		}
		sort(all(v),comp);
		l=0,r=-1;
		FOR(i,0,m)
		{
			curl=v[i].l,curr=v[i].r;
			while(r<curr)
			{
				++r;
				// cout<<r<<endl;
				add(r);
			}
			while(r>curr)
			{
				// cout<<"2 "<<r<<endl;
				remove(r);
				--r;
			}
			while(l<curl)
			{
				// cout<<"3 "<<l<<endl;
				remove(l);
				l++;
			}
			while(l>curl)
			{
				--l;
				// cout<<"4 "<<l<<endl;
				add(l);
			}
			// cout<<l<<" - "<<r<<endl;
			out[v[i].q]=ans;
		}
		FOR(i,0,m)cout<<out[i]<<ln;
		return 0;
}