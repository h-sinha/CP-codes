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
map<ll,ll> counter;
int pos[L], n[L];
set<int>SET[50];
int main()
{

		// 4 , 8, 15, 16, 23, 42
		int a[] ={4 , 8, 15, 16, 23, 42};
		FOR(i,0,6)
		{
			FOR(j,0,6)
			{
				if(i == j)continue;
				SET[a[i]].insert(a[i]*a[j]);
			}
		}
		cout<<"? 1 2"<<endl;
		fflush(stdout);
		cin >> n[2];
		FOR(i,0,6)
		{
			if(SET[a[i]].find(n[2]) != SET[a[i]].end())
			{
				pos[a[i]]++;
			}
		}
		cout<<"? 1 3"<<endl;
		fflush(stdout);
		cin >> n[3];
		FOR(i,0,6)
		{
			if(SET[a[i]].find(n[3]) != SET[a[i]].end())
			{
				pos[a[i]]++;
			}
		}
		cout<<"? 1 4"<<endl;
		fflush(stdout);
		cin >> n[4];
		FOR(i,0,6)
		{
			if(SET[a[i]].find(n[4]) != SET[a[i]].end())
			{
				pos[a[i]]++;
			}
		}
		cout<<"? 1 5"<<endl;
		fflush(stdout);
		cin >> n[5];
		FOR(i,0,6)
		{
			if(SET[a[i]].find(n[5]) != SET[a[i]].end())
			{
				pos[a[i]]++;
			}
		}
		int mx = INT_MIN;
		FOR(i,0,6)
		{
			if(pos[a[i]] > mx)
			{
				n[1] = a[i];
				mx = pos[a[i]];
			}
		}
		cout<<"! "<<n[1]<<" "<<n[2]/n[1]<<" "<<n[3]/n[1]<<" "<<n[4]/n[1]<<" "<<n[5]/n[1]<<" ";
		counter[n[1]]++;
		counter[n[2]/n[1]]++;
		counter[n[3]/n[1]]++;
		counter[n[4]/n[1]]++;
		counter[n[5]/n[1]]++;
		FOR(i,0,6)
		{
			// debug(counter[a[i]], a[i]);
			if(counter.find(a[i]) == counter.end())
			{
				cout<<a[i]<<endl;
				break;
			}
		}
		return 0;
}