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
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a,n;
	 	ll arr[2000];
	 	while(1)
	 	{
	 		cin>>n;
	 		if(!n)return 0;
	 		stack<ll>s1;
	 		stack<ll>s2;
	 		int pos[1002],temp,f=1,cur=1;
	 		FOR(i,0,n){cin>>arr[i];}
	 		RFOR(i,n-1,0){s1.push(arr[i]);pos[arr[i]]=1;}
	 		while(cur<=n)
	 		{
	 			// cout<<cur<<endl;
	 			if(pos[cur]==1)
	 			{
	 				while(s1.top()!=cur)
	 				{
	 					temp=s1.top();
	 					s1.pop();
	 					s2.push(temp);
	 					pos[temp]=2;
	 				}
	 				// cout<<s1.top()<<endl;
	 				s1.pop();
	 				cur++;
	 			}
	 			else 
	 			{
	 				if(s2.top()!=cur)
	 				{
	 					f=0;
	 					cout<<"no"<<ln;
	 					break;
	 				}
	 				else 
	 				{
	 					s2.pop();
	 					cur++;
	 				}
	 			}
	 		}
	 		if(f)cout<<"yes"<<ln;

	 	}
		return 0;
}
