#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
const int L=1e7+7;
std::vector<pii> v;
int ans[L],cost[10];
bool comp(pii x,pii y)
{
	if(x.F==y.F)return x.S>y.S;
	return x.F<y.F; 
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a,val,mn=INT_MAX,num;
	 	cin>>val;
	 	FOR(i,1,10)
	 	{
	 		cin>>cost[i];
	 		if(mn>cost[i])
	 		{
	 			mn=cost[i];
	 			num=i;
	 		}
	 	}
	 	if(val<mn){cout<<"-1";return 0;}
	 	int len=val/mn;
	 	FOR(i,0,len)ans[i]=num;
	 	val-=(len*mn);
	 	FOR(i,0,len)
	 	{
	 		RFOR(j,9,num+1)
	 		{
	 			if(val+mn-cost[j]>=0)
	 			{
	 				ans[i]=j;
	 				val=val+mn-cost[j];
	 				break;
	 			}
	 		}
	 	}
	 	FOR(i,0,len)cout<<ans[i];
		return 0;
}