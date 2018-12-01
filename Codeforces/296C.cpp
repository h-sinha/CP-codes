#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
ll cum[100005],aux[100005],arr[100005],modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,x,y,a[100005],b[100005],c[100005],m,k,d;
	cin>>n>>m>>k;
	FOR(i,1,n+1)cin>>arr[i];
	FOR(i,1,m+1)
		cin>>a[i]>>b[i]>>c[i];
	while(k--)
	{
		cin>>x>>y;
		aux[x]+=1;
		aux[y+1]-=1;
	}
	FOR(i,1,m+1)
		aux[i]+=aux[i-1];
	FOR(i,1,m+1)
		c[i]*=aux[i];
	FOR(i,1,m+1)
	{
		cum[a[i]]+=c[i];
		cum[b[i]+1]-=c[i];
	}
	 FOR(i,1,n+1)cum[i]+=cum[i-1];
	FOR(i,1,n+1){printf("%lld ",arr[i]+cum[i]);}
	return 0;
}