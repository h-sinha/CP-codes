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
int size_of_base, inf, inf1;
std::vector<int> baseArray(L),seg(4*L),lazy(4*L);
std::vector<int> baseArray1(L),seg1(4*L),lazy1(4*L);
int combine(int a, int b)
{
	return min(a,b);
}
void lazyUpdate(int start, int end, int index)
{
	if(lazy[index] != 0)
	{
		seg[index] += lazy[index];
		if(start != end)
		{
			lazy[2*index] += lazy[index];
			lazy[(2*index) + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	return;
}
void updateRange(int l, int r, int value, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if(r < start || l > end || start > end )return;
	if( l <= start && r >= end )
	{
		seg[index] += value;
		if(start != end)
		{
			lazy[2*index] += value;
			lazy[2*index + 1] += value;
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	seg[index] = combine(seg[2*index] , seg[2*index + 1]) ;
	return;
}
int query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return inf;
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2, query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return combine(query_left , query_right);
}
int combine1(int a, int b)
{
	return max(a,b);
}
void lazyUpdate1(int start, int end, int index)
{
	if(lazy1[index] != 0)
	{
		seg1[index] += lazy1[index];
		if(start != end)
		{
			lazy1[2*index] += lazy1[index];
			lazy1[(2*index) + 1] += lazy1[index];
		}
		lazy1[index] = 0;
	}
	return;
}
void updateRange1(int l, int r, int value, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate1(start, end, index);
	if(r < start || l > end || start > end )return;
	if( l <= start && r >= end )
	{
		seg1[index] += value;
		if(start != end)
		{
			lazy1[2*index] += value;
			lazy1[2*index + 1] += value;
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange1(l, r, value, start, mid, 2*index );
	updateRange1(l, r, value, mid+1, end, 2*index + 1);
	seg1[index] = combine1(seg1[2*index] , seg1[2*index + 1]) ;
	return;
}
int query1(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate1(start, end, index);
	if( start > r || end < l || start > end)
		return inf1;
	if(start >= l && end <= r)
		return seg1[index];
	int mid = (start + end)/2, query_left, query_right;
	query_left = query1(l, r, start, mid, 2*index );
	query_right = query1(l, r, mid+1, end, 2*index + 1);
	return combine1(query_left , query_right);
}
char a[L];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	inf = INT_MAX;
	inf1 = INT_MIN;
	cin >> s;
	FOR(i,0,n+1)a[i] = 'a';
	int m = 0;
	FOR(i,0,n)
	{
		if(s[i] == 'L')size_of_base--;
		else if(s[i] == 'R')size_of_base++;
		m = max(m, size_of_base);
	}
	size_of_base = m+1;
	int idx = 1, tmp, tmp1, mx = 0;
	FOR(i,0,n)
	{
		if(s[i] == 'R')idx++;
		else if(s[i] == 'L')idx--;
		else if(s[i] == '(')
		{
			idx = max(idx, 1);
			if(a[idx] != '(')
			{
				if(a[idx] == ')')
				{
					updateRange(idx, size_of_base, 2);
					updateRange1(idx, size_of_base, 2);
				}
				else
				{
					updateRange(idx, size_of_base, 1);
					updateRange1(idx, size_of_base, 1);
				}
				a[idx] = '(';
			}
		}
		else if(s[i] == ')')
		{
			idx = max(idx, 1);
			if(a[idx] != ')')
			{
				if(a[idx] == '(')
				{
					updateRange(idx, size_of_base, -2);
					updateRange1(idx, size_of_base, -2);
				}
				else
				{
					updateRange(idx, size_of_base, -1);
					updateRange1(idx, size_of_base, -1);
				}
				a[idx] = ')';
			}
		}
		else
		{
			idx = max(idx, 1);
			tmp = query(idx, idx);
			if(a[idx] == '(')
			{
				updateRange(idx, size_of_base, -1);
				updateRange1(idx, size_of_base, -1);
			}
			else if(a[idx] == ')')
			{
				updateRange(idx, size_of_base, 1);
				updateRange1(idx, size_of_base, 1);
			}
			a[idx] = s[i];
		}
		idx = max(idx, 1);
		mx = max(mx, idx);
		tmp = query(1,mx);
		tmp1 = query(mx,mx);
		if(tmp < 0 || tmp1 != 0)cout<<"-1 ";
		else 
		{
			tmp = query1(1, mx);
			cout<<tmp<<" ";
		}
	}
	return 0;
}