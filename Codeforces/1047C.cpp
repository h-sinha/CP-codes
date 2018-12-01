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
const int L=3e5+7;
ll a[L];
int counter[15000010],cal[15000010];
bool prime[15000010];
void calc()
{
	prime[1] = 1;
	FOR(i,2,15000001)
	{
		if(prime[i])continue;
		for(int j = 2*i ;j<= 15000000;j+=i)
		{
			prime[j] = 1;
			if(counter[j])cal[i]+=counter[j];
		}
		if(counter[i])cal[i]+=counter[i];
	}

}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin >> n;
	 	ll g = 0;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 		g = __gcd(g,a[i]);
	 	}
	 	int f=0;
	 	FOR(i,0,n)
	 	{
	 		a[i]/=g;
	 		if(a[i]!=1)f=1;
	 		counter[a[i]]++;
	 	}
	 	if(!f)
	 	{
	 		cout<<"-1";
	 		return 0;
	 	}
	 	calc();
	 	int cur = INT_MIN;
	 	FOR(i,2,15000001)
	 	{
	 		// if(cal[i])debug2(i,cal[i]);

	 		if(cal[i])cur=max(cur,cal[i]);
	 	}
	 	cout<<n-cur;
		return 0;
}