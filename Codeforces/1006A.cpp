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
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	ll tmp,cur;
	 	cin>>n;
	 	set<ll>SET;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		SET.insert(a[i]);
	 		counter[a[i]]++;
	 	}
	 	cur=-1;
	 	while(sz(SET))
	 	{
	 		tmp = *SET.begin();
	 		// cout<<tmp<<" "<<cur<<endl;
	 		if(tmp<=cur)break;
	 		cur=tmp;
	 		if(tmp%2)
	 		{
	 			FOR(i,0,n)
	 			{
	 				if(a[i]==tmp)
	 				{
	 					a[i] = tmp+1;
	 					counter[tmp]--;
	 					counter[tmp+1];
	 				}
	 			}
	 			if(counter[tmp]==0)SET.erase(tmp);
	 			SET.insert(tmp+1);
	 		}
	 		else
	 		{
	 			FOR(i,0,n)
	 			{
	 				if(a[i]==tmp)
	 				{
	 					a[i] = tmp-1;
	 					counter[tmp]--;
	 					counter[tmp-1];
	 				}
	 			}
	 			if(counter[tmp]==0)SET.erase(tmp);
	 			SET.insert(tmp-1);
	 		}
	 		int co=0;
	 		trace(SET,x)
	 		{
	 			if(x<=cur)co++;
	 			else break;
	 		}
	 		// cout<<"co"<<co<<endl;
	 		while(co>0)
	 		{
	 			// cout<<co<<endl;
	 			// if(sz(SET)==0)break;
	 			SET.erase(SET.begin());
	 			co--;
	 		}
	 	// FOR(i,0,n)cout<<a[i]<<" ";
	 	// cout<<ln;
	 	}
	 	FOR(i,0,n)cout<<a[i]<<" ";
		return 0;
}