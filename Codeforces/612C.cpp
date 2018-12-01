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
std::map<char, int> hashing;
int counter[6];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int f=0,ans=0,tmp;
	 	string s;
	 	cin >> s;
	 	hashing['('] = 1;
	 	hashing[')'] = -1;
	 	hashing['{'] = 2;
	 	hashing['}'] = -2;
	 	hashing['['] = 3;
	 	hashing[']'] = -3;
	 	hashing['<'] = 4;
	 	hashing['>'] = -4;
	 	int len = s.length();
	 	FOR(i,0,len)
	 	{
	 		tmp = hashing[s[i]];
	 		// cout<<tmp<<ln;
	 		if(tmp < 0)
	 		{
	 			counter[-tmp]--;
	 			if(counter[-tmp]<0)
	 			{
	 				f=0;
	 				// cout<<i<<ln;
	 				// cout<<i <<" "<<tmp<<ln;
	 				FOR(j,1,5)
	 				{
	 					if(j==-tmp)continue;
	 					if(counter[j]>=1)
	 					{
	 						counter[j]--;
	 						f=1;break;
	 					}
	 				}
	 				if(!f)
	 				{
	 					cout<<"Impossible";return 0;
	 				}
	 				ans++;
	 				counter[-tmp]++;
	 			}
	 		}
	 		else counter[tmp]++;
	 		cout<<i<<" -> ";
	 		FOR(j,1,5)cout<<counter[j]<<" ";
	 		cout<<ln;
	 	}
	 	FOR(i,1,5)
	 	{
	 		debug2(i,counter[i]);
	 		if(counter[i] != 0)
	 		{
	 			cout<<"Impossible";return 0;
	 		}
	 	}
	 	cout<<ans;
		return 0;
}