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
string s[L];
int ni[L];
struct node
{
	node *child[26];
	int freq;
};
node *new_node()
{
	node *temp=new node();
	FOR(i,0,26)temp->child[i]=NULL;
	temp->freq=1;
	return temp;
}
void insert(node *root,int x)
{	
	FOR(i,0,ni[x])
	{
		int temp=s[x][i]-'A';
		if(root->child[temp]==NULL)
		{
			root->child[temp]=new_node();
			root=root->child[temp];
		}
		else
		{
			root=root->child[temp];
			root->freq++;
		}
	}
	return;
}
ll ans, xx, n, k;
ll solve(node *root, int dpt = 0)
{
	if(root == NULL)return 0;
	int cc = 0;
	// debug(root->freq);
	FOR(i,0,26)
		cc += solve(root->child[i],dpt+1);
	// debug(root->freq,"bef");
	root->freq -= cc;
	// debug(root->freq,cc, k, dpt);
	int cur = root->freq/k;
	ans += cur*dpt;
	cc += cur*k;
	return cc;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t;
	 	cin >> t;
	 	while(t--)
	 	{
	 		xx++;
	 		ans = 0;
	 		node *root = new node();
	 		cin >> n >> k;
	 		FOR(i,0,n)
	 		{
	 			cin >> s[i];
	 			ni[i] = s[i].length();
	 			insert(root, i);
	 		}
	 		solve(root);
			cout<<"Case #"<<xx<<": "<<ans<<ln;
	 	}
		return 0;
}