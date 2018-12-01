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
const int L=1e6+7;
ll size_of_base,arr[L][22],seg[4*L],lazy[4*L][22];
void lazyUpdate(int start, int end, int index)
{
	FOR(i,0,21)seg[index][i]^=lazy[index];
	if(start != end)
	{
		FOR(i,0,21)
		{
			lazy[index<<1][i]^=lazy[index];
			lazy[(index<<1)+1][i]^=lazy[index];
		}
	}
	FOR(i,0,22)lazy[index][i]=0;
	return;
}
void updateRange(int l, int r, ll value, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if(r < start || l > end || start > end )return;
	if( l <= start && r >= end )
	{
		ll val = value, tmp;
		FOR(i,0,21)
		{
			tmp=val&1;
			seg[index][i]^=tmp;
			val>>=1;
		}
		val=value;
		if(start != end)
		{
			FOR(i,0,21)
			{
				tmp=val&1;
				lazy[index<<1][i]^=tmp;
				lazy[(index<<1)+1][i]^=tmp;
				val>>=1;
			}
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	FOR(i,0,21)
	seg[index][i] = (seg[2*index][i] + seg[2*index + 1][i]) ;
	return;
}
arr[] query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return 0;
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2;
	ll query_left[22], query_right[22];
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	FOR(i,0,21)query_right[i]+=query_left[i];
	return query_right;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll type, operations, idx, value, l, r;
	cin >> size_of_base;
	for (ll i = 1; i <= size_of_base; ++i)
		cin >> baseArray[i];
	FOR(i,1,size_of_base+1)
	{
		tmp = baseArray[i];
		cur=0;
		while(tmp > 0)
		{
			if(tmp&1)arr[i][cur]=1;
			tmp/=2;
		}
	}
	FOR(i,1,size_of_base+1)
	{
		FOR(j,0,21)
		{
			arr[i][cur] += arr[i-1][cur];
		}
	}
	cin >> operations;
	while( operations-- )
	{
		cin >> type;
		if( type == 1 )
		{
			cin >> l >> r;

		}
		else if( type == 2 )
		{
			cin >> l >> r >> value;
			updateRange(l, r, value);
		}
	}
	return 0;
}