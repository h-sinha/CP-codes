#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
ll a[L], p[L], po[L], ans[L];
struct node
{
	int freq;
	node *children[2];
};
node* new_node()
{
	node * tmp = new node();
	tmp->freq = 1;
	tmp->children[0] = NULL;
	tmp->children[1] = NULL;
	return tmp;
}
void insert(node* root, ll num)
{
	RFOR(i,30,0)
	{
		if(num & po[i])
		{
			if(root->children[1] == NULL)
				root->children[1] = new_node();
			else
				root->children[1]->freq++;
			root = root->children[1];
		}
		else
		{
			if(root->children[0] == NULL)
				root->children[0] = new_node();
			else
				root->children[0]->freq++;
			root = root->children[0];	
		}
	}
}
ll query(node *root, ll num)
{
	ll ret = 0;
	RFOR(i,30,0)
	{
		if(num & po[i])
		{
			if(root->children[1] != NULL && root->children[1]->freq > 0)
			{
				ret += po[i];
				root = root->children[1];
				root->freq--;
			}
			else
			{
				root = root->children[0];
				root->freq--;
			}
		}
		else
		{
			if(root->children[0] != NULL && root->children[0]->freq > 0)
			{
				root = root->children[0];
				root->freq--;
			}
			else
			{
				ret += po[i];
				root = root->children[1];
				root->freq--;
			}
		}
	}
	return ret^num;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node* root = new_node();
	int n;
	cin >> n;
	po[0] = 1;
	FOR(i,1,31)
		po[i] = (po[i-1] * 2LL);
	FOR(i,0,n)cin >> a[i];
	FOR(i,0,n)
	{
		cin >> p[i];
		insert(root, p[i]);
	}
	FOR(i,0,n)
		ans[i] = query(root, a[i]);
	FOR(i,0,n)cout << ans[i] <<" ";
	return 0;
}