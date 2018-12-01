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
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, tmp1, tmp2, aa, k1, k2;
	 	cin >> n;
	 	cin >> k1;
	 	deque <int> q1,q2;
	 	FOR(i,0,k1)
	 	{
	 		cin >> aa;
	 		q1.push_back(aa);
	 	}
	 	cin >> k2;
	 	FOR(i,0,k2)
	 	{
	 		cin >> aa;
	 		q2.push_back(aa);
	 	}
	 	int cur=0;
	 	while(cur < 5e6)
	 	{
	 		tmp1 = q1.front();
	 		q1.pop_front();
	 		tmp2 = q2.front();
	 		q2.pop_front();
	 		// cout<<tmp1<<" "<<tmp2<<ln;
	 		if(tmp1 < tmp2)
	 		{
	 			q2.push_back(tmp1);
	 			q2.push_back(tmp2);
	 		}
	 		else if(tmp1 > tmp2)
	 		{
	 			q1.push_back(tmp2);
	 			q1.push_back(tmp1);	
	 		}
	 		else 
	 		{
	 			cout<<"-1";
	 			return 0;
	 		}
	 		if(q1.empty())
	 		{
	 			cout<<cur+1<<" 2";
	 			return 0;
	 		}
	 		if(q2.empty())
	 		{
	 			cout<<cur+1<<" 1";
	 			return 0;
	 		}
	 		cur++;
	 	}
	 	cout<<"-1";
		return 0;
}