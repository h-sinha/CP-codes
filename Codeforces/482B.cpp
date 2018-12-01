#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
const ll L=1e5+7;
ll a[L][35],power[35],size_of_base;
ll mark[L],done[L],counter[2],seg[4*L],baseArray[L],l[L],r[L],q[L];
void build(ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	ll mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	seg[index] = ( seg[ 2*index ] & seg[ 2*index + 1] );
	return;
}
ll query(ll l, ll r, ll start = 1, ll end = size_of_base, ll index = 1)
{
	if( start > r || end < l )return power[30]-1;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	ll mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return (query_left & query_right);
}
void solve(ll i)
{
	ll ans=0;
	FOR(j,0,32)
		if(a[i][j])ans=ans+power[j];
	baseArray[i]=ans;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,tmp;
	 	cin>>n>>m;
	 	ll cur=0;
	 	power[0]=1;
	 	FOR(i,1,33)power[i]=power[i-1]*2;
	 	FOR(i,0,m)
	 	{
	 		cin>>l[i]>>r[i]>>q[i];
	 		cur=0;
	 		tmp=q[i];
	 		while(tmp)
	 		{
	 			if(tmp&1)
	 			{
	 				a[r[i]+1][cur]--;
	 				a[l[i]][cur]++;
	 			}
	 			cur++;
	 			tmp>>=1;
	 		}
	 	}
	 	FOR(i,1,n+1)
	 		FOR(j,0,31)
	 				a[i][j]+=a[i-1][j];
	 	size_of_base=n;
	 	FOR(i,1,n+1)solve(i);
	 	build();
	 	FOR(i,0,m)
	 	{
	 		// cout<<query(l[i],r[i])<<ln;
	 		if(q[i]!=query(l[i],r[i]))
	 		{
	 			cout<<"NO";
	 			return 0;
	 		}
	 	}
	 	cout<<"YES\n";
	 	FOR(i,1,n+1)cout<<baseArray[i]<<" ";
		return 0;
}eturn 0;
}