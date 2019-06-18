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
const int L=1e5+7;
int a[L],out[L],mark[L],counter[L];
std::map<int, int> hashing;
int sofarmx,ans=0, f= 0;
struct node
{
	int l,r,q;
};
bool comp(node x, node y)
{
	if(x.l/900==y.l/900)return x.r<y.r;
	return x.l<y.l;
}
void add(int idx) 
{
	if(mx[i] == 0)f = 1;
	else 
	{
		
	}
	counter[mark[idx]]++;
	if(counter[mark[idx]]==a[idx])ans++;
	else if(counter[mark[idx]]==a[idx]+1)ans--;
}

void remove(int idx) 
{
	counter[mark[idx]]--;
	if(counter[mark[idx]]==a[idx]-1)ans--;
	else if(counter[mark[idx]]==a[idx])ans++;
}
int mx[L], a[L], b[L];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int curl,curr,n,m,l,r,k,cur=-1;
	 	cin>>n>>m;
	 	FOR(i,0,n)
	 	{
	 		cin >> a[i] >> b[i];
	 		mx[a[i]] = max(mx[a[i]], b[i]);
	 	}
	 	FOR(i,1,500001)
	 	{
	 		if(mx[i-1] < i)continue;
	 		mx[i] = max(mx[i], mx[i-1]);
	 	}
	 	std::vector<node> v(m);
	 	node temp;
	 	FOR(i,0,m)
		{
			cin>>l>>r;
			v[i].l=l,v[i].r=r,v[i].q=i;
		}
		sort(all(v),comp);
		l=0,r=-1;
		FOR(i,0,m)
		{
			curl=v[i].l,curr=v[i].r;
			while(r<curr)
			{
				++r;
				add(r);
			}
			while(r>curr)
			{
				remove(r);
				--r;
			}
			while(l<curl)
			{
				remove(l);
				l++;
			}
			while(l>curl)
			{
				--l;
				add(l);
			}
			out[v[i].q]=ans;
		}
		FOR(i,0,m)cout<<out[i]<<ln;
		return 0;
}