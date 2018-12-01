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
std::vector<ll> buy[L], vote(L), cost(L), count_vote(L), mark(L);
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll a, b, n, sumis = 0, leftis = 0, cur, aux, ans=LLONG_MAX;
	 	multiset<ll> stor;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> a >> b;
	 		if(a==0)b=100000;
	 		count_vote[a]++;
	 		cost[i] = b;
	 		vote[i] = a;
	 		sumis += b;
	 	}
	 	// FOR(i,0,n)cout<<cost[i]<<" ";
	 	leftis = n;
	 	FOR(i,0,n)
	 	{
	 		// if(mark[vote[i]])continue;
	 		buy[count_vote[vote[i]]].pb(cost[i]);
	 		// mark[vote[i]] = 1;
	 	}
	 	// cout<<ln;
	 	FOR(i,0,count_vote[0])
	 	{
	 		trace(buy[i], x)
	 		{
	 			sumis -= x;
	 			stor.insert(x);
	 		}
	 		leftis -= sz(buy[i]);
	 	}

	 	// debug2(leftis,sumis);
	 	// trace(stor,x )cout<<x<<"sa"<<ln;
	 	FOR(i,count_vote[0], n+1)
	 	{
	 		cout<<i <<" -> ";
	 		
	 		// debug2(leftis,sumis);
	 		// cout<<vote[0]<<" _ "<<leftis<<ln;
	 		if(count_vote[0] + leftis >= i)
	 		{
	 			trace(buy[i], x)
	 			{
	 				sumis -= x;
	 				stor.insert(x);
	 			}
	 			leftis -= sz(buy[i]);
	 			ans = min(ans,  sumis);
	 			continue;
	 		}
	 		cur = count_vote[0] + leftis;
	 		aux = sumis;
	 		// cout<<"cur "<<cur<<ln;
	 		trace(stor, x)
	 		{
	 			cout<<cur<<" & "<<aux<<" "<<x<<ln;
	 			if(cur >= i)
	 			{
	 				ans = min(ans, aux);
	 				break;
	 			}
	 			cur++;
	 			aux += x;
	 		}
	 		trace(buy[i], x)
	 		{
	 			sumis -= x;
	 			stor.insert(x);
	 		}
	 		leftis -= sz(buy[i]);
	 		cout<<"ans"<<ans<<ln;
	 	}
	 	cout<<ans;
		return 0;
}