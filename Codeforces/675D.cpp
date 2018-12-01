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
std::map<pii, int> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,a,l,r;
	 	cin>>n;
	 	set<int>SET;
	 	set<int>::iterator it;
	 	FOR(i,0,n)
	 	{
	 		cin>>a;
	 		SET.insert(a);
	 		it = SET.find(a);
	 		if(it==SET.begin())l=INT_MIN;
	 		else
	 		{
	 			it--;
	 			l = *it;
	 			it++;
	 		}
	 		it++;
	 		if(it==SET.end())r=INT_MAX;
	 		else
	 		{
	 			r = *it;
	 		}
	 		// cout<<l<<" "<<r<<ln;
	 		if(i)cout<<counter[mp(l,r)]<<" ";
	 		counter.erase(mp(l,r));
	 		counter[mp(l,a)] = a;
	 		counter[mp(a,r)] = a;
	 	}
		return 0;
}