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
std::vector<pii> v[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int ans,t,n,k,co;
	 	cin >> t;
	 	FOR(kk,0,t)
	 	{
	 		cin >> n >> k;
	 		ans=0;
	 		
	 		if(n==2)
	 		{
	 			cout<<"Case #"<<kk+1<<": 0"<<ln;
	 			cout<<"1\n";
	 			cout<<"1 2 "<<k<<ln;
	 			continue;
	 		}
	 		if(k==2 || k==1)
	 		{
	 			cout<<"Case #"<<kk+1<<": 0"<<ln;
	 			cout<<"1\n";
	 			cout<<"1 "<<n<<" "<<k<<ln;
	 			continue;
	 		}
	 		FOR(i,0,n+1)v[i].clear();
	 		if(k>=n)
	 		{
	 			co=1;
	 			FOR(i,1,n)
	 			{
	 				v[i].pb(mp(i+1,k-i));
	 				ans+=k-i;
	 				co++;
	 			}
	 			v[1].pb(mp(n,k));
	 			cout<<"Case #"<<kk+1<<": "<<abs(ans-k)<<ln;
	 			cout<<co<<ln;
	 			FOR(i,1,n+1)
	 			{
	 				trace(v[i],x)cout<<i<<" "<<x.F<<" "<<x.S<<ln;
	 			}
	 		}
	 		else
	 		{
	 			v[1].pb(mp(n,k));
	 			co=1;
				FOR(i,1,n)
				{
					
					if(k-i==1)
					{
						v[i].pb(mp(n,1));
						ans+=1;
						co++;
						break;
					}
					co++;
					v[i].pb(mp(i+1,(k-i)));
					ans+=(k-i);
				}
				cout<<"Case #"<<kk+1<<": "<<abs(ans-k)<<ln;
	 			cout<<co<<ln;
	 			FOR(i,1,n)
	 			{
	 				trace(v[i],x)cout<<i<<" "<<x.F<<" "<<x.S<<ln;
	 			}	 			
	 		}
	 	}
		return 0;
}