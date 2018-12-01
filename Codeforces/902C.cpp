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
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
int a[200002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int mx=-1,h;
		cin>>h;
		FOR(i,0,h+1)cin>>a[i];
		FOR(i,2,h+1)if(a[i]!=1 && a[i-1]!=1)mx=INT_MAX;
		if(mx!=INT_MAX)
		{
			cout<<"perfect";
			return 0;
		}
		cout<<"ambiguous"<<ln;
		int cur=0,tmp;
		FOR(i,0,h+1)
		{
			tmp=a[i];
			while(tmp--)cout<<cur<<" ";
			cur+=(a[i]);
		}
		cout<<ln;
		tmp=a[0],cur=0;
		while(tmp--)cout<<cur<<" ";
		cur+=(a[0]);
		FOR(i,1,h+1)
		{
			tmp=a[i];
			while(tmp>1)
			{cout<<cur<<" ";tmp--;}
			if(a[i-1]>1)cout<<cur-1<<" ";
			else cout<<cur<<" ";
			cur+=(a[i]);
		}
		return 0;
}