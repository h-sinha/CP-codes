#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
std::vector<bool> visit(100002);
ll w[200002],mini=INT_MAX;
int mark0[200002],mark1[200002];
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	string str;
	 	priority_queue<pii,std::vector<pii>,greater<pii> > qsmall;
		priority_queue<pii,std::vector<pii> > qlarge;
	 	FOR(i,0,n)
	 	{
	 		cin>>w[i];
	 		qsmall.push(mp(w[i],i));
	 	}
	 	cin>>str;
		int len=str.length();
		pii temp;
		FOR(i,0,len)
		{
			if(str[i]=='0')
			{
				while(1)
				{
					temp=qsmall.top();
					if(mark0[temp.second]==0)break;
				}
				cout<<temp.second+1<<" ";
				mark0[temp.second]=1;
				qsmall.pop();
				qlarge.push(mp(temp.first,temp.second));
			}
			else 
			{
				while(1)
				{
					temp=qlarge.top();
					if(mark1[temp.second]==0)break;
				}
				cout<<temp.second+1<<" ";
				mark1[temp.second]=1;
				qlarge.pop();
			}
		}
		return 0;
}