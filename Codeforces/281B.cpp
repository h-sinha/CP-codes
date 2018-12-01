#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
typedef long long ll;
typedef long double ld;
std::map<int, int> counter;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ld x,y,n,ansx,ansy,m=INT_MAX;
	cin>>x>>y>>n;
	ld num;
	FOR(i,1,n+1)
	{
		num=ll((x*i)/y);
		if(abs(x/y-num/i)<m)
		{
			m=abs(x/y-num/i);
			ansx=num;
			ansy=i;
		}
		num=ceil((x*i)/y);
		if(abs(x/y-num/i)<m)
		{
			m=abs(x/y-(num/i));
			ansx=num;
			ansy=i;
		}
	}
	cout<<ansx<<"/"<<ansy;
	return 0;
}