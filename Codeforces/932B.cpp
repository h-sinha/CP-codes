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
const int L=1e6+7;
int ans[L],stor[L][10];
void pre()
{
	int cur,tmp;
	FOR(i,1,10)ans[i]=i;
	FOR(i,10,1000001)
	{
		cur=i,tmp=1;
		while(cur>0)
		{
			if(cur%10!=0)
				tmp*=(cur%10);
			cur/=10;
		}
		ans[i]=ans[tmp];
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	pre();
	 	FOR(i,1,1000001)stor[i][ans[i]]++;
	 	FOR(i,1,1000001)FOR(j,1,10)stor[i][j]+=stor[i-1][j];
	 	int q,l,r,k;
	 	cin>>q;
	 	while(q--)
	 	{
	 		cin>>l>>r>>k;
	 		cout<<stor[r][k]-stor[l-1][k]<<ln;
	 	}
		return 0;
}