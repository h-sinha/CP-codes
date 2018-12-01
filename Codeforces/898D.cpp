#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main()
{
	ll n,m,k,ans=0,counter=0,j=1;
	cin>>n>>m>>k;
	std::vector<int> v(n+1);
	std::vector<int> arr(1000006);
	for (int i = 1; i <=n; i++)
	{
		cin>>v[i];
		arr[v[i]]=1;
	}
	for(int i=0;i<1000001;i++)
	{
		while(j-i<m && j<1000001)
		{

			if(arr[j]==1)
				counter++;
			if(counter==k)
			{
				arr[j]=0;
				counter--;
				ans++;
			}
			j++;
		}
		if(arr[i]==1)
			counter--;
	}
	cout<<ans<<endl;
	return 0;
}