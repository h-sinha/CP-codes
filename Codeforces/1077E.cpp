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
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
ll size_of_base, baseArray[L], seg[4*L];
std::map<ll, int> counter;
std::map<ll, bool> done;
multiset<int>SET;
void build(int start = 1, int end = size_of_base, int index = 1)
{
	if( start == end )
	{
		seg[index] = baseArray[start];
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*index);
	build(mid+1, end, 2*index + 1);
	seg[index] = min( seg[ 2*index ] , seg[ 2*index + 1] );
	return;
}
ll query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	if( start > r || end < l )return INT_MAX;
	if(start >= l && end <= r)
	{
		return seg[index];
	}
	int mid = (start + end)/2;
	ll query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return min(query_left, query_right);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n, mx=INT_MIN, aux, tmp;
	 	cin >> n;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i];
	 		counter[a[i]]++;
	 		mx = max(mx, counter[a[i]]);
	 	}
	 	FOR(i,0,n)
	 	{
	 		if(!done[a[i]])SET.insert(-counter[a[i]]), done[a[i]]=1;
	 	}
	 	// cout<<tmp<<endl;
	 	tmp = -(*SET.begin());
	 	SET.erase(SET.begin());
	 	int ans = tmp, cur=0;
	 	RFOR(i,tmp, 1)
	 	{
	 		cur = 0;
	 		if(i&1)continue;
	 		aux = i/2;
	 		cur =i;
	 		multiset<int>S1;
	 		// debug(aux, ans);
	 		while(aux>0 && !SET.empty())
	 		{
	 			// debug(cur, aux,*SET.begin());
	 			if(-(*SET.begin()) < aux)break;
	 			cur += (aux);
	 			S1.insert(*SET.begin());
	 			SET.erase(SET.begin());
	 			if(aux&1)break;
	 			aux/=2;
	 			// debug(sz(SET));
	 		}
	 		trace(S1,x)SET.insert(x);
	 		ans = max(ans, cur);
	 	}
	 	cout<<ans;
		return 0;
}