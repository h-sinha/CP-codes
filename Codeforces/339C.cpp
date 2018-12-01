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
std::vector<int> aux;
std::vector<int> ans;
int f=0,m;
bool solve(int one,int two,int cur,int prev)
{
	if(cur>=m || f)return 0;
	// cout<<one<<" "<<two<<" "<<prev<<ln;
	bool tmp;
	if(cur&1)
	{
		trace(aux,x)
		{
			if(one<two+x && x!=prev)
			{
				if(cur==m-1){ans.pb(x);f=1;return 1;}
				tmp=solve(one,two+x,cur+1,x);
				if(tmp){ans.pb(x);return 1;}
			}
		}
	}
	else
	{
		trace(aux,x)
		{
			if(one+x>two && x!=prev)
			{
				if(cur==m-1){ans.pb(x);f=1;return 1;}
				tmp=solve(one+x,two,cur+1,x);
				if(tmp){ans.pb(x);return 1;}
			}
		}
	}
	return 0;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s;
	 	bool tmp;
	 	cin>>s;
	 	cin>>m;
	 	FOR(i,0,10)
	 		if(s[i]=='1')aux.pb(i+1);
	 	if(m==1)
	 	{
	 		trace(aux,x)
	 		{
	 			cout<<"YES\n";
	 			cout<<x;
	 			return 0;
	 		}
	 		cout<<"NO";
	 		return 0;
	 	}
		trace(aux,x)
		{
			tmp=solve(x,0,1,x);
			if(tmp){ans.pb(x);break;}
		}
		if(!sz(ans)){cout<<"NO";return 0;}
		cout<<"YES\n";
		RFOR(i,sz(ans)-1,0)cout<<ans[i]<<" ";
		return 0;
}