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
ll fact[100],counter[15];
ll co[15];
void pre()
{
	fact[0]=1,fact[1]=1;
	FOR(i,2,20)
		fact[i]=fact[i-1]*i;
}
ll calc(ll arr[])
{
	ll tot=0,div=1,ans=0;
	FOR(i,0,10)
	{
		div*=fact[arr[i]];
		tot+=arr[i];
	}
	ans=fact[tot]/div;
	if(counter[0]>0)
	{
		tot--;
		div/=fact[arr[0]];
		div*=fact[arr[0]-1];
		ans-=fact[tot]/div;
	}
	return ans;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	cin>>s;
	 	int len=s.length();
	 	FOR(i,0,len)
	 		counter[s[i]-'0']++;
	 	// FOR(i,1,10)cout<<counter[i];
	 	pre();
	 	std::vector<int> v;

	 	ll ans=0;
	 	FOR(i,0,10)co[i]=counter[i];
	 	FOR(i,0,10)
	 	{
	 		if(co[i]>1)
	 		{
	 			v.pb(i);
	 		}
	 		// co[i]=counter[i];
	 	}

	 	if(sz(v))goto label;
	 	// cout<<"sa";
	 	ans+=calc(counter);
	 	
	 	label:
	 	if(sz(v)==9)
	 	{
	 		FOR(i,1,counter[v[0]]+1)
	 		{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 					FOR(l,1,counter[v[3]]+1)
	 					{
	 						FOR(m,1,counter[v[4]]+1)
	 						{
	 							FOR(n,1,counter[v[5]]+1)
	 							{
	 								FOR(o,1,counter[v[6]]+1)
	 								{
	 									FOR(p,1,counter[v[7]]+1)
	 									{
	 										FOR(q,1,counter[v[8]]+1)
	 										{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
	 												co[v[3]]=l;
	 												co[v[4]]=m;
	 												co[v[5]]=n;
	 												co[v[6]]=o;
	 												co[v[7]]=p;
	 												co[v[8]]=q;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 												co[v[3]]=counter[3];
	 												co[v[4]]=counter[4];
	 												co[v[5]]=counter[5];
	 												co[v[6]]=counter[6];
	 												co[v[7]]=counter[7];
	 												co[v[8]]=counter[8];
	 										}
	 									}
	 								}
	 							}
	 						}
	 					}
	 				}

	 			}
	 		}
	 	}
	 		else if(sz(v)==8)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 					FOR(l,1,counter[v[3]]+1)
	 					{
	 						FOR(m,1,counter[v[4]]+1)
	 						{
	 							FOR(n,1,counter[v[5]]+1)
	 							{
	 								FOR(o,1,counter[v[6]]+1)
	 								{
	 									FOR(p,1,counter[v[7]]+1)
	 									{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
	 												co[v[3]]=l;
	 												co[v[4]]=m;
	 												co[v[5]]=n;
	 												co[v[6]]=o;
	 												co[v[7]]=p;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 												co[v[3]]=counter[3];
	 												co[v[4]]=counter[4];
	 												co[v[5]]=counter[5];
	 												co[v[6]]=counter[6];
	 												co[v[7]]=counter[7];
	 									}
	 								}
	 							}
	 						}
	 					}
	 				}
	 			}
	 		}
	 		}
	 		else if(sz(v)==7)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 					FOR(l,1,counter[v[3]]+1)
	 					{
	 						FOR(m,1,counter[v[4]]+1)
	 						{
	 							FOR(n,1,counter[v[5]]+1)
	 							{
	 								FOR(o,1,counter[v[6]]+1)
	 								{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
	 												co[v[3]]=l;
	 												co[v[4]]=m;
	 												co[v[5]]=n;
	 												co[v[6]]=o;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 												co[v[3]]=counter[3];
	 												co[v[4]]=counter[4];
	 												co[v[5]]=counter[5];
	 												co[v[6]]=counter[6];
	 											}
	 										}
	 									}
	 								}
	 							}
	 						}
	 					}
	 		}
	 		else if(sz(v)==6)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 					FOR(l,1,counter[v[3]]+1)
	 					{
	 						FOR(m,1,counter[v[4]]+1)
	 						{
	 							FOR(n,1,counter[v[5]]+1)
	 							{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
	 												co[v[3]]=l;
	 												co[v[4]]=m;
	 												co[v[5]]=n;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 												co[v[3]]=counter[3];
	 												co[v[4]]=counter[4];
	 												co[v[5]]=counter[5];
	 											}
	 										}
	 									}
	 								}
	 						}
	 					}
	 		}
	 		else if(sz(v)==5)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 					FOR(l,1,counter[v[3]]+1)
	 					{
	 						FOR(m,1,counter[v[4]]+1)
	 						{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
	 												co[v[3]]=l;
	 												co[v[4]]=m;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 												co[v[3]]=counter[3];
	 												co[v[4]]=counter[4];
	 											}
	 										}
	 									}
	 								}
	 					}
	 		}
	 		else if(sz(v)==4)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 					FOR(l,1,counter[v[3]]+1)
	 					{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
	 												co[v[3]]=l;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 												co[v[3]]=counter[3];
	 											}
	 										}
	 									}
	 								}
	 		}
	 		else if(sz(v)==3)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 				FOR(k,1,counter[v[2]]+1)
	 				{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
	 												co[v[2]]=k;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 												co[v[2]]=counter[2];
	 											}
	 										}
	 									}
	 		}
	 		else if(sz(v)==2)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 			FOR(j,1,counter[v[1]]+1)
	 			{
	 												co[v[0]]=i;
	 												co[v[1]]=j;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 												co[v[1]]=counter[1];
	 											}
	 										}
	 									}
	 	else if(sz(v)==1)
	 		{
	 			FOR(i,1,counter[v[0]]+1)
	 			{	
	 												co[v[0]]=i;
													ans+=calc(co);
													co[v[0]]=counter[0];
	 											}
	 										}
	 	cout<<ans;
		return 0;
}