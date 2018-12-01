#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int main()
{
	ll n;
	cin>>n;
	if(n%10==0)
	{
		cout<<n<<endl;
		return 0;
	}
	if(n%10<=5)
	{
		n/=10;
		n*=10;
		cout<<n<<endl;
		return 0;
	}
	n/=10;
	int temp=n%10;
	n/=10;
	n=n*10+temp+1;
	n*=10;
	cout<<n<<endl;
	return 0;
	return 0;
}