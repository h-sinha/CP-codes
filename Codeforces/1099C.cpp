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
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	int k, co = 0, snow = 0, candy = 0;
	 	cin >> s;
	 	int len = s.length();
	 	cin >> k;
	 	FOR(i,0,len)
	 	{
	 		if(s[i] == '*')snow++;
	 		else if(s[i] == '?')candy++;
	 		else 
			{
				if(s[i+1] == '*' || s[i+1] == '?')continue;
	 			co++;
			}
	 	}
	 	// debug(co,k, snow);
	 	if(co == k)
	 	{
	 		FOR(i,0,len)
	 		{
	 			if(s[i] == '?'||s[i] == '*')continue;
	 			if(i!=len-1 &&(s[i+1] == '*'||s[i+1] == '?' ))continue;
	 			cout<<s[i];
	 		}
	 		return 0;
	 	}
	 	else if(co<k)
	 	{
	 		if(snow == 0 && candy + co < k)
	 		{
	 			cout<<"Impossible";
	 			return 0;
	 		}
	 		if(snow)
	 		{
	 			// cout<<"sda";
	 			FOR(i,0,len)
	 			{
	 				// debug(i,s[i], s[i+1]);
	 				if(s[i] == '*'||s[i]=='?')continue;
	 				if(i!= len-1 &&s[i+1] == '?')continue;
	 				if(i!= len-1 &&s[i+1] == '*' && co==k)continue;
	 				if(i!= len-1 &&s[i+1] == '*' && co!=k)
	 				{
	 					// cout<<"sda";
	 					FOR(j,0,k-co)cout<<s[i];
	 					co = k;
	 					continue;
	 				}
	 				cout<<s[i];
	 			}
	 		}
	 		else
	 		{
	 			FOR(i,0,len)
	 			{
	 				if(s[i] == '*'||s[i]=='?')continue;
	 				if(i!= len-1 &&s[i+1] == '?' && co==k)continue;
	 				if(i!= len-1 &&s[i+1] == '?' && co!=k)
	 				{
	 					co++;
	 					cout<<s[i];
	 					continue;
	 				}
	 				cout<<s[i];
	 			}
	 		}
	 	}
	 	else if(co > k)
	 	{
	 		cout<<"Impossible";
	 	}
		return 0;
}