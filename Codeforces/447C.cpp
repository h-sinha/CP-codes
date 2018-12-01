#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,int>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
typedef long long ll;
typedef long double ld;
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
bool comp(pii t1,pii t2)
{
	if(t1.F==t2.F)return t1.S<t2.S;
	return t1.F<t2.F;
}
std::vector<pii> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a;
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a;
	 		v.pb(mp(a,i));
	 	}
	 	sort(v.begin(), v.end(),comp);
	 	int markpos=-1,mark=0,ans=-1,prev=0;
	 	ll cur=v[0].S;
	 	for(auto&x:v)debug2(x.F,x.S);
	 	FOR(i,1,n)
	 	{
	 		if(v[i].S==cur+1){cur++;continue;}
	 		if(v[i].S==cur+2)
	 		{
	 			if(!mark)markpos=i,mark=1,cur+=2;
	 			else 
	 			{
		 			ans=max(ans,i-prev+1);
	 				mark=0,cur=v[markpos].S;
	 				i=markpos;
	 				prev=markpos;
	 				markpos=0;
	 			}
	 		}	
	 		else
	 		{
	 			// cout<<cur<<" "<<v[i+1].S<<endl;
	 			if(mark)
		 			ans=max(ans,i-prev+1);
	 			else
	 			{
	 				if(v[i+1].S==cur+1)
	 				{
	 					mark=1;
	 					markpos=i;
	 					// cout<<"sda";
	 					continue;
	 				}
		 			ans=max(ans,i-prev);
	 			}
	 			cur=v[i].S;
	 			markpos=-1,mark=0,prev=i;
	 		}
	 	}
	 	ans=max(ans,n-1-prev+1);
	 	cout<<ans;
		return 0;
}