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
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
char ch[102][102];
std::map<char, int> counter;
// set<char>SET;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,m;
		cin>>n>>m;
		FOR(i,0,n)FOR(j,0,m)cin>>ch[i][j];
		char cur=ch[0][0];
		int f=0,length=0,lng,width=0,prev=-1;
		// SET.insert(cur);
		counter[cur]++;
		FOR(i,0,n)
		{
			f=0;
			if(cur!=ch[i][0])
			{
				lng=i-prev-1;
				if(lng!=length && prev!=-1){f=1;break;}
				prev=i-1;
				cur=ch[i][0];
				length=lng;
				// SET.insert(cur);
				counter[cur]++;
			}
			FOR(j,0,m)
			{
				if(ch[i][j]!=cur)
				{
					f=1;
					break;
				}
			}
			if(f)break;
		}

		lng=n-prev-1;
		if(counter['R']!=1 || counter['G']!=1 ||counter['B']!=1)f=1;
		// if(sz(SET)!=3)f=1;
		if(lng!=length && prev!=-1)f=1;
		if(!f){cout<<"YES\n";return 0;}
		prev=-1;
		// SET.clear();
		counter.clear();
		cur=ch[0][0];
				counter[cur]++;
		// SET.insert(cur);
		FOR(i,0,m)
		{
			f=0;
			if(cur!=ch[0][i])
			{
				lng=i-prev-1;
				if(lng!=length && prev!=-1){f=1;break;}
				prev=i-1;
				cur=ch[0][i];
				counter[cur]++;
					length=lng;
			// SET.insert(cur);

			}
			FOR(j,0,n)
			{
				if(ch[j][i]!=cur)
				{
					f=1;
					break;
				}
			}
			if(f)break;
		}
		lng=m-prev-1;
		// trace(counter,x)cout<<x.F<<" "<<x.S<<ln;
		if(counter['R']!=1 || counter['G']!=1 ||counter['B']!=1)f=1;
		// if(sz(SET)!=3)f=1;
		if(lng!=length && prev!=-1)f=1;
		if(!f)cout<<"YES\n";
		else cout<<"NO\n";
		return 0;
}