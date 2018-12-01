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
int x[5],y[5],X[5],Y[5],c[6],m[5],xmin=INT_MAX,xmax=INT_MIN,Xmax=INT_MIN,Xmin=INT_MAX,ymin=INT_MAX,ymax=INT_MIN,Ymax=INT_MIN,Ymin=INT_MAX;
bool check(int i,int j)
{
	// cout<<xmin<<" "<<xmax<<" "<<ymin<<" "<<ymax<<ln;
	if(i>=xmin && i<=xmax && j<=ymax && j>=ymin)return 1;
	return 0;
}
bool check1(int xx,int yy)
{
	int t1,t2,t3;
	FOR(i,0,2)
	{
		t1=c[i];
		t2=c[i+2];
		t3=yy-m[i]*xx;
		// cout<<t1<<" "<<t2<<ln;
		if(t3<min(t1,t2) || t3>max(t1,t2))return 0;
	}
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	FOR(i,0,4)
	 	{
	 		cin>>x[i]>>y[i];
	 		xmin=min(xmin,x[i]);
	 		xmax=max(xmax,x[i]);
	 		ymin=min(ymin,y[i]);
	 		ymax=max(ymax,y[i]);
	 	}
	 	FOR(i,0,4)
	 	{
	 		cin>>X[i]>>Y[i];
	 		Xmin=min(Xmin,X[i]);
	 		Xmax=max(Xmax,X[i]);
	 		Ymin=min(Ymin,Y[i]);
	 		Ymax=max(Ymax,Y[i]);

	 	}
	 	FOR(i,0,3)
	 	{
	 		m[i]=(Y[i+1]-Y[i])/(X[i+1]-X[i]);
	 		c[i]=Y[i]-m[i]*X[i];
	 	}
	 	m[3]=(Y[0]-Y[3])/(X[0]-X[3]);
	 	c[3]=Y[3]-m[3]*X[3];
	 	FOR(i,-100,101)
	 	{
	 		FOR(j,-100,101)
	 		{
	 			// cout<<check(i,j)<<" "<<check1(i,j)<<ln;
	 			if(check(i,j) && check1(i,j))
	 			{
	 				// cout<<i<<" "<<j<<ln;
	 				cout<<"YES\n";
	 				return 0;
	 			}
	 		}
	 	}
	 	cout<<"NO\n";
	 	return 0;
		return 0;
}