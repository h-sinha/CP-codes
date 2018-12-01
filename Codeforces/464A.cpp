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
map<ll,ll> counter;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,p,cur,next,prev,pprev,f=0,pos;
	 	cin>>n>>p;
	 	string s;
	 	cin>>s;
	 	RFOR(i,n-1,2)
	 	{
	 		cur=s[i]-'a',prev=s[i-1]-'a',pprev=s[i-2]-'a';
	 		f=0;
	 		// cout<<i<<" "<<cur<<" "<<prev<<" "<<pprev<<" "<<next<<ln;
	 		FOR(j,cur+1,p)
	 		{
	 			// cout<<cur<<" "<<prev<<" "<<pprev<<" "<<j<<ln;
	 			if(j==prev || pprev==j)continue;
	 			s[i]=char(j+97);
	 			pos=i;
	 			f=1;
	 			break;
	 		}
	 		if(f)break;
	 	}
	 	if(!f)
	 	{
	 		if(n>1)
	 		cur=s[1]-'a',prev=s[0]-'a';
	 		else cur=INT_MAX-2;
	 		// cout<<cur<<ln;
	 		FOR(j,cur+1,p)
	 		{
	 			f=0;
	 			// cout<<cur<<" "<<prev<<" "<<j<<ln;
	 			if(j==prev)continue;
	 			s[1]=char(j+97);
	 			pos=1;
	 			f=1;
	 			break;
	 		}
	 		if(!f)
	 		{
	 			cur=s[0]-'a';
	 			// cout<<cur<<ln;
	 			FOR(j,cur+1,p)
	 			{
	 				f=0;
	 				// cout<<cur<<" "<<prev<<" "<<j<<ln;
	 				// if(j==prev)continue;
	 				s[0]=char(j+97);
	 				pos=0;
	 				f=1;
	 				break;
	 			}	
	 		}
	 	}
	 	FOR(i,pos+1,n)
	 	{
	 		cur=s[i]-'a',prev=s[i-1]-'a',pprev=s[i-2]-'a';
	 		FOR(j,0,26)
	 		{
	 			cur=s[i]-'a',prev=s[i-1]-'a',pprev=s[i-2]-'a';
		 		if(prev==j || pprev==j)continue;
	 			s[i]=char(j+97);
	 			break;
	 		}
	 	}
	 	if(f)cout<<s;
	 	else cout<<"NO";
		return 0;
}