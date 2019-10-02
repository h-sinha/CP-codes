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
int a[L], po[L], done[L], val[L];
void pre()
{
	po[0]= 1;
	FOR(i,1,22)po[i] = (po[i-1]*2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	freopen("looking.in", "r", stdin);
	cin >> t;
	pre();
	int n, al;
	while(t--)
	{

		cin >> n >> al;
		int ans = 0;
		FOR(i,0,n)
		{
			cin >> a[i];
			done[i] = 0;
		}
		RFOR(i,20,0)
		{
			if(al==0)break;
			FOR(j,0,n)
			{
				val[j] = 0;
				if((po[i]&a[j]) == 0 || done[j])continue;
				FOR(k,0,20)
				{
					if(((po[k]&a[j]) == po[k]) && ((ans&po[k])==0))
					{
						val[j] += po[k];
					}
				}
				
			}
			int idx = -1, mx = 0; 
			FOR(j,0,n)
			{
				if(val[j] > mx)
				{
					mx = val[j];
					idx = j;
				}
			}
			if(idx != -1)
			{
				al--;
				ans |= a[idx];
				done[idx] = 1;
			}
		}
		cout<<ans<<ln;
	}
	return 0;
}