#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ld,ld>
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
ld X[100005],Y[100002],sign[1000002];
int f=0,n;
void solve(int i,ld sumx,ld sumy)
{
	if(i>n)
	{
		// printf("%Lf\n",sumx*sumx+sumy*sumy);
		if((sumy*sumy + sumx*sumx)<=2250000000000)f=1;
		return;
	}
	ld tmp1,tmp2,tmp3,tmp4;
	tmp1=abs(sumx+X[i]),tmp2=abs(sumy+Y[i]);
	tmp3=abs(sumx-X[i]),tmp4=abs(sumy-Y[i]);
	// cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<" "<<tmp4<<"-"<<X[i]<<ln;
	ld aux1=tmp1*tmp1+tmp2*tmp2;
	ld aux2=tmp3*tmp3+tmp4*tmp4;
	// cout<<aux1<<" "<<aux2<<ln;
	// printf("%Lf\n",aux1 );
	if(aux1<aux2)
	{
		sign[i]=1;
		solve(i+1,sumx+X[i],sumy+Y[i]);
	}
	else 
	{
		sign[i]=-1;
		solve(i+1,sumx-X[i],sumy-Y[i]);
	}

}
void solve1(int i,ld sumx,ld sumy)
{
	if(i<0)
	{
		if(sqrt(sumy*sumy + sumx*sumx)<=1500000)f=1;
		return;
	}
	ld tmp1,tmp2,tmp3,tmp4;
	tmp1=abs(sumx+X[i]),tmp2=abs(sumy+Y[i]);
	tmp3=abs(sumx-X[i]),tmp4=abs(sumy-Y[i]);
	ld aux1=(tmp1*tmp1+tmp2*tmp2);
	ld aux2=(tmp3*tmp3+tmp4*tmp4);
	// cout<<aux1<<" "<<aux2<<ln;
	// printf("%.0Lf\n",aux2 );
	if(aux1<=aux2)
	{
		sign[i]=1;
		solve1(i-1,sumx+X[i],sumy+Y[i]);
	}
	else 
	{
		sign[i]=-1;
		solve1(i-1,sumx-X[i],sumy-Y[i]);
	}

}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ld x,y;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>x>>y;
	 		X[i]=x,Y[i]=y;
	 	}

	 	solve(0,0,0);
	 	if(f)
	 	{
	 		FOR(i,0,n)cout<<sign[i]<<" ";
	 		return 0;
	 	}
	 	solve1(n-1,0,0);
	 	if(f)
	 	{
	 		FOR(i,0,n)cout<<sign[i]<<" ";
	 		return 0;
	 	}

		return 0;
}