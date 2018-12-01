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
ll a[L], b[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	ll v1,v2,tmp;
	 	cin >>n;
	 	ll mini = LLONG_MAX;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i] >> b[i];
	 		if (a[i]*b[i] < mini)
	 		{
	 			mini = a[i]*b[i];
	 			v1=a[i],v2=b[i];
	 		}
	 	}
	 	set<ll> check;
	 	tmp = sqrt(v1);
	 	while(v1%2==0){check.insert(2);v1/=2;}
	 	FOR(i,3,tmp+1)
	 	{
	 		if(v1%i==0)check.insert(i);
	 		while(v1%i==0)
	 			v1/=i;
	 		if(v1==1)break;
	 	}
	 	if(v1>2)check.insert(v1);
	 	tmp = sqrt(v2);
	 	while(v2%2==0){check.insert(2);v2/=2;}
	 	FOR(i,3,tmp+1)
	 	{
	 		if(v2%i==0)check.insert(i);
	 		while(v2%i==0)
	 			v2/=i;
	 		if(v2==1)break;
	 	}
	 	if(v2>2)check.insert(v2);
	 	check.erase(1);
	 	std::vector<ll> check1;
	 	trace(check,x)check1.pb(x);
	 	int f;
	 	trace(check1,x)
	 	{
	 		f=0;
	 		FOR(i,0,n)
	 		{
	 			if(a[i]%x==0 || b[i]%x ==0)continue;
	 			else 
	 			{
	 				f=1;break;
	 			}
	 		}
	 		if(f==0)
	 		{
	 			cout<<x;
	 			return 0;
	 		}
	 	}
	 	cout<<"-1";
		return 0;
}