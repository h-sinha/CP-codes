#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define	revpr priority_queue<pii,std::vector<pii>,greater<pii> >;
typedef long long ll;
typedef long double ld;
int counter[11];
int pr(int num,int rem)
{
	while(counter[num]>1)
	{
		rem=((rem*10)+num)%7;
		cout<<num;
		counter[num]--;
	}
	return rem;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	cin>>s;
	 	int rem=0,len=s.length();
	 	FOR(i,0,len)counter[s[i]-'0']++;
		RFOR(i,7,1)
		{
			if(i==1||i==6)continue;
			while(counter[i]--)
			{
				rem=((rem*10)+i)%7;
				cout<<i;
			}
		}
		rem=pr(9,rem);
		rem=pr(8,rem);
		rem=pr(6,rem);
		rem=pr(1,rem);
		int ans[10];
		ans[0]=1869,ans[1]=6198,ans[2]=1896,ans[3]=1689,ans[4]=1986,ans[5]=1968,ans[6]=1698;
		cout<<ans[rem];
		while(counter[0]--)cout<<"0";
		return 0;
}

