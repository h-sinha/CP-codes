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
ll h11[L], h12[L], h21[L], h22[L], m = 1e9+7;
ll po1[L], po2[L], inv1[L], inv2[L];
string s1, s2;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp%m;
}
void pre()
{
	po1[0] = po2[0] = 1;
	inv1[0] = inv2[0] = 1;
	ll i1 = fastexpo(37,m-2,m), i2 = fastexpo(53, m-2,m);
	FOR(i,1,200001)
	{
		po1[i] = (po1[i-1] * 37LL)%m;
		po2[i] = (po2[i-1] * 53LL)%m;
		inv1[i] = (inv1[i-1] * i1)%m;
		inv2[i] = (inv2[i-1] * i2)%m;
	}
}
bool check(int l1, int r1, int l2, int r2)
{
	if(l1 == r1)
	{
		if(s1[l1] == s2[l2])return 1;
		return 0;
	}
	ll val11 = h11[r1], val12 = h12[r1], val21 = h21[r2], val22 = h22[r2];
	if(l1 != 0)val11 = (val11 - h11[l1 - 1] + m)%m;
	val11 = (val11 * inv1[l1])%m;

	if(l1 != 0)val12 = (val12 - h12[l1 - 1] + m)%m;
	val12 = (val12 * inv2[l1])%m;
	
	if(l2 != 0)val21 = (val21 - h21[l2 - 1] + m)%m;
	val21 = (val21 * inv1[l2])%m;
	
	if(l2 != 0)val22 = (val22 - h22[l2 - 1] + m)%m;
	val22 = (val22 * inv2[l2])%m;
	
	if(val11 == val21 && val12 == val22)return 1;
	if((r1-l1+1) & 1)return 0;
	
	int mid1 = (l1 + r1)/2, mid2 = (l2 + r2)/2;
	if(check(l1, mid1, mid2 + 1, r2) && check(mid1 + 1, r1, l2, mid2))return 1;
	if(check(l1, mid1, l2, mid2) && check(mid1 + 1, r1, mid2 + 1, r2))return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s1 >> s2;
	if(s1 == s2)
	{
		cout<<"YES\n";
		return 0;
	}
	int n = s1.length();
	if(n&1)
	{
		cout<<"NO\n";
		return 0;
	}
	pre();
	h11[0] = ((s1[0]-'a'+1) * po1[0])%m;
	h12[0] = ((s1[0]-'a'+1) * po2[0])%m;
	h21[0] = ((s2[0]-'a'+1) * po1[0])%m;
	h22[0] = ((s2[0]-'a'+1) * po2[0])%m;
	FOR(i,1,n)
	{
		h11[i] = (((s1[i]-'a'+1) * po1[i])%m + h11[i-1])%m;
		h12[i] = (((s1[i]-'a'+1) * po2[i])%m + h12[i-1])%m;
		h21[i] = (((s2[i]-'a'+1) * po1[i])%m + h21[i-1])%m;
		h22[i] = (((s2[i]-'a'+1) * po2[i])%m + h22[i-1])%m;
	}
	if(check(0, n/2 - 1, n/2, n-1) && check(n/2, n-1, 0, n/2 - 1))cout<<"YES\n";
	else if(check(0, n/2 - 1, 0, n/2 - 1) && check(n/2, n-1, n/2, n-1))cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}