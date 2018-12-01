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
std::vector<int> v[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, d, h, tmp;
	 	cin >> n >> d >> h;
	 	int cur = 1;
	 	FOR(i,1,h+1)
	 	{
	 		v[i].pb(i+1);
	 		cur = i+1;
	 	}  
	 	if(d - h < 0)
	 	{
	 		cout << "-1";
	 		return 0;
	 	}
	 	else if(d - h == 0)
	 	{
	 		if(cur == 2 && n!=2)
	 		{
	 			cout << "-1";
	 			return 0;
	 		}
	 		FOR(i,cur+1,n+1)v[2].pb(i);
	 		FOR(i,1,n+1)
	 			trace(v[i],x)cout<<i<<" "<<x<<ln;
	 	}
	 	else
	 	{
	 		tmp = d-h;
	 		if(tmp > h)
	 		{
	 			cout << "-1";
	 			return 0;
	 		}
	 		v[1].pb(cur+1);
	 		cur++;
	 		tmp--;
	 		while(tmp > 0)
	 		{
	 			v[cur].pb(cur+1);
	 			cur++;
	 			tmp--;
	 		}
	 		if(cur > n)
	 		{
	 			cout<<"-1";
	 			return 0;
	 		}
	 		FOR(i,cur+1,n+1)v[1].pb(i);
	 		FOR(i,1,n+1)
	 			trace(v[i],x)cout<<i<<" "<<x<<ln;
	 	}
		return 0;
}