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
std::map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,k;
	 	cin>>n>>k;
	 	ll co=0;
	 	if(n<2)
	 	{
	 		if(k==0)cout<<"1";
	 		else cout<<"-1";
	 		return 0;
	 	}
	 	if(k<n/2){cout<<"-1";return 0;}
	 	ll cur=1;
	 	while(n-(co+2)>=2)
	 	{
	 		cout<<cur<<" "<<cur+1<<" ";
	 		counter[cur]++;
	 		counter[cur+1]++;
	 		co+=2;
	 		k-=1;
	 		cur+=2;
	 	}
	 	ll au=cur;
	 	cur=1;
	 	while(1)
	 	{
	 		if(counter[k*cur])
	 		{
	 			cur++;
	 		}
	 		else break;
	 	}
	 	cout<<k*cur<<" "<<k*(cur+1)<<" ";
	 	counter[k*cur]++;
	 	counter[k*(cur+1)]++;
	 	co+=2;
	 	if(n-co>0)
	 	{
	 		FOR(i,au,1000000001)
	 		{
	 			if(counter.find(i)==counter.end())
	 			{
	 				cout<<i;return 0;
	 			}
	 		}
	 	}
		return 0;
}