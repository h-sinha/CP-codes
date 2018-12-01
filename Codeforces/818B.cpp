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
int pos[102],tmp, l[102];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,sumis=0,tt=0;
	 	cin>>n>>m;
	 	FOR(i,1,m+1){cin>>l[i];sumis+=l[i];}
	 	FOR(i,1,m)
	 	{
	 		if(pos[l[i]])tt=pos[l[i]];
			if(l[i+1]-l[i]>0)
		 		pos[l[i]]=l[i+1]-l[i];
		 	else
		 		pos[l[i]]=n-l[i]+l[i+1];
		 	if(tt!=pos[l[i]])
	 		counter[pos[l[i]]]++;
	 		// cout<<tt<<" "<<pos[l[i]]<<ln;
	 		if(tt!=pos[l[i]] && tt!=0){cout<<"-1";return 0;}
	 		tt=0;
	 	}
	 	int idx=0;
	 	std::vector<int> cur;
	 	FOR(i,1,n+1)
	 	{
	 		if(counter[i]==0)cur.pb(i);
	 		else if(counter[i]>1){cout<<"-1";return 0;}
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(pos[i]==0)
	 		{
	 			pos[i]=cur[idx++];
	 		}
	 	}
	 	FOR(i,1,n+1)cout<<pos[i]<<" ";
		return 0;
}