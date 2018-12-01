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
typedef priority_queue<ll,std::vector<ll>,greater<ll> > revpr;

map<ll,ll> counter;
int p[100002],c[100002];
struct node{
	ll power,cost,index;
};
std::vector<node> v;
bool cmp(const node &x,const node &y)
{
	// if(x.power==y.power)
	return x.power<y.power;
}
std::vector<ll> ans(100002);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,k;
	 	ll temp;
	 	cin>>n>>k;
	 	FOR(i,0,n)cin>>p[i];
	 	FOR(i,0,n)cin>>c[i];
	 	FOR(i,0,n)
	 	{
	 		node temp;
	 		temp.power=p[i];
	 		temp.cost=c[i];
	 		temp.index=i;
	 		v.pb(temp);
	 	}
	 	sort(all(v),cmp);
	 	ll sofar=0,mini=INT_MAX;
	 	// set<ll>SET;
	 	revpr SET;
	 	FOR(i,0,n)
	 	{
	 		if(i<k)
	 		{
	 			ans[v[i].index]=sofar;
	 			// mini=min(mini,v[i].cosst);
	 			SET.push(v[i].cost);
	 			sofar+=v[i].cost;
	 		}
	 		else 
	 		{
	 			ans[v[i].index]=sofar;
	 			if(sz(SET))
	 			temp=SET.top();
	 			else temp=INT_MAX;
	 			if(temp<v[i].cost)
	 			{
	 				SET.pop();
	 				SET.push(v[i].cost);
	 				sofar+=v[i].cost;
	 				sofar-=temp;
	 			}
	 		}
	 	}
	 	FOR(i,0,n)cout<<ans[i]+c[i]<<" ";
		return 0;
}