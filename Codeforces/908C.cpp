#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n;
	double r,posmx;
	cin>>n>>r;
	std::vector<double> x(n+1);
	std::vector<double> ans(n+1);
	for (int i = 0; i < n; i++)
	{
		cin>>x[i];
		ans[i]=r;
		for (int j = 0; j < i; j++)
			ans[i]=max(ans[i],ans[j]+sqrt((4*r*r)-(abs(x[j]-x[i])*abs(x[j]-x[i]))));
	}
	for (int i = 0; i < n; i++)
		printf("%.10lf ",ans[i]);
	return 0;
}