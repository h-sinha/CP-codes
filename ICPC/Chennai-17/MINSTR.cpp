#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
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
std::map<string, int> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, n, tmp;
	 	string s;
	 	cin >> t;
	 	while(t--)
	 	{
	 		cin >> n;
	 		counter.clear();
	 		FOR(i,0,n)
	 		{
	 			cin >> s;
	 			counter[s]++;
	 		}
	 		int ans = 0, tmp ;
	 		tmp = min(counter["ab"], counter["ba"]);
	 		ans += (counter["ab"] + counter["ba"])*2;
	 		ans -= 2*tmp;
	 		if(counter["ab"] == counter["ba"] && tmp)ans++;
	 		if(counter["ab"] == 0 && counter["ba"] == 0)
	 		{
	 			if(counter["a"] || counter["aa"])ans++;
	 			if(counter["b"] || counter["bb"])ans++;
	 		}
	 		cout<<ans<<ln;
	 	}
		return 0;
}