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
map<ll,ll> counter;
char ch[30][30];
int dp[30][30];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int w,h,starty,startx,endy,endx;
struct node{
	int i,j,dist;
};
bool operator>(const node& a, const node& b)
{
    return (a.dist > b.dist);
}
void solve(int ix,int jx)
{
	FOR(i,1,h+1)FOR(j,1,w+1)dp[i][j]=INT_MAX;
	priority_queue<node,std::vector<node>,greater<node> > qq;
	node temp,temp1;
	dp[ix][jx]=0;
	temp.dist=0;
	dp[ix+1][jx]=dp[ix-1][jx]=dp[ix][jx+1]=dp[ix][jx-1]=0;
	temp.i=ix+1;
	temp.j=jx;
	temp.dist=0;
	qq.push(temp);
	temp.i=ix-1;
	temp.j=jx;
	temp.dist=0;
	qq.push(temp);
	temp.i=ix;
	temp.j=jx+1;
	temp.dist=0;
	qq.push(temp);
	temp.i=ix;
	temp.j=jx-1;
	temp.dist=0;
	qq.push(temp);
	int i,j;
	while(sz(qq))
	{
		// cout<<sz(qq)<<endl;
		temp=qq.top();
		// debug3(temp.i,temp.j,temp.dist);
		qq.pop();
		if(ch[temp.i][temp.j]=='D')return;
		// if(dp[temp.i][temp.j]<temp.dist)continue;
		if(ch[temp.i][temp.j]=='X' || temp.i<1 || temp.i>h || temp.j<1 || temp.j>w)continue;
		// debug2(ch[i][j],ch[i][j]-'0');
		i=temp.i,j=temp.j;
		if(ch[i+1][j]!='X' && ch[i+1][j]!='S')
		{
			if(dp[i+1][j]>temp.dist+(ch[i][j]-'0'))
			{
				dp[i+1][j]=min(dp[i+1][j],temp.dist+(ch[i][j]-'0'));
				temp1.i=i+1;
				temp1.j=j;
				temp1.dist=dp[i+1][j];
				qq.push(temp1);
			}
		}
		if(ch[i-1][j]!='X' && ch[i-1][j]!='S')
		{

			if(dp[i-1][j]>temp.dist+(ch[i][j]-'0'))
			{
				dp[i-1][j]=min(dp[i-1][j],temp.dist+(ch[i][j]-'0'));
				temp1.i=i-1;
				temp1.j=j;
				temp1.dist=dp[i-1][j];
				qq.push(temp1);
			}
		}
		if(ch[i][j+1]!='X' && ch[i][j+1]!='S')
		{

			if(dp[i][j+1]>temp.dist+(ch[i][j]-'0'))
			{
				dp[i][j+1]=min(dp[i][j+1],temp.dist+(ch[i][j]-'0'));
				temp1.i=i;
				temp1.j=j+1;
				temp1.dist=dp[i][j+1];
				qq.push(temp1);
			}
		}
		if(ch[i][j-1]!='X' && ch[i][j-1]!='S')
		{

			if(dp[i][j-1]>temp.dist+(ch[i][j]-'0'))
			{
				dp[i][j-1]=min(dp[i][j-1],temp.dist+(ch[i][j]-'0'));
				temp1.i=i;
				temp1.j=j-1;
				temp1.dist=dp[i][j-1];
				qq.push(temp1);
			}
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t=1;
		while(1)
		{
			cin>>w>>h;
			if(w==h && h==0)return 0;
			FOR(i,1,h+1)
			{
				FOR(j,1,w+1)
				{
					cin>>ch[i][j];
					if(ch[i][j]=='S'){starty=i;startx=j;}
					if(ch[i][j]=='D'){endx=i;endy=j;}
				}
			}
			solve(starty,startx);
			cout<<dp[endx][endy]<<ln;
		}
		return 0;
}