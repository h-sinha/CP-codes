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
typedef long long ll;
typedef long double ld;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,temp,y1,x1,dx,dy;
	 	ll p[1002],slopy,slopx;
	 	int f=0;
	 	cin>>n;
	 	FOR(i,1,n+1)cin>>p[i];
	 	dy=p[3]-p[2];
	 	dx=1;
	 	// cout<<dy<<ln;
	 	std::vector<ll> vx;
	 	std::vector<ll> vy;
	 	FOR(i,3,n)
	 	{
	 		y1=p[i+1]-p[i];
			x1=1;
			temp=__gcd(y1,x1);
			y1/=temp;
			x1/=temp;
			// debug1(y1);
			if(y1!=dy || x1!=dx){f=1;break;}	
	 	}
	 	if(!f)
	 	{
	 		slopy=p[2]-p[1];
	 		// cout<<"as";
	 		if(slopy!=dy)
	 		{cout<<"Yes";return 0;}
	 	}
		FOR(i,2,n+1)
		{
			std::vector<bool> mark(1002,0);
			mark[1]=1;
			dy=p[i]-p[1];
			dx=i-1;
			// debug2(dy,dx);
			temp=__gcd(dy,dx);
			dy/=temp;
			dx/=temp;
			mark[i]=1;
			// cout<<i<<ln;
			// cout<<"dd"<<i<<ln;
			// debug2(dy,dx);
			// cout<<ln;
			FOR(j,2,n+1)
			{
				if(i==j)continue;
				y1=p[j]-p[1];
				x1=j-1;
				temp=__gcd(y1,x1);
				if(temp!=0)
				{
					y1/=temp;
					x1/=temp;
					// debug2(y1,x1);
				}
				if(y1==dy && x1==dx)mark[j]=1;
			}
			FOR(j,2,n+1)
				if(!mark[j])vx.pb(j),vy.pb(p[j]);
				// cout<<sz(vx);
			if(sz(vx)==1){cout<<"Yes";return 0;}
			if(!sz(vx))continue;
			f=0;
			slopy=dy,slopx=dx;
			dy=vy[1]-vy[0];
			dx=vx[1]-vx[0];
			temp=__gcd(dy,dx);
			dy/=temp;dx/=temp;
			// cout<<"sa";
		// debug2(dy,dx);
		// cout<<ln;
			FOR(j,1,sz(vx)-1)
			{
				y1=vy[j+1]-vy[j];
				x1=vx[j+1]-vx[j];
				temp=__gcd(y1,x1);
				// cout<<y1<<" "<<x1<<ln;
				// debug2(y1,x1);
				if(temp!=0)
				{
					y1/=temp;
					x1/=temp;
				}
				if(y1!=dy || x1!=dx){f=1;break;}
			}
			if(!f)
			{
				// cout<<slopx<<" "<<slopy<<" "<<dx<<" "<<dy<<endl;
				if(slopx==dx && slopy==dy)
				{
					// cout<<"as";
					cout<<"Yes";return 0;
				}
			}
			vx.clear();
			vy.clear();
			// mark.clear();
		}
		cout<<"No";
		return 0;
}