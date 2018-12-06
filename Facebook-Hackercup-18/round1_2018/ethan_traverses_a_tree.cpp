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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
int val[2002],pre[2002],post[2002],cur=0,pr[2002],po[2002];
std::vector<pii> v(2002);
void prep(int vertex)
{
	pre[cur++]=vertex;
	if(v[vertex].F!=0)prep(v[vertex].F);
	if(v[vertex].S!=0)prep(v[vertex].S);
	return;
}
void postp(int vertex)
{
	if(v[vertex].F!=0)postp(v[vertex].F);
	if(v[vertex].S!=0)postp(v[vertex].S);
	post[cur++]=vertex;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int t,n,k,a,b,flag=1,curval,f,co;
		cin>>t;
		while(t--)
		{
			cin>>n>>k;
			FOR(i,1,n+1)
			{
				cin>>a>>b;
				v[i].F=a,v[i].S=b;
			}
			cur=0;
			prep(1);
			cur=0;
			postp(1);
			FOR(i,0,cur)
			{
				po[pre[i]]=post[i];
				pr[post[i]]=pre[i];
			}
			// FOR(i,0,cur)cout<<pre[i]<<" ";
			// cout<<ln;
			// FOR(i,0,cur)cout<<post[i]<<" ";
			// cout<<ln;
			// FOR(i,1,n+1)cout<<i<<" "<<pr[i]<<" "<<po[i]<<ln;
			co=1;
			FOR(i,1,n+1)
			{
				if(val[i]!=0)continue;
				if(co>k)co=k;
				val[i]=co;
				f=1,curval=i;
				while(1)
				{
					if(val[po[curval]]!=0 || po[curval]==0)break;
					val[po[curval]]=co;
					curval=po[curval];
				}
				co++;
			}
			if(co<=k)
			{
				cout<<"Case #"<<flag<<": Impossible\n";
			}
			else
			{
				cout<<"Case #"<<flag<<": ";
				FOR(i,1,n+1)cout<<val[i]<<" ";
				cout<<ln;
			}
			flag++;
			FOR(i,1,n+1)
				val[i]=0;
			v.clear();
		}
		return 0;
}