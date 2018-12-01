#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	std::vector<int> dp(n+1);
	dp[1]=1;dp[2]=2;
	for(int i=3;i<=n;i++)
		dp[i]=dp[i-2]+i;
	cout<<dp[n];
	return 0;
}