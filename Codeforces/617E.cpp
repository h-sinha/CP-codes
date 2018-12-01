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
const int L=1e5+1;
ll sofar[L],out[L];
struct node
{
	ll l,r,q;
};
ll ans=0,counter[3000002],k;
bool comp(node x, node y)
{
	return x.r<y.r;
}
void add(ll val)
{
	ans+=counter[val^k];
	counter[val]++;
	return;
}
void remove(ll val)
{
	counter[val]--;
	ans-=counter[val^k];
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a,n,m,cur=0,l,r;
	 	cin>>n>>m>>k;
	 	FOR(i,1,n+1)
	 	{
	 		cin>>a;
	 		sofar[i]^=sofar[i-1];
	 		sofar[i]^=a;
	 	}
	 	std::vector<node> v[n/316 + 5];
	 	node temp;
	 	FOR(i,0,m)
		{
			cin>>l>>r;
			l--,r++;
			temp.l=l,temp.r=r,temp.q=i;
			v[l/316].pb(temp);
	 		// cout<<"sda"<<endl;
		}
		FOR(i,0,n/316 +1)sort(all(v[i]),comp);
		// cout<<"sda"<<endl
		FOR(i,0,n/316 + 3)
		{
			// cout<<"SDA"<<endl;
			l=r=i*316;
				ans=0;
			// cout<<i<<" "<<l<<" "<<r<<" "<<sz(v[i])<<endl;
			trace(v[i],x)
			{
				// cout<<x.l<<" "<<x.r<<ln;
				while(r<x.r)
				{
					// cout<<"3 "<<r<<ln;
					add(sofar[r]);
					++r;
				}
				// cout<<ans<<ln;
				while(l<x.l)
				{
					// cout<<"1 "<<l<<ln;
					remove(sofar[l]);
					l++;
				}
				// cout<<ans<<ln;
				while(l>x.l)
				{
					// cout<<"2 "<<l<<ln;
					--l;
					add(sofar[l]);
				}
				// cout<<ans<<ln;
				
				// while(r>x.r)
				// {
				// 	// cout<<"4 "<<r<<ln;
				// 	remove(sofar[r]);
				// 	--r;
				// }
				// cout<<ans<<ln;
			// FOR(kk,0,10)cout<<kk<<" "<<counter[kk]<<ln;
				// cout<<x.l<<" - "<<x.r<<" "<<ans<<ln;
				// cout<<x.q<<ln;
				// cout<<x.l<<" "<<x.r<<" "<<x.q<<" - "<<ans<<ln;
				out[x.q]=ans;
				// cout<<ln;
			}
			FOR(j,l,r)remove(sofar[j]);
		}
		FOR(i,0,m)cout<<out[i]<<ln;
	return 0;
}