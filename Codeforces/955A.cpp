#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
int modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ld ans=0,h,d,c,n,hh,mm;
	cin>>hh>>mm;
	cin>>h>>d>>c>>n;
	if(hh<20)
	{
		ld time=(60-mm)+(19-hh)*60;
		// cout<<time<<endl;
			int co=0;
			ld temp=h+time*d;
			while(temp>0)
				{temp-=n;co++;}
		 ans=((co)*(0.8*c));
	}
	else
	{
		int co=0;
		while(h>0)
				{h-=n;co++;}
			cout<<co*0.8*c<<endl;
			return 0;
	}
	int co=0;
	while(h>0)
				{h-=n;co++;}
			// cout<<co*c<<endl;
	ans=min(ans,(co)*c);
	printf("%.10Lf",ans);
	return 0;
}