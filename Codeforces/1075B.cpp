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
const int L=3e5+7;
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
ll x[L],t[L];
std::vector<ll> taxi,person;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m;
	 	cin >> n >> m;
	 	FOR(i,0,n+m)
	 	{
	 		cin >> x[i];
	 	}
	 	FOR(i,0,n+m)
	 	{
	 		cin >> t[i];
	 		if(t[i] == 1)
	 		{
	 			taxi.pb(x[i]);
	 		}
	 		else
	 			person.pb(x[i]);
	 	}
	 	ll curmin1,curmin3,curmin2,tmp1,tmp2,tmp3;
	 	sort(all(taxi));
	 	std::vector<ll>::iterator it;
	 	trace(person,xx)
	 	{
	 		curmin1 = curmin2 = curmin3 = tmp1 = tmp2= tmp3= LLONG_MAX;
	 		it = upper_bound(all(taxi),xx);
	 		// debug(xx,*it);
	 		if(it!=taxi.end()){curmin1=abs(xx-*it);tmp1=*it;}
	 		if(it!=taxi.begin())it--;
	 		if(it!=taxi.end()){curmin2=abs(xx-*it);tmp2=*it;}
	 		if(it!=taxi.begin())it--;
	 		if(it!=taxi.end()){curmin3=abs(xx-*it);tmp3=*it;}
	 		if(curmin1 < curmin2 && curmin1 < curmin3)counter[tmp1]++;
	 		else if(curmin2 < curmin1 && curmin2 < curmin3)counter[tmp2]++;
	 		else if(curmin3 < curmin2 && curmin3 < curmin1)counter[tmp3]++;
	 		else if(curmin1 == curmin2 && curmin1 < curmin3)
	 		{
	 			if(tmp1 < tmp2)counter[tmp1]++;
	 			else counter[tmp2]++;

	 		}
	 		else if(curmin2 == curmin3 && curmin2 < curmin1)
	 		{
	 			if(tmp2 < tmp3)counter[tmp2]++;
	 			else counter[tmp3]++;
	 		}
	 		else if(curmin1 == curmin3 && curmin1 < curmin2)
	 		{
	 			if(tmp1 < tmp3)counter[tmp1]++;
	 			else counter[tmp3]++;
	 		}
	 		else if(curmin2 == curmin3 && curmin2 == curmin3)
	 		{
	 			tmp1 = min(tmp1,tmp2);
	 			tmp1 = min(tmp1,tmp3);
	 			counter[tmp1]++;
	 		}


	 	}
	 	trace(taxi,xx)cout<<counter[xx]<<" ";
		return 0;
}