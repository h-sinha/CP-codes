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
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,m;
		string s,t;
		cin >> n >> m;
		cin >> s;
		cin >>t;
		int pos =-1;
		FOR(i,0,n)
		{
			if(s[i] == '*')
			{
				pos= i;
				break;
			}
		}
		if(pos == -1)
		{
			if(n != m)
			{
				cout<<"NO";
				return 0;
			}
			FOR(i,0,n)
			{
				if(s[i]!=t[i])
				{
					cout<<"NO";
					return 0;
				}
			}
			cout<<"YES";
			return 0;
		}
		int cur=0;
		FOR(i,0,pos)
		{
			if(cur >= m)
			{
				cout<<"NO";
				return 0;
			}
			if(s[i] != t[cur++])
			{
				cout<<"NO";
				return 0;
			}
		}
		cur--;
		int last = m-1;
		RFOR(i,n-1,pos+1)
		{
			if(last <= cur)
			{
				cout<<"NO";
				return 0;
			}
			if(s[i]!=t[last--])
			{
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
		return 0;
		return 0;
}