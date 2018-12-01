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
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
std::vector<int> ans;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a1,a2,a3,a4;
	 	cin >> a1 >> a2 >> a3 >> a4;
	 	if(abs(a3-a4)>1)
	 	{
	 		cout<<"-1";
	 		return 0;
	 	}

int flag=0;
	 	if(a3==a4)
	 	{
	 		int cur=0,f;
	 		while(a3>0)
	 		{
	 			ans.pb(4);
	 			ans.pb(7);
	 			f=cur+1;
	 			cur+=2;
	 			a3--,a1--,a2--;
	 		}
	 		// cout<<a1<<ln;
	 		if(a1>0)
	 		{
	 			ans.pb(4);
	 			a1--;
	 		}
	 		else {flag=1;a2--;}
	 		if(a1<0 || a2<0)
	 		{
	 			cout<<"-1";return 0;
	 		}
	 		while(a1>0){cout<<"4";a1--;}
	 		int au=0;
	 		if(flag)
	 		cout<<"7";
	 		trace(ans,x)
	 		{
	 			if(f==au)
	 			{
	 				while(a2>0)
	 				{
	 					cout<<"7";
	 					a2--;
	 				}
	 			}
	 			cout<<x;
	 			au++;
	 		}
	 	}

	 	else if(a3>a4)
	 	{
	 		a4-=(a3-1);
	 		while(a3>0)
	 		{
	 			ans.pb(4);
	 			ans.pb(7);
	 			a1--,a2--;
	 			a3--;
	 		}
	 		// cout<<a1<<" - "<<a2<<" "<<a3<<" "<<a4<<ln;
	 		if(a1==0 && a2==0 && a3==0 && a4==0)
	 		{
	 			trace(ans,x)cout<<x;
	 			return 0;
	 		}
	 		while(a2>0)
	 		{
	 			ans.pb(7);
	 			a2--;
	 		}
	 		if(a2<0 || a1<0)
	 		{
	 			cout<<"-1";
	 			return 0;
	 		}
	 		while(a1>0)
	 		{
	 			cout<<"4";
	 			a1--;
	 		}
	 		trace(ans,x)cout<<x;
	 	}
	 	else
	 	{
	 		int cur=0,au=0;
	 		while(a4>0)
	 		{
	 			au=cur;
	 			cur+=2;
	 			ans.pb(7);
	 			ans.pb(4);
	 			a1--,a2--;
	 			a4--;
	 		}
	 		if(a1==0 && a2==0 && a3==0 && a4==0)
	 		{
	 			trace(ans,x)cout<<x;
	 			return 0;
	 		}
	 		
	 		if(a2<0 || a1<0)
	 		{
	 			cout<<"-1";
	 			return 0;
	 		}
	 		int f=0;
	 		int co=0;
	 		trace(ans,x)
	 		{
	 			if(co==au)
	 			{
	 				while(a2>0)
	 				{
	 					cout<<"7";
	 					a2--;
	 				}
	 			}
	 			co++;
	 			if(!f && x==4)
	 			{
	 				while(a1>0)
	 				{
	 					cout<<"4";
	 					a1--;
	 				}
	 				f=1;
	 			}
	 			cout<<x;
	 		}
	 	}
		return 0;
}