#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<pii,int> counter;
const int L=1e6;
bool prime[L+10];
std::vector<int> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,mst=0,sp=0;
	 	cin>>n>>m;
	 	prime[1]=1;
	 	std::vector<int> ::iterator it;
	 	FOR(i,2,1001)
	 	{
	 		if(prime[i])continue;
	 		for(int j=i*2;j<=L;j+=i)
	 			prime[j]=1;
	 	}
	 	FOR(i,1,L+1)if(!prime[i])v.pb(i);
	 	it=upper_bound(v.begin(), v.end(),n-2);
		mst=max(int(0),n-2)+(*it-(n-2));
		sp=mst;		
		m-=(n-1);
		cout<<mst<<" "<<sp<<ln;
		FOR(i,1,n-1)
	 	{
	 		cout<<i<<" "<<i+1<<" "<<"1"<<ln;
	 		mst++;
	 		sp++;
		}
		cout<<n-1<<" "<<n<<" "<<*it-(n-2)<<ln;
		int last=*it-(n-2);
		int cur=1,aux=3;
		while(m>0)
		{
			if(aux!=n)
			{
				cout<<cur<<" "<<aux<<" "<<(aux-cur)+1<<ln;
				aux++;
				m--;
			}
			else 
			{
				cout<<cur<<" "<<n<<" "<<(last+n-1-cur)+1<<ln;
				cur++;
				aux=cur+2;
				m--;
			}
		}
		return 0;
}