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
struct node
{
	int open, close, ok;
};
char baseArray[L];
node seg[4*L];
int size_of_base;
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index].ok = 0;
		// cout<<start<<" "<<baseArray[start]<<ln;
		if(baseArray[start] == '(')
		{
			// cout<<start<<" ";
			seg[index].open = 1;
			seg[index].close = 0;
		}
		else
		{
			seg[index].open = 0;
			seg[index].close = 1;
		}
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	int tmp = min(seg[index<<1].open , seg[(index<<1)+1].close);
	seg[index].ok = (seg[index<<1].ok + seg[(index<<1)+1].ok + tmp); 
	seg[index].open = seg[index<<1].open + seg[(index<<1)+1].open -tmp;
	seg[index].close = seg[index<<1].close + seg[(index<<1)+1].close -tmp;
	return;
}
node query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	node temp;
	temp.ok = 0,temp.open=0,temp.close=0;
	if( start > r || end < l )return temp;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	int mid = (start + end)/2;
	node query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	int tmp = min(query_left.open, query_right.close);
	temp.ok = query_right.ok + query_left.ok + tmp;
	temp.open = query_left.open + query_right.open - tmp;
	temp.close = query_left.close + query_right.close - tmp;
	return temp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int operations,l,r;
	string tmp;
	cin>>tmp;
	size_of_base = tmp.length();
	FOR(i,1,size_of_base+1)baseArray[i]=tmp[i-1];
	build();
	cin>>operations;
	while( operations-- )
	{
		cin >> l >> r;
		cout<<2*query(l, r).ok<<ln;
	}
	return 0;
}