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
const int L=2e5;
set<int>v[L+5];
int cnt[L+5],parent[L+5],mark[L+5],mark1[L+5],mark2[L+5];
std::vector<int> arr;
inline int find(int x)
{
	if(parent[x]<=0)return x;
	parent[x]=find(parent[x]);
	return parent[x];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL),cout.tie(NULL);
	 	int f=0,ans=0,cur,pi,pj,a,b,n,m,co=0;
	 	cin>>n>>m;
	 	while(m--)
	 	{
	 		cin>>a>>b;
	 		v[a].insert(b);
	 		v[b].insert(a);

	 	}
	 	int an=n;
	 	FOR(i,1,n+1)
	 	{
	 	    cnt[i]=sz(v[i]);
	 		if(sz(v[i])==n-1)
	 		{
	 			mark[i]=1;
	 			parent[i]=-1;
	 			co++;
	 			an--;
	 		}
	 		else if(sz(v[i])==0)
	 		{
	 			cout<<"1"<<ln;
	 			cout<<n;
	 			return 0;
	 		}
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(mark1[i])continue;
	 		cur=0;
	 		mark1[i]=1;
	 		if(parent[i]==0){parent[i]=-1;}
	 		// cout<<parent[pi]<<"&";
	 		if(parent[pi]==-an){f=1;break;}
	 		if(cnt[i]==n-1)continue;
	 		FOR(j,1,n+1)
	 		{
	 			if(i==j)continue;
	 			if(v[i].find(j)!=v[i].end())continue;
	 			// if(cur<sz(v[i]) && v[i][cur]==j){cur++;continue;}
		 		pi=find(i);
	 			pj=find(j);
	 			if(mark1[j]==0)co++;
	 			if(pi==pj)continue;
	 			if(parent[pj]==0){parent[pj]=-1;}
				parent[pi]+=parent[pj];
				parent[pj]=pi;
	 			mark1[j]=1;
	 			cnt[i]++;
	 		    if(cnt[i]==n-1)break;
	 		}
	 	}
	 	// cout<<an<<ln;
	 	FOR(i,1,n+1){if(parent[i]==-an)f=1;break;}
	 	if(f)goto label;
	 	// cout<<"sda";
	 	RFOR(i,n,1)
	 	{
	 		if(mark2[i])continue;
	 		mark2[i]=1;
	 		pi=find(i);
	 		if(parent[pi]==-an)break;
            if(cnt[i]==n-1)continue;
	 		FOR(j,1,n+1)
	 		{
	 			if(i==j)continue;
	 			if(v[i].find(j)!=v[i].end())continue;
		 		pi=find(i);
	 			pj=find(j);
	 			if(pi==pj)continue;
	 			if(parent[pj]==0){parent[pj]=-1;}
				parent[pi]+=parent[pj];
				parent[pj]=pi;
				cnt[i]++;
				if(cnt[i]==n-1)break;
	 			mark2[j]=1;
	 		}
	 	}
	 	label:
	 	// FOR(i,1,n+1)debug2(i,parent[i]);
	 	FOR(i,1,n+1)
	 	{
	 		if(parent[i]<0)
	 		{
	 			ans++;
	 			arr.pb(-parent[i]);
	 		}
	 	}
	 	sort(arr.begin(), arr.end());
	 	cout<<ans<<ln;
	 	for(auto &x:arr)cout<<x<<" ";
		return 0;
}