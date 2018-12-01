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
const int L=2e5+7;
int a[L],nexti[L],previ[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n, m, l, r ,x, tmp;
		cin >> n >> m;
		FOR(i,0,n)cin >> a[i];
		previ[0] = -1;
		nexti[n-1] = -1;
		FOR(i,1,n)
		{
			if(a[i-1] != a[i])previ[i] = i-1;
			else previ[i] = previ[i-1];
		}
		RFOR(i,n-2,0)
		{
			if(a[i+1] != a[i])nexti[i] = i+1;
			else nexti[i] = nexti[i+1];
		}
		// FOR(i,0,n)debug3(i,nexti[i],previ[i]);
		while(m--)
		{
			cin >> l >> r >> x;
			if(a[l-1] != x)cout<<l<<ln;
			else if(a[r-1]!=x)cout<<r<<ln;
			else 
			{
				// cout<<a[l-1]<<" "<<nexti[l-1]<<" "<<a[r-1]<<" "<<previ[r-1]<<ln;
				tmp = max(nexti[l-1],previ[r-1]);	
				if(tmp+1 >= l && tmp+1<=r)cout<<tmp+1<<ln;
				else cout<<"-1\n";
			}
		}
		return 0;
}