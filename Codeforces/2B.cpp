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
#define debug3(x,y,z,w) cout<<x<<"-->"<<y<<"-->"<<z<<"-->"<<w<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
struct node{
	int flag,x,y,five,two;
};
node dp[1002][1002],arr[1002][1002];
int inp[1002][1002],n,dp1[1002][1002];
node aux;
node solve(int i,int j)
{
	if(i<1||i>n||j<0||j>n)return aux;
	// if(dp[i][j].flag==1)return dp[i][j];
	if(i==n && j==n)
	{
		node temp;
		temp.five=arr[i][j].five;
		temp.two=arr[i][j].two;
		temp.x=n,temp.y=n;
		temp.flag=1;
		dp[i][j]=temp;
		return dp[i][j];
	}
	node q1=solve(i+1,j);
	node q2=solve(i,j+1);
	ll temp=0;
	q1.two+=arr[i][j].two;
	q1.five+=arr[i][j].five;
	q2.two+=arr[i][j].two;
	q2.five+=arr[i][j].five;
	// cout<<i<<" "<<j<<" "<<q1.five<<" "<<q1.two<<" "<<q2.five<<" "<<q2.two<<endl;
	if(min(q1.five,q1.two)>min(q2.five,q2.two) && min(dp[i][j].five,dp[i][j].two)>min(q2.five,q2.two))
	{
		q2.flag=1;
		q2.x=i;
		q2.y=j+1;
		dp[i][j]=q2;
		return dp[i][j];
	}
	else if(min(q1.five,q1.two)<min(q2.five,q2.two) && min(dp[i][j].five,dp[i][j].two)>min(q1.five,q1.two))
	{
		q1.flag=1;
		q1.x=i+1;
		q1.y=j;	
		dp[i][j]=q1;
		return dp[i][j];
	}
	else if(min(q1.five,q1.two)==min(q2.five,q2.two) && min(dp[i][j].five,dp[i][j].two)>min(q1.five,q1.two))
	{
		q1.flag=1;
		q1.x=i+1;
		q1.y=j;	
		q2.flag=1;
		q2.x=i+1;
		q2.y=j;	
		if(q2.five>q1.five || q2.two>q1.two)
		dp[i][j]=q2;
		else dp[i][j]=q1;
		return dp[i][j];
	}
	// cout<<i<<" "<<j<<" "<<dp[i][j].five<<endl;
	return dp[i][j];

}
node mini(int i,int j)
{
	if(i<1||i>n||j<0||j>n)return aux;
	if(i==n && j==n)
	{
		node temp;
		temp.five=inp[i][j];
		temp.two=arr[i][j].two;
		temp.x=n,temp.y=n;
		temp.flag=1;
		dp[i][j]=temp;
		return dp[i][j];
	}
	if(dp[i][j].flag==1)return dp[i][j];
	node q1,q2;
	// dp[i][j].five=min(mini(i+1,j),mini(i,j+1))+inp[i][j];
	q1=mini(i+1,j);
	q2=mini(i,j+1);
	if(q1.five<q2.five)
	{
		q1.flag=1;
		q1.x=i+1;
		q1.y=j;
		dp[i][j]=q1;
	}
	else
	{
		q2.flag=1;
		q2.x=i;
		q2.y=j+1;
		dp[i][j]=q2;
	}
	return dp[i][j];	
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	int co=0,temp;
	 	cin.tie(NULL);
	 	cin>>n;
	 	aux.five=1e6;
	 	aux.two=1e6;

	 	FOR(i,1,1002)
	 	{
	 		FOR(j,0,1002)
	 		{
	 			dp[i][j].x=i;
	 			dp[i][j].y=j;
	 			dp[i][j].five=1e6;
	 			dp[i][j].two=1e6;
	 			dp[i][j].flag=0;
	 		}
	 	}
	 	FOR(i,1,n+1)FOR(j,1,n+1)cin>>inp[i][j];
	 	FOR(i,1,n+1)
	 	{
	 		FOR(j,1,n+1)
	 		{
	 			temp=inp[i][j],co=0;
	 			while(temp%5==0 && temp>0){co++;temp/=5;}
	 			arr[i][j].five=co;co=0,temp=inp[i][j];
	 			while(temp%2==0 && temp>0){co++;temp/=2;}
	 			arr[i][j].two=co;co=0,temp=inp[i][j];
	 			// cout<<inp[i][j]<<" "<<arr[i][j].five<<" "<<arr[i][j].two<<ln;
	 		}
	 	}
	 	solve(1,1);
	 	// cout<<"ba"<<endl;
	 	FOR(i,1,n+1)FOR(j,1,n+1){inp[i][j]=min(dp[i][j].two,dp[i][j].five);cout<<i<<" "<<j<<" "<<inp[i][j]<<endl;}
	 	// FOR(i,1,n+1)FOR(j,1,n+1)cout<<i<<" "<<j<<" "<<dp[i][j].five<<endl;
	 	FOR(i,1,1002)
	 	{
	 		FOR(j,0,1002)
	 		{
	 			dp[i][j].x=i;
	 			dp[i][j].y=j;
	 			dp[i][j].five=1e6;
	 			dp[i][j].two=1e6;
	 			dp[i][j].flag=0;
	 		}
	 	}
	 	mini(1,1);
	 	cout<<inp[1][1]<<ln;
	 	int i=1,j=1,auxi,auxj;
	 // 	while(1)
		// {
		// 	if(dp[i][j].x>i)cout<<"D";
		// 	else cout<<"R";
		// 	auxi=i,auxj=j;
		// 	i=dp[i][j].x;
		// 	j=dp[auxi][auxj].y;
		// 	if(i==n && j==n)break;
		// }
	 	// debug2(dp[1][1].two,dp[1][1].five);
		// cout<<n<<" "<<n;
		return 0;
}