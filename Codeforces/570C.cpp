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
set<int>SET,REVSET;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,m,sofar=0,idx,numseg=0,dot=0;
	 	char ch;
	 	string s;
	 	cin>>n>>m;
	 	cin>>s;
	 	FOR(i,0,n)
	 	{
	 		if(s[i]!='.' && sofar!=0){numseg++;sofar=0;}
	 		else if(s[i]=='.'){dot++;sofar++;}
	 	}
	 	if(sofar!=0)numseg++;
	 	// cout<<dot<<" & "<<numseg<<ln;
	 	while(m--)
	 	{
	 		cin>>idx>>ch;
	 		if(ch!='.')
	 		{
	 			if(s[idx-1]=='.')
	 			{
	 				dot--;
	 				s[idx-1]=ch;
	 				if(s[idx]=='.' && idx>1 && s[idx-2]=='.')
	 				{
	 					numseg++;
	 				}
	 				else if((s[idx]!='.' && idx>1 && s[idx-2]!='.')  ||(s[idx]!='.' && idx==1 ) )
	 				{
	 					numseg--;
	 				}
	 			}
	 		}
	 		else
		 		{
	 			if(s[idx-1]!='.')
	 			{
	 				dot++;
	 				s[idx-1]='.';
	 				if(s[idx]!='.' && idx>1 && s[idx-2]!='.' || s[idx]!='.' && idx==1)
	 				{
	 					numseg++;
	 				}
	 				else if((s[idx]=='.' && idx>1 && s[idx-2]=='.'))
	 				{
	 					numseg--;
	 				}
	 			}	
	 		}
	 		cout<<max(0,dot-numseg)<<ln;
	 		// cout<<dot<<" & "<<numseg<<ln;
	 	}
		return 0;
}