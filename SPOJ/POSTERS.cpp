#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
const int L=1e7;
int arr[L+5];
int lazy[4*L+5],seg[4*L+5],idx=1;
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
void lazyupdate(int s,int e,int index)
{
	if(lazy[index])
	{
		lazy[index<<1]=max(lazy[index<<1],lazy[index]);
		lazy[(index<<1)+1]=max(lazy[(index<<1)+1],lazy[index]);
		lazy[index]=0;
	}
	return ;
}
void update(int s,int e,int index,int start,int end)
{
	if(end<s||start>e)return;
	if(end>=e && start<=s)
	{
		lazy[index]=idx;
		return;
	}
	lazyupdate(s,e,index);
	int mid=(s+e)/2;
	update(s,mid,index<<1,start,end);
	update(mid+1,e,(index<<1)+1,start,end);
	return;
}
set<int>SET;
void cnt(int id = 1,int l = 0,int r = 1e7){
	if(lazy[id]){
		SET.insert(lazy[id]);
		return ; 
	}
	if(l>=r)	return ;
	int mid = (l+r)/2;
	cnt(2 * id, l, mid);
	cnt(2*id+1, mid+1, r);
}

int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t,n,cur,l,r;
	 	cin>>t;
	 	while(t--)
	 	{
	 		cin>>n;
	 		idx=1;
	 		FOR(i,0,4*(1e7+2))seg[i]=0,lazy[i]=0;
	 		FOR(i,1,n+1)
	 		{
	 			cin>>l>>r;
	 			update(1,1e7,1,l,r);
	 			idx++;

	 		}
	 		idx=INT_MIN;
	 		cnt(1,1,1e7);
	 		// update(1,1e7,1,1,1e7);
	 		cout<<sz(SET)<<ln;
	 		SET.clear();
	 	}
		return 0;
}