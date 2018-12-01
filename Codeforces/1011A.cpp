#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
std::map<char, int> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,k;
	 	string s;
	 	cin>>n>>k;
	 	cin>>s;
	 	int tmp=k;
	 	FOR(i,0,n)
	 	{
	 		counter[s[i]-'a']++;
	 	}
	 	int ans=0;
	 	FOR(i,0,26)
	 	{
	 		if(counter.find(i)!=counter.end())
	 		{
	 			ans+=(i+1);
	 			i++;
	 			// cout<<"i"<<i<<ln;
	 			k--;
	 		}
	 		if(k==0)break;
	 	}
	 	if(k)cout<<"-1";
	 	else cout<<ans<<ln;
	 	// int ans1=0;
	 	// FOR(i,1,26)
	 	// {
	 	// 	if(counter.find(i)!=counter.end())
	 	// 	{
	 	// 		ans1+=i;
	 	// 		i++;
	 	// 		tmp--;
	 	// 	}
	 	// 	if(tmp==0)break;
	 	// }
	 	// if(k>0 && tmp>0)cout<<"-1";
	 	// else
	 	// {
	 	// 	if(tmp==0 && k==0)
	 	// 	cout<<max(ans,ans1);
	 	// 	else if(tmp==0)cout<<ans1;
	 	// 	else cout<<ans;
	 	// }
		return 0;
}