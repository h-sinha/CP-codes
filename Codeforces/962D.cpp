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
const int L=150001;
map<ll,ll> counter;
std::map<ll,int> hashing;
set<int>idx[L];
set<ll>mult;
bool mark[L];
ll a[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,cur=0;
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		if(hashing[a[i]]==0)
	 		{
	 			hashing[a[i]]=++cur;
	 		}
	 		counter[a[i]]++;
	 		if(counter[a[i]]>1)
	 			mult.insert(a[i]);
	 		idx[hashing[a[i]]].insert(i);
	 	}
	 	ll ele;
	 	int tmp,index;
	 	while(!mult.empty())
	 	{
	 		ele=*mult.begin();
	 		index=hashing[ele];
	 		mark[*idx[index].begin()]=1;
	 		idx[index].erase(idx[index].begin());
	 		tmp=*idx[index].begin();
	 		a[tmp]=2*ele;
	 		if(hashing[2*ele]==0)
	 		{
	 			hashing[2*ele]=++cur;
	 		}
	 		idx[index].erase(idx[index].begin());
			index=hashing[2*ele];
	 		idx[index].insert(tmp);
	 		counter[2*ele]++;
	 		if(counter[2*ele]>1)mult.insert(2*ele);
	 		counter[ele]-=2;
	 		if(counter[ele]<=1)mult.erase(ele);
	 	}
	 	int co=0;
	 	FOR(i,0,n)if(mark[i])co++;
	 	cout<<n-co<<ln;
	 	FOR(i,0,n)
	 	if(!mark[i])cout<<a[i]<<" ";
		return 0;
}