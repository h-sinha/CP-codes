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
struct node{
	int type, length;
	char ch;
};
ll x[100002],y[100002];
std::vector<pii> v;
std::vector<node> ans;
bool comp(pii x,pii y)
{
	ll x1=abs(x.F-0),y1=abs(x.S-0), x2=abs(y.F-0),y2=abs(y.S-0);
	if(x1==x2)
		return y1<y2;
	else if(y1==y2)
		return x1<x2;
	else
		return y1<y2;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n;
		ll mov=0,curx,cury;
		cin>>n;
		FOR(i,0,n)
		{
			cin>>x[i]>>y[i];
			v.pb( mp(x[i],y[i]) );
		}	 	
		node temp;
		sort(all(v),comp);
		// FOR(i,0,n)cout<<v[i].F<<" "<<v[i].S<<ln;
		FOR(i,0,n)
		{
			curx=v[i].F,cury=v[i].S;
			// cout<<curx<<" - "<<cury<<ln;
			mov=abs(cury-0);
			if(mov!=0)
			{
				temp.type=1;
				temp.length=mov;
				if(cury<0)temp.ch='D';
				else temp.ch='U';
				ans.pb(temp);
			}
			mov=abs(curx-0);
			if(mov!=0)
			{
				temp.type=1;
				temp.length=mov;
				if(curx>0)temp.ch='R';
				else temp.ch='L';
				ans.pb(temp);
			}
			temp.type=2,temp.length=-1,temp.ch='X';
			ans.pb(temp);
			mov=abs(curx-0);
			if(mov!=0)
			{
				temp.type=1;
				temp.length=mov;
				if(curx>0)temp.ch='L';
				else temp.ch='R';
				ans.pb(temp);
			}
			mov=abs(cury-0);
			if(mov!=0)
			{
				temp.type=1;
				temp.length=mov;
				if(cury<0)temp.ch='U';
				else temp.ch='D';
				ans.pb(temp);
			}
			
			temp.type=3,temp.length=-1,temp.ch='X';
			ans.pb(temp);
		}
		cout<<sz(ans)<<ln;
		trace(ans,x)
		{
			if(x.type==1)
				cout<<x.type<<" "<<x.length<<" "<<x.ch<<ln;
			else cout<<x.type<<ln;
		}
		return 0;
}