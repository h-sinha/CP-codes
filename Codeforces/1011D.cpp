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
int flag[32];
int main()
{
		ll n,m,l,r,mid,val,cur=0,prev;
		cin>>m>>n;
		l=1,r=m;
		FOR(i,0,n)
		{
			cout<<"1"<<endl;
			fflush(stdout);
			cin>>val;
			if(val==0)return 0;
			if(val < 0)flag[i] = 0;
			else flag[i] = 1;
		}		
		l=1,r=m;
		while(1)
		{
			mid=(l+r)/2;
			cout<<mid<<endl;
			fflush(stdout);
			cin>>val;
			if(val==-2 || val==0)return 0;
			if(flag[cur])
			{
				if(val==-1)r=mid-1;
				else l=mid+1;
			}
			else
			{
				if(val==-1)l=mid+1;
				else r=mid-1;
			}
			cur++;
			if(cur>=n)cur=0;
		}
		return 0;
}