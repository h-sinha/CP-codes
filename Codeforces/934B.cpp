#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define L 1e5
#define pb push_back
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int modu=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	ld temp=0;
	cin>>k;
	if(k==0){cout<<"1";return 0;}
	if(k==1){cout<<"4";return 0;}
	while(k>1)
	{
		temp=temp*10+8;
		if(temp>1e18){cout<<"-1";return 0;}
		k-=2;
	}
	while(k>0){temp*=10;if(temp>1e18){cout<<"-1";return 0;}k--;}
	if(temp>1e18)cout<<"-1";
	else printf("%.0Lf\n",temp );
	return 0;
}