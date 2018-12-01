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
int counter[20],au[20];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int sumis=0,n,a;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a;
	 		sumis+=a;
	 		counter[a]++;
	 		au[a]++;
	 	}
	 	if(counter[0]==0){cout<<"-1\n";return 0;}
	 	au[0]--;
	 	counter[0]--;
	 	RFOR(i,9,0)
	 	{
	 		while(counter[i]>0)
	 		{
	 			sumis = (sumis+i)%3;
	 			counter[i]--;
	 		}
	 	}
	 	if(sumis==2)
	 	{
	 		int f=0;
	 		FOR(i,0,10)
	 		{
	 			if(au[i]>0 && i%3==1)
	 			{
	 				au[i]--;
	 				f=1;
	 				break;
	 			}
	 		}
	 		if(!f)
	 		{
		 		FOR(i,0,10)
		 		{
		 			if(au[i]>0 && i%3==2)
		 			{
		 				au[i]--;
		 				if(au[i]>0)
		 				{
		 					au[i]--;
		 					f=1;
		 					break;
		 				}

		 			}
		 		}
		 	}
	 	}
	 	else if(sumis==1)
	 	{
	 		int f=0;
	 		FOR(i,0,10)
	 		{
	 			if(au[i]>0 && i%3==2)
	 			{
	 				au[i]--;
	 				f=1;
	 				break;
	 			}
	 		}
	 		if(!f)
	 		{
		 		FOR(i,0,10)
		 		{
		 			if(au[i]>0 && i%3==1)
		 			{
		 				au[i]--;
		 				if(au[i]>0)
		 				{
		 					au[i]--;
		 					f=1;
		 					break;
		 				}

		 			}
		 		}
		 	}
	 	}
	 	int f=0;
	 	RFOR(i,9,1)if(au[i])f=1;
	 	if(!f){cout<<"0";return 0;}
	 	RFOR(i,9,0)
		{
		 	while(au[i]>0)
		 	{
		 		cout<<i;
		 		au[i]--;
		 	}
		 }
		 cout<<"0";
		return 0;
}