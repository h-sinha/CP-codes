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
int mark[27],counter[1502];
ll m=1e9+7,pre[2002];
std::map<pii,ll> done;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		string s,val;
		cin>>s;
		int len=s.length(),k;
		cin>>val;
		cin>>k;
		FOR(i,0,26)
			if(val[i]=='0')mark[i]++;
		FOR(i,0,len)
			if(mark[s[i]-'a'])counter[i]++;
		FOR(i,1,len)counter[i]+=counter[i-1];
		ll cur=0,sofar,bck=0;
		pre[0]=1;
		FOR(i,1,1502)
			pre[i] = (pre[i-1]%m * 53 )%m;
		FOR(i,0,len)
		{
			cur=0;
			bck=0;
			FOR(j,i,len)
			{
				cur = (cur%m + (s[j]-'a'+1) * pre[j-i]%m)%m;
				bck = ( (bck%m *97)%m + (s[j]-'a'+1) )%m;
				if(i>0)
					sofar=counter[j]-counter[i-1]; 
				else
					sofar=counter[j];
				if(sofar>k)break;
				// cout<<cur<<" "<<bck<<" "<<s.substr(i,j-i+1)<<" "<<sofar<<ln;
				done[mp(min(cur,bck),max(cur,bck))]++;
			}
		}
		cout<<sz(done);
		return 0;
}0;
}