#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	int(a.size())
#define F first
#define S second
#define aint(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<int,int>
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
struct node
{
	int l, r, tot;
};
node seg[4*L];
int size_of_base;
string s;
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index].l = seg[index].r = seg[index].tot = 0;
		// debug(s[index-1], index, s);
		if(s[start-1] == '(')seg[index].l = 1;
		else seg[index].r = 1;
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	int tmp = min(seg[2*index].l, seg[2*index + 1].r);
	seg[index].tot = seg[2*index].tot + seg[2*index + 1].tot + tmp;
	seg[index].l = seg[2*index].l + seg[2*index + 1].l - tmp;
	seg[index].r = seg[2*index].r + seg[2*index + 1].r - tmp;
	return;
}
node query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return node({0,0,0});
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	int mid = (start + end)/2;
	node query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	int tmp = min(query_left.l, query_right.r);
	node ret;
	ret.tot = query_left.tot + query_right.tot + tmp;
	ret.l = query_left.l + query_right.l - tmp;
	ret.r = query_left.r + query_right.r - tmp;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	size_of_base = s.length();
	build();
	int ans = INT_MIN;
	FOR(i,1,size_of_base+1)
		ans = max(ans, query(i,size_of_base).tot*2);
	cout<<ans;
	return 0;
}
